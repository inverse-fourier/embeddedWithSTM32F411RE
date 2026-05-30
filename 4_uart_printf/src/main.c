#include <stdio.h>
#include "stm32f411re.h"
#include "usart.h"

int main(void){

    uart2_tx_init();
    while(1){
        printf("Hello World!\n");
    }
    
    return 0;
}















