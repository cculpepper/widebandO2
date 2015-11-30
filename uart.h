#include <MK64F12.h>

#ifndef UART_H
#define UART_H
/* This is part of my generic uart driver. All functions are written generically
 * to make it easier for me to write them and to test them. */ 
    typedef struct {
	volatile UART_Type *UART;
} uartDataStruct;
 extern volatile uartDataStruct uart0Data;
 void uartInit(UART_Type * UART_to_init, int baud);
int uartGetString(uartDataStruct uartData, char *str, int len);
int uartTxInQueue(uartDataStruct uartData);
void uartWait(uartDataStruct uartData);
void uartPutString(uartDataStruct uartData, char *str);
void uartPutChar(uartDataStruct uartData, char ch);
void uartPutCharBlock(uartDataStruct uartData, char ch);
char uartGetChar(uartDataStruct uartData);
char uartGetCharBlock(uartDataStruct uartData);
void uartputNum(uartDataStruct uartData, int num);
 
#define uart_getchar() uartGetCharBlock( uart0Data )
#define uart_putchar(c) uartPutCharBlock(uart0Data, c)
#define uart_putstring(s) uartPutString(uart0Data, s)
#define put(s) uartPutString(uart0Data, s)
#define uart_init() uartInit(UART0, 9600)
/* Required lab functions ^*/ 
#endif	/*  */
    
