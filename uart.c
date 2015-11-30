#include "MK64F12.h"
#include "uart.h"
#include <stdint.h>
#define MAXQUEUE 80
#define MAXGETRETRIES 100000

#define BAUD_RATE 9600		//default baud rate 
#define SYS_CLOCK 20485760	//default system clock (see DEFAULT_SYSTEM_CLOCK  in system_MK64F12.c)
volatile uartDataStruct uart0Data;
 void uartInit(UART_Type * UART_to_init, int baud)
{
	uint16_t ubd, brfa;
	
	    /* Init clocks
	     * Init pins
	     * Init baud*/ 
	    if (UART_to_init == (UART_Type *) UART0) {
		SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
		
		    /*Also need to get the pins correct. PTB16 is TX, RX is PTB17 */ 
		    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
		PORTB->PCR[16] = PORT_PCR_MUX(3);
		PORTB->PCR[17] = PORT_PCR_MUX(3);
		uart0Data.UART = (UART_Type *) UART0;	/* This is used for generic functions */
		
		    //NVIC_EnableIRQ(UART0_IRQn);
	} else {
		return;
	}
	 ubd = (uint16_t) ((SYS_CLOCK) / (BAUD_RATE * 16));
	 
	    //clear SBR bits of BDH
	    UART_to_init->BDL = ubd & UART_BDL_SBR_MASK;
	UART_to_init->BDH = (ubd >> 8) & UART_BDH_SBR_MASK;
	 
	    //distribute this ubd in BDH and BDL
	     
	    //BRFD = (1/32)*BRFA 
	    //make the baud rate closer to the desired value by using BRFA
	    brfa = (((SYS_CLOCK * 32) / (BAUD_RATE * 16)) - (ubd * 32));
	UART_to_init->C4 = brfa;
	UART_to_init->C2 = UART_C2_RE_MASK | UART_C2_TE_MASK;
	
	    /* Enable the receiver and transmitter. */ 
 }

 void uartPutString(uartDataStruct uartData, char *str)
{
	
	    /* Puts a string into a specified buffer. Nothing fancy. */ 
	int i;
	char curr;
	i = 0;
	curr = str[i];
	while (curr) {
		uartPutCharBlock(uartData, curr);
		curr = str[++i];
	}
	
	    /*UCA0IE |=  UCTXIE; */ 
}

void uartPutCharBlock(uartDataStruct uartData, char ch)
{
	
	    /* Puts a character, but blocks. (uses poling).
	     * Disables TX interrupts because polling. */ 
	    uartData.UART->C2 &= ~UART_C2_TIE_MASK;
	while ((uartData.UART->S1 & UART_S1_TDRE_MASK) == 0) ;
	uartData.UART->D = ch;
}

char uartGetCharBlock(uartDataStruct uartData)
{
	
	    /* This is a polling get char. It polls the RFRF flag */ 
	char ret;
	char status;
	uartData.UART->C2 &= ~(UART_C2_RIE_MASK);
	status = uartData.UART->S1;
	while ((status & UART_S1_RDRF_MASK) == 0) {
		status = uartData.UART->S1;
	}
	ret = uartData.UART->D;
	
	    /*UART->C2 |= (UART_C2_RIE_MASK); */ 
	    /* This means that we need to initialize the uart again. 
	     * */ 
	    return ret;
}


