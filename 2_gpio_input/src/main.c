#include "stm32f411re.h"

/*On stm32f411re nucleo board push button is connected to PC13
and LED is connected to PA5. So we will read the state of push button and
toggle the LED accordingly.*/

#define GPIOA_EN    (1UL << 0)
#define GPIOC_EN    (1UL << 2)


int main(void){
    // 1. Enable clock access to GPIOA
    RCC->AHB1ENR  |= GPIOA_EN;
    RCC->AHB1ENR  |= GPIOC_EN;

    // 2. Set PA5 a output pin
    GPIOA->MODER |= (1UL << 10);
    GPIOA->MODER &= ~(1UL << 11);

    // 3. Set PC13 as input pin
    GPIOC->MODER &= ~(3UL << 26);

    while(1){
        // 4. Check if PC13 is pressed
        if(!((GPIOC->IDR) & (1UL << 13)))
            GPIOA->BSRR |= (1UL << 5);
        else
            GPIOA->BSRR |= (1UL << (5+16));
    }
    return 0;
}











