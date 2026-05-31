#ifndef TIMERS_H
#define TIMERS_H
#include "stm32f411re.h"

#define RCC_APB1ENR_TIM2EN  (1 << 0) // Bit 0 enables TIM2 clock
#define TIM_CR1_CEN         (1 << 0) // Bit 0 enables the

#define TIM_SR_UIF          (1 << 0) // Update interrupt flag

void TIM2_1HZ_Init(void);

#endif

