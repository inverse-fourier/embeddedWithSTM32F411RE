#include <stdio.h>
#include "stm32f411re.h"
#include "usart.h"
#include "adc.h"

#define GPIOAEN (1U<<0)
#define PA5     (1U<<5)

uint32_t sensor_value;

int main(void){

    uart2_txrx_init();
    pa1_adc_init();

    while(1){
        start_adc_conversion();
        sensor_value = read_adc_value();
        printf("Sensor Value: %lu\r\n", sensor_value);
    }
    return 0;
}

