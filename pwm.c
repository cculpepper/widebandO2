/*
 * Pulse-Width-Modulation Code for K64
 * PWM signal can be connected to output pins PC3 and PC4
 * 
 * Author: Brent Dimmig <bnd8678@rit.edu>
 * Modified by: 
 * Created: 2/20/2014
 * Modified: 3/07/2015
 */  
#include "common.h"

#include "pwm.h"

/*From clock setup 0 in system_MK64f12.c*/ 
#define DEFAULT_SYSTEM_CLOCK 20485760u /* Default System clock value */
#define CLOCK					20485760u
#define PWM_FREQUENCY			1000
#define FTM0_MOD_VALUE			(CLOCK/PWM_FREQUENCY)
/* Use the SystemCoreClock variable. */ 
/* This module uses the system clock. */ 
#define FTM_MAX_MOD 



static volatile unsigned int PWMTick = 0;
static unsigned int chan2Mod = 0;
static unsigned int chan2Freq = 0;


/*
 * Change the Motor Duty Cycle and Frequency
 * @param DutyCycle (0 to 100)
 * @param Frequency (~1000 Hz to 20000 Hz)
 * @param dir: 1 for C3 active, else C2 active 
 */ 
void SetDutyCycle2(unsigned int DutyCycle, unsigned int Frequency,
		unsigned int dir) 
{

	// Calculate the new cutoff value
	uint16_t mod = (uint16_t) (((SystemCoreClock / Frequency) * DutyCycle) / 100);
	FTM0_C2V = mod;
	// Update the clock to the new frequency
	FTM0_MOD = (CLOCK / Frequency);

}



/*
 * Initialize the FlexTimer for PWM
 */ 
void InitPWM2(uint32_t frequency) 
{
	int i;
	int divider;
	int found;
	// 12.2.13 Enable the Clock to the FTM0 Module
	SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;
	// Enable clock on PORT A so it can output
	SIM_SCGC5 |=
		SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK;


	// 11.4.1 Route the output of TPM channel 0 to the pins
	// Use drive strength enable flag to high drive strength
	//These port/pins may need to be updated for the K64 <Yes, they do. Here are two that work.>
	PORTC_PCR3 = PORT_PCR_MUX(4) | PORT_PCR_DSE_MASK;	//Ch2
	/*PORTC_PCR4 = PORT_PCR_MUX(4) | PORT_PCR_DSE_MASK;	//Ch3*/

	// 39.3.10 Disable Write Protection
	FTM0_MODE |= FTM_MODE_WPDIS_MASK;


	// 39.3.4 FTM Counter Value
	// Initialize the CNT to 0 before writing to MOD
	FTM0_CNT = 0;


	// 39.3.8 Set the Counter Initial Value to 0
	FTM0_CNTIN = 0;
	
	found = 0;
	if ((SystemCoreClock / frequency) > ((1<<16)-1)){
		/* Then we must divide the thing to make the tihing work. */ 
		for (i=0;i<8;i++){
			divider = (1<<i);
			if (((SystemCoreClock / frequency)/divider) < ((1<<16)-1)){ 
				found = i;
				break;
			}
		}
		if (found == 0){
			return 1;
			/* Then we cant find a divider too low. Frequency too low. */ 
		}
	}

	chan2Freq = frequency;
	chan2Mod = ((SystemCoreClock / divider) / frequency);
	
	// 39.3.3 FTM Setup
	// Set prescale value to 1 
	// Chose system clock source
	// Timer Overflow Interrupt Enable
	FTM0_SC = FTM_SC_PS(found) | FTM_SC_CLKS(1) | FTM_SC_TOIE_MASK;

	// 39.3.5 Set the Modulo resister
	FTM0_MOD = chan2Mod;

	// 39.3.6 Set the Status and Control of both channels
	// Used to configure mode, edge and level selection
	// See Table 39-67,  Edge-aligned PWM, High-true pulses (clear out on match)
	// See Table 39-67,  Edge-aligned PWM, Low-true pulses (clear out on match)
	FTM0_C2SC |= FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;

	FTM0_C2SC &= ~FTM_CnSC_ELSA_MASK;
	// Enable Interrupt Vector for FTM
	//NVIC_EnableIRQ(FTM0_IRQn);

} 


/*OK to remove this ISR?*/ 
void FTM0_IRQHandler(void)
{				//For FTM timer

	FTM0_SC &= ~FTM_SC_TOF_MASK;


	//if motor tick less than 255 count up... 
	if (PWMTick < 0xff)

		PWMTick++;



}
