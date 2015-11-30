/*
* Rochester Institute of Technology
* Department of Computer Engineering
*  CMPE 460  Interfacing Digital Electronics
Spring 2015

*
*
* Filename: main.c
*/

#include "common.h"
#include "adc.h"

/* 60 Should be DP0 on ADC1. 
 * Going to use for Pump current
 * 63 Sholud be DP3 on ADC1. Also is DP0 on ADC0. 
 * Going to use for 
 * 4e should be se14 on ADC1.
 * 4f should be se15 on ADC1.
 * */ 
const uint8_t ADC1SourceBytes[ADC1_NUM_SOURCES] = {0x60, 0x63, 0x4E, 0x4F};
volatile int ADC1ResultIndex;
void DAC0_INIT(void) {
		//Enable DAC clock
		SIM_SCGC2 |= SIM_SCGC2_DAC0_MASK;
		DAC0_C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;
		DAC0_C1 = 0;
}

void PDB_INIT(void) {
	//Enable PDB Clock
	SIM_SCGC6 |= SIM_SCGC6_PDB_MASK;
	//PDB0_CNT = 0x0000;
	PDB0_MOD = 50000; // 50,000,000 / 50,000 = 1000

	PDB0_SC = PDB_SC_PDBEN_MASK | PDB_SC_CONT_MASK | PDB_SC_TRGSEL(0xf) | PDB_SC_LDOK_MASK;
	PDB0_CH1C1 = PDB_C1_EN(0x01) | PDB_C1_TOS(0x01);
}

void ADC1_INIT(void) {
	unsigned int calib;

	// Turn on ADC0
	SIM_SCGC3 |= SIM_SCGC3_ADC1_MASK;

	ADC1ResultIndex = 0;

	// Configure CFG Registers
	// Configure ADC to divide 50 MHz down to 6.25 MHz AD Clock, 16-bit single ended
	//(Insert your code here.)
	ADC1->CFG1 = ADC_CFG1_ADIV(3) | ADC_CFG1_MODE(11);


	// Do ADC Calibration for Singled Ended ADC. Do not touch.
	ADC1_SC3 = ADC_SC3_CAL_MASK;
	while ( (ADC1_SC3 & ADC_SC3_CAL_MASK) != 0 );
	calib = ADC1_CLP0;
	calib += ADC1_CLP1;
	calib += ADC1_CLP2;
	calib += ADC1_CLP3;
	calib += ADC1_CLP4;
	calib += ADC1_CLPS;
	calib = calib >> 1;
	calib |= 0x8000;
	ADC1_PG = calib;

	// Configure SC registers.
	// Select hardware trigger.
	ADC1->SC2 |= ADC_SC2_ADTRG_MASK;



	// Configure SC1A register.
	// Select ADC Channel and enable interrupts. Use ADC1 channel DAD3  in single ended mode.
	//(Insert your code here.)
	ADC1_SC1A = 0x43;//ADC_SC1_ADCH(3) | ADC_SC1_AIEN_MASK;


	// Enable NVIC interrupt
	NVIC_EnableIRQ(ADC1_IRQn);//ADC1 Interrupt
	__enable_irq();
}

// ADC1 Conversion Complete ISR
void ADC1_IRQHandler(void) {
	// Read the result (upper 12-bits). This also clears the Conversion complete flag.
	__disable_irq();
	if (ADC1ResultIndex > ADC1_NUM_SOURCES || ADC1ResultIndex < 0){
		ADC1ResultIndex = 0;
		ADC1_SC1A = ADC1SourceBytes[ADC1ResultIndex];
		return;
	ADC1Results[ADC1ResultIndex++] = ADC1_RA;
	ADC1_SC1A = ADC1SourceBytes[ADC1ResultIndex];
	__enable_irq();
	if (ADC1ResultIndex == ADC1_NUM_SOURCES){
		ADC1ResultIndex = 0;
	}
}

int notmain(void) {
	unsigned int i; char str[100];
	float c,f;
	//c=(ADC1_RA * 3.3 / (0xffff)) * 0.02;
	// Enable UART Pins
	uart_init();

	DAC0_INIT();
	ADC1_INIT();
	PDB_INIT();

	// Start the PDB (ADC Conversions)
	PDB0_SC |= PDB_SC_SWTRIG_MASK;

	for(;;) {}{
		i = ADC1_RA;
		c=(i/200.0)-48.0;//(i * 3.3 / (2<<12))*10;
		f = (c * 1.8) + 32;
		sprintf(str,"\n Celcius: %f farenheit: %f                \r",c,f);
		//sprintf(str,"\n Decimal: %d Hexadecimal: %x                \r",ADC1_RA,ADC1_RA);
		uart_putstring(str);
		for( i=0; i < 5000000; ++i ){

	}
}

return 0;
}
