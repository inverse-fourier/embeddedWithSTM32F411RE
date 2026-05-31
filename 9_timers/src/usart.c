
#include "usart.h"

static uint16_t compute_uart_bd(uint32_t periphClk, uint32_t BaudRate){
    return ((periphClk + (BaudRate)/2U)/BaudRate);
}

static void uart_set_BaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate){
    USARTx->BRR = compute_uart_bd(PeriphClk,BaudRate);
}


void uart2_txrx_init(void){

    /********** Configure uart GPIO pin ***********/
    /* Enble clock access to GPIOA */
    RCC->AHB1ENR = GPIOA_EN;

    /* Set PA2 mode to alternate function mode */
    // For alternate function mode MODER2[1:0] should be 10
    GPIOA->MODER |= (1UL << (2*2 + 1));
    GPIOA->MODER &= ~(1UL << (2*2));

    /* Set PA3 mode to alternate function mode */
    // For alternate function mode MODER3[1:0] should be 10
    GPIOA->MODER |= (1UL << (3*2 + 1));
    GPIOA->MODER &= ~(1UL << (3*2));

    /* Set PA2 and PA3 alternate function type to UART_TX and UART_RX (AF07)*/
    // For AF07, AFRL2[3:0] should be 0111
    GPIOA->AFRL |=  (1UL << (2*4 + 0));
    GPIOA->AFRL |=  (1UL << (2*4 + 1));
    GPIOA->AFRL |=  (1UL << (2*4 + 2));
    GPIOA->AFRL &= ~(1UL << (2*4 + 3));

// For AF07, AFRL3[3:0] should be 0111
    GPIOA->AFRL |=  (1UL << (3*4 + 0));
    GPIOA->AFRL |=  (1UL << (3*4 + 1));
    GPIOA->AFRL |=  (1UL << (3*4 + 2));
    GPIOA->AFRL &= ~(1UL << (3*4 + 3));

    /********** Configure uart module **********/
    /* Enable clock access to uart2 */
    RCC->APB1ENR |= UART2_EN;

    /* Configure baudrate */
    uart_set_BaudRate(USART2,APB1_CLK,UART_BAUDRATE);

    /* Configure the transfer direction */
    USART2->CR1 = CR1_TE | CR1_RE;          

    /* Enable UART module */
    USART2->CR1 |= CR1_UE;

}

char uart2_read(void){
    /* Make sure receive data register is not empty */
    while(!(USART2->SR & SR_RXNE));

    /* Read from receive data register */
    return USART2->DR;
}

void uart2_write(int ch){
    /* Make sure transmit data register is empty */
    while(!(USART2->SR & SR_TXE));

    /* Write to transmit data register */
    USART2->DR = (ch & 0xFF);
}

int __io_putchar(int ch){
    uart2_write(ch);
    return ch;
}