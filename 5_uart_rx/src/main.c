#include <stdio.h>
#include "stm32f411re.h"
#include "usart.h"

#define GPIOAEN (1U<<0)
#define PA5     (1U<<5)


int main(void){

    RCC->AHB1ENR |= GPIOAEN;
    GPIOA->MODER |= (1U << (5*2));
    GPIOA->MODER &= ~(1U << (5*2 + 1));
    uart2_txrx_init();

    while(1){
        if(uart2_read() == '1'){
            GPIOA->ODR |= PA5;
        }
        else{
            GPIOA->ODR &= ~PA5;
        }
    }
    
    return 0;
}















