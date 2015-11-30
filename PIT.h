#include <stdint.h>
#include "common.h"

#ifndef PIT_H
#define PIT_H
typedef struct {
	void (*T0ISR)(void);
	void (*T1ISR)(void);
} PITDataStruct;
void startPIT0(void  (*T0ISR)(), int ldVal);
void startPIT1(void  (*T1ISR)(), int ldVal);
void stopPIT0(void);
void stopPIT1(void);
void PIT0_IRQHandler(void);
void PIT1_IRQHandler(void);


#endif
