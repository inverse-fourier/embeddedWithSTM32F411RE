#include "timers.h"

void TIM2_1HZ_Init(void)
{
    // Enable the clock for TIM2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Set the prescaler and auto-reload values for 1 Hz frequency
    TIM2->PSC = 16000 - 1; // Prescaler value (16 MHz / 16000 = 1 kHz)
    TIM2->ARR = 1000 - 1;  // Auto-reload value (1 kHz / 1000 = 1 Hz)

    /* Clear the counter */
    TIM2->CNT = 0;

    // Enable the timer
    TIM2->CR1 |= TIM_CR1_CEN;
}



