#include "common.h"
#include "uart.h"
#include "i2c.h"
#include "gpio.h"
#include "delay.h"
#include "cw.h"
#include "PID.h"
#include "pwm.h"

#include "adc.h"
#define inline __inline

//#include "ff.h"

int main(void);

volatile struct PIDDataStruct heaterPID;
volatile struct PIDDataStruct pumpCurrentPID;
volatile struct PIDDataStruct nernstVoltagePID;
float pumpCurrentMeasured;
float pumpCurrentDesired;
int pumpCurrentDutyCycle;
float nernstVoltage;
int heaterDutyCycle;
int nernstR;
void updatePIDs();
int main(){
	int pitldval;
	char buf[1000];
	int pitClock;
	InitPWM2(1000);
	LedPortInit();
	LedDirInit();
	ledGOn();
	ledBOn();
	ADC1_INIT();
	if(SystemCoreClock == 120000000u){
		pitClock = 60000000u;
	} else{
		pitClock = SystemCoreClock;
	}
	PIDInitialize(&heaterPID, .5, 0, .01, 
			80, 120, 40, 
			0, 100, .001);
/* Use the heaterPID, proportion of 0.5, no derivative, .01 integral, shoot for 
 * 80 ohms of resistance on the nernst cell, with a max and min, Output between 
 * 0 and 100. I promise I'll update every milisecond...*/ 
	PIDInitialize(&nernstVoltagePID, 8, 0, 0, 
			.45, 3.3, 0,
			-.01, .01, .001);
/* The above PID takes the nernst voltage, and produces a desired current
 * that will be driven into the pump. */ 
	PIDInitialize(&pumpCurrentPID, 1, 0, 0,  
			0, 0.01, -0.01,
			0, 100, .001);
	nernstR = 0;
	pumpCurrentMeasured = 0;
	pumpCurrentDutyCycle = 0;
	heaterDutyCycle = 0;


	
	
	
	
	/*
	
	
	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, .1);
	pumpCurrentMeasured = .01;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, .45);
	pumpCurrentMeasured = .01;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, 1);
	pumpCurrentMeasured = .01;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, .1);
	pumpCurrentMeasured = -.01;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, .45);
	pumpCurrentMeasured = -.01;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

	
	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, 1);
	pumpCurrentMeasured = -.01;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

	
	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, .1);
	pumpCurrentMeasured = 0;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, .45);
	pumpCurrentMeasured = 0;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

	
	
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, 1);
	pumpCurrentMeasured = 0;
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	PIDSetGoal(&pumpCurrentPID, pumpCurrentDesired);
	pumpCurrentDutyCycle = PIDUpdate(&pumpCurrentPID, pumpCurrentMeasured);

		
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	pitldval = pitClock / 1000;
/* Set up the PIT to trigger 100 times a second. */ 
	startPIT0(updatePIDs, pitldval);
	LedPortInit();
	LedDirInit();
uart_init();
ledBOff();
ledROff();
ledGOff();
	for(;;){
		sprintf((char*) buf, "Measured Nernst V %f\t PumpCurrent DC %u\t Measured PumpCurrent: %f \t DesiredPumpCurrent %f  \r", nernstVoltage, pumpCurrentDutyCycle,  pumpCurrentMeasured, pumpCurrentDesired);
		//sprintf((char*) buf, "%d\t%d\t%d\t%d\t\r\n", ADC1Results[0], ADC1Results[1],ADC1Results[2],ADC1Results[3]);
		//sprintf((char*) buf, "in: %d\tout: %f", ADC1Results[0],(3.3 * (float) ADC1Results[0]) / (float)(1<<15));
		//buf[100] = 0;
		uart_putstring("                                                                                                                                           \r");
		uart_putstring((char*) buf);
		//ledGToggle();
	}

}
void updatePIDs(){
	int16_t pumpCurrent = ADC1Results[0];
	int16_t nernstOut = ADC1Results[1];
	nernstVoltage = (3.3 * (float) nernstOut) / (float)(1<<15);
	if (nernstVoltage>3.3) nernstVoltage = 3.3;
	pumpCurrentDesired = PIDUpdate(&nernstVoltagePID, nernstVoltage);
	if (pumpCurrentDesired < 0){
		ledROn();
		ledBOff();
	} else {
		ledBOn();
		ledROff();
	} 
		
	pumpCurrentMeasured = (3.3 * (float) pumpCurrent) / (1<<15);
	if (pumpCurrentMeasured>3.3) pumpCurrentMeasured = 3.3;
	// Desired pump current runs from -.01 to .01.
	// Need to go from zero to 100. 
	// From range of .02 -> 100, Mult by 5000
	// Then add 50
	pumpCurrentDutyCycle = pumpCurrentDesired * 5000.0;
	pumpCurrentDutyCycle = pumpCurrentDutyCycle +50;
	if (pumpCurrentDutyCycle > 105) pumpCurrentDutyCycle =105;
	if (pumpCurrentDutyCycle < 1) pumpCurrentDutyCycle = 1;
	
	SetDutyCycle2(pumpCurrentDutyCycle);
		ADC1ResultIndex = 0;
		ADC1_SC1A = ADC1SourceBytes[ADC1ResultIndex];




}
/* Actually.
 * I want to go and update the PIDs every 10 millisecond. Clear cut. Every millisecond. 
 * But. I only want one sensor read for every output update. Thats all we need. 
 * So. We have the pump current reading. The heater currnt reading. And finally,
 * The cell resistance calculation (The hardest thing, imho.
 * So. we are going to do an update of the PIDs. 
 * We will set a flag that says Hey! Dont measure ADCs
 * A PIT loop called 4k times a second wil see this flag. 
 * It will say woooohooo, we can go to town.
 * It will set the GPIO to set 5V through the nernst cell. 
 * The next time through, it will read an ADC thats on the other end of the cell
 * It will then save this result, and let the ADCs be read again. 
 * The resistance can be calculated from this measurement. Because were doing this 
 * dynamic like, we dont even need the DC blokcng caps. I think. TBD.
 * But thats how the program should work. */ 
void startResistanceMeasurement(){
		 /* Who cares about signal integrety. 
		  * Not I said the college student. 
		  * Call this guy 4-5 K times a second. 
		  * He will toggle an output. If the input was high, he will 
		  * setup a read to a single ended ADC pin. 
		  * He will wait until that ADC is read. 
		  * This voltage will */ 
}
