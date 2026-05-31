#ifndef SYSTICK_H
#define SYSTICK_H     

#include "stm32f411re.h"

#define SYSTICK_LOAD_VAL_1MS    16000
#define CTRL_ENABLE             (1UL << 0)           
#define CTRL_TICKINT            (1UL << 1)
#define CTRL_CLKSOURCE          (1UL << 2)
#define CTRL_COUNTFLAG          (1UL << 16)

void systickDelayMs(int delayInMs);

#endif /* SYSTICK_H */