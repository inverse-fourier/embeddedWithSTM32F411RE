#include "stm32f411re.h"
#include "usart.h"

int main(void){

    uart2_tx_init();

    uart2_write('H');
    uart2_write('E');
    uart2_write('L');
    uart2_write('L');
    uart2_write('O');
    uart2_write('\n');
    while(1){}
    
    return 0;
}















