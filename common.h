#ifndef COMMON_H
#define COMMON_H

#include <MK64F12.h>
#include <stdint.h>
#include <system_MK64F12.h>



#if (DEFAULT_SYSTEM_CLOCK == 20485760u)
#define DEFAULT_BUS_CLOCK 20485760u
#elif (DEFAULT_SYSTEM_CLOCK == 120000000u)
#define DEFAULT_BUS_CLOCK 60000000u
#else
#define DEFAULT_BUS_CLOCK 60000000u

#endif

#endif
