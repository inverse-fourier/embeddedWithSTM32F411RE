#include <stdio.h>
#include "stm32f411re.h"
#include "usart.h"
#include "adc.h"
#include "systick.h"
#include "timers.h"

#define GPIOAEN (1U<<0)
#define PA5     (1U<<5)

uint32_t sensor_value;

int main(void){

    RCC->AHB1ENR |= GPIOAEN; // enable clock for GPIOA

    /*Set PA5 to output mode*/
    GPIOA->MODER |= (1U<<10); // set PA5 to output
    GPIOA->MODER &= ~(1U<<11); // set PA5 to output

    uart2_txrx_init();
    TIM2_1HZ_Init();

    while(1){

        while(!(TIM2->SR & TIM_SR_UIF)); // wait for update interrupt flag
        TIM2->SR &= ~TIM_SR_UIF; // clear the update interrupt flag
        GPIOA->ODR ^= PA5; // toggle PA5
        printf("A second has passed\r\n");

    }
    return 0;
}

