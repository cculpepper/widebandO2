#ifndef gpio_h
#define gpio_h
#define LedPortInit() SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK; LedDirInit(); PORTB->PCR[22] = PORT_PCR_MUX(1) ; PORTB->PCR[21] = PORT_PCR_MUX(1) ; PORTE->PCR[26] = PORT_PCR_MUX(1) ;
#define LedDirInit() PTB->PDDR |= LEDR | LEDB ;PTE->PDDR |= LEDG
#define SwPortInit() SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTA_MASK
#define LEDR (1<<22)
#define LEDG (1<<26)
#define LEDB (1<<21)
#define SWF (1<<6)
#define SWB (1<<4)
#define initSW1() PORTC->PCR[6] = PORT_PCR_MUX(1)
#define initSW2() PORTA->PCR[4] = PORT_PCR_MUX(1)
#define ledROn() PTB->PCOR |= LEDR
#define ledROff() PTB->PSOR |= LEDR
#define ledRToggle() PTB->PTOR |= LEDR
#define ledBOn() PTB->PCOR |= LEDB
#define ledBOff() PTB->PSOR |= LEDB
#define ledBToggle() PTB->PTOR |= LEDB
#define ledGOn() PTE->PCOR |= LEDG
#define ledGOff() PTE->PSOR |= LEDG
#define ledGToggle() PTE->PTOR |= LEDG
#define ledData(x) PTC->PDO |= (x<<7) | (PTC->PDO & ~ (0xF << 7))
#define getSw1() (PTC->PDIR & SWF)
#define getSw2() (PTA->PDIR & SWB)
#endif	/* 
 */
