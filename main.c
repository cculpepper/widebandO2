#include "common.h"
#include "uart.h"
#include "i2c.h"
#include "gpio.h"
#include "delay.h"
#include "cw.h"
#include "PID.h"
#include "pwm.h"
#define inline __inline

//#include "ff.h"

int main(void);

struct PIDDataStruct heaterPID;
struct PIDDataStruct pumpCurrentPID;
int nernstR;
int pumpCurrentMeasured;
int pumpCurrentOut;
int heaterDutyCycle;
void updatePIDs();
int main(){
	int pitldval;
	int pitClock;
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
	PIDInitialize(&pumpCurrentPID, .5, 0, 0, 
			.45, 0, 3.3,
			0, 100, .001);
	nernstR = 0;
	pumpCurrentMeasured = 0;
	pumpCurrentOut = 0;
	heaterDutyCycle = 0;


	pitldval = pitClock / 1000;
/* Set up the PIT to trigger 1000 times a second. */ 
	startPIT0(updatePIDs, pitldval);
}
void updatePIDs(){


}
/* Actually.
 * I want to go and update the PIDs every millisecond. Clear cut. Every millisecond. 
 * But. I only want one sensor read for every output update. Thats all we need. 
 * So. We have the pump current reading. The heater current reading. And finally,
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
