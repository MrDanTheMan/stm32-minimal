#ifndef SYS_STM32F4_H
#define SYS_STM32F4_H

#include <stdint.h>
#include "stm32f4xx.h"


/// NucleoF401RE internal clock frequency in Hz
#ifndef HSI_CLK_FREQ
#define HSI_CLK_FREQ 16000000UL
#endif

/// Max clock speed supported by the STM32F401 in Hz
#ifndef MAX_CLK_FREQ
#define MAX_CLK_FREQ 84000000UL
#endif

// PLL coefficients to optain max clock speed of 84MHz
// Output clock formula ((InputFreq / PLL_M) * PLL_N) / PLL_P
#define PLL_M  HSI_CLK_FREQ / 1000000UL
#define PLL_N  336U
#define PLL_P  1U //(DIV 4)
#define PLL_Q  8U

// Bus speed prescalers
// AHB - main system bus | APB1 low speed peripheral bus | APB2 high speed peripheral bus
#define AHB_SCALE 0U
#define APB1_SCALE 2U
#define APB2_SCALE 0U

extern void ConfigureSys(void);
extern void ConfigureSysTick(uint32_t interval);
extern void ConfigureSysClockHSI(void);
extern void ConfigureSysClockPLL(void);

#endif