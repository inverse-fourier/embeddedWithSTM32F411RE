#include <stdio.h>
#include "stm32f411re.h"
#include "usart.h"
#include "adc.h"
#include "systick.h"

#define GPIOAEN (1U<<0)
#define PA5     (1U<<5)

uint32_t sensor_value;

int main(void){

    RCC->AHB1ENR |= GPIOAEN; // enable clock for GPIOA

    /*Set PA5 to output mode*/
    GPIOA->MODER |= (1U<<10); // set PA5 to output
    GPIOA->MODER &= ~(1U<<11); // set PA5 to output

    uart2_txrx_init();

    while(1){
        GPIOA->ODR ^= PA5; // toggle PA5
        printf("A second has passed\r\n");
        systickDelayMs(1000); // Delay for 1 second
    }
    return 0;
}

