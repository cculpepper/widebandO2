/*
* Rochester Institute of Technology
* Department of Computer Engineering
*  CMPE 460  Interfacing Digital Electronics
Spring 2015

*
*
* Filename: main.c
*/
#ifndef ADC_H
#define ADC_H
#include "uart.h"
#include <MK64F12.h>
#include <stdio.h>


void PDB_INIT(void) ;

void ADC1_INIT(void) ;

// ADC1 Conversion Complete ISR
void ADC1_IRQHandler(void) ;
#define ADC1_NUM_SOURCES 4
const extern uint8_t ADC1SourceBytes[ADC1_NUM_SOURCES];
volatile extern int ADC1ResultIndex;
volatile extern int16_t ADC1Results[ADC1_NUM_SOURCES];
#endif
