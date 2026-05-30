
#include "usart.h"
/* UART2 is connected to APB1 bus, and its clock can be enabled by setting the 17th bit of APB1ENR register.*/
#define UART2_EN        (1UL << 17)
#define GPIOA_EN        (1UL << 0)
#define CR1_TE          (1UL << 3)
#define CR1_UE          (1UL << 13)

#define SYS_FREQ        (16000000)
#define APB1_CLK        (SYS_FREQ)
#define UART_BAUDRATE   (115200)

static uint16_t compute_uart_bd(uint32_t periphClk, uint32_t BaudRate){
    return ((periphClk + (BaudRate)/2U)/BaudRate);

}

static void uart_set_BaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate){
    USARTx->BRR = compute_uart_bd(PeriphClk,BaudRate);
}


void uart2_tx_init(void){

    /********** Configure uart GPIO pin ***********/
    /* Enble clock access to GPIOA */
    RCC->AHB1ENR = GPIOA_EN;

    /* Set PA2 mode to alternate function mode */
    // For alternate function mode MODER2[1:0] should be 10
    GPIOA->MODER |= (1UL << 5);
    GPIOA->MODER &= ~(1UL << 4);

    /* Set PA2 alternate function type to UART_TX (AF07)*/
    // For AF07, AFRL2[3:0] should be 0111
    GPIOA->AFRL |=  (1UL << 8);
    GPIOA->AFRL |=  (1UL << 9);
    GPIOA->AFRL |=  (1UL << 10);
    GPIOA->AFRL &= ~(1UL << 11);



    /********** Configure uart module **********/
    /* Enable clock access to uart2 */
    RCC->APB1ENR |= UART2_EN;

    /* Configure baudrate */
    uart_set_BaudRate(USART2,APB1_CLK,UART_BAUDRATE);

    /* Configure the transfer direction */
    USART2->CR1 = CR1_TE;          

    /* Enable UART module */
    USART2->CR1 |= CR1_UE;

}

void uart2_write(int ch){
    /* Make sure transmit data register is empty */
    while(!(USART2->SR & (1UL << 7)));

    /* Write to transmit data register */
    USART2->DR = (ch & 0xFF);
}

int __io_putchar(int ch){
    uart2_write(ch);
    return ch;
}