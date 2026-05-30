#include "systick.h"

void systickDelayMs(int delayInMs){
    /* Configure SysTick for 1ms delay */
    /* Reload with number of 1ms intervals */
    SYSTICK->LOAD = SYSTICK_LOAD_VAL_1MS - 1; // Set reload value for 1ms delay

    // Clear current value and count flag
    SYSTICK->VAL = 0; // Clear current value

    /* Enable SysTick and select internal clock */
    SYSTICK->CTRL = CTRL_ENABLE | CTRL_CLKSOURCE; // Enable SysTick with internal clock

    for(int i = 0; i < delayInMs; i++){
        // Wait until the COUNTFLAG is set
        while((SYSTICK->CTRL & CTRL_COUNTFLAG) == 0);
    }

    SYSTICK->CTRL = 0; // Disable SysTick after delay
}