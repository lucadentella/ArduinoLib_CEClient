#ifndef COMMON_H__
#define COMMON_H__

#if defined(ARDUINO_ARCH_STM32F1) || defined(ARDUINO_ARCH_STM32F2) || defined(ARDUINO_ARCH_STM32F3) || defined(ARDUINO_ARCH_STM32F4)
# define STM32
#endif


#ifdef WIN32
#include <windows.h>
#include <stdio.h>
#include <assert.h>

#define ASSERT(x) assert(x)
void DbgPrint(const char* fmt, ...);

extern "C"
{
extern unsigned long micros();
extern void delayMicroseconds(unsigned int);
}

#elif defined(STM32)

#include "dwt.h"

#define ASSERT(x) ((void)0)
void DbgPrint(const char* fmt, ...);
#ifndef NULL
	#define NULL 0
#endif

/*
static const uint32_t cyclesPerUS = (SystemCoreClock / 1000000ul);
static inline unsigned long micros() {
    bool ready = false;
    if (!ready) {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        DWT->CTRL |= 1;
        ready = true;
    }
    return DWT->CYCCNT / cyclesPerUS; // TODO: handle wraparound
}*/
#else

#define ASSERT(x) ((void)0)
void DbgPrint(const char* fmt, ...);
#ifndef NULL
	#define NULL 0
#endif


extern "C"
{
extern unsigned long micros();
extern void delayMicroseconds(unsigned int);
}

#endif

#endif // COMMON_H__
