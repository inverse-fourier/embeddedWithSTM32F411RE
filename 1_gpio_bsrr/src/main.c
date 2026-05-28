#include "stm32f411re.h"

#define GPIOA_EN    (1UL << 0)
#define BS5         (1UL << 5)
#define BR5         (1UL << (5 + 16))

void delay(void){
    for(int i=0;i<500000;i++){}
}

int main(void){
    // 1. Enable clock access to GPIOA
    RCC->AHB1ENR  |= GPIOA_EN;

    // 2. Set PA5 a output pin
    GPIOA->MODER |= (1UL << 10);
    GPIOA->MODER &= ~(1UL << 11);

    while(1){
        // 3. Set PA5 as high
        //GPIOA_OD_R |= LED_PIN;
        GPIOA->BSRR = BS5;
        delay();
        GPIOA->BSRR = BR5;
        delay();
    }
    return 0;
}











