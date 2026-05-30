#ifndef USART_H
#define USART_H

#include "stm32f411re.h"

/* UART2 is connected to APB1 bus, and its clock can be enabled by setting the 17th bit of APB1ENR register.*/
#define UART2_EN        (1UL << 17)
#define GPIOA_EN        (1UL << 0)

#define CR1_TE          (1UL << 3)
#define CR1_RE          (1UL << 2)

#define CR1_UE          (1UL << 13)
#define SR_TXE          (1UL << 7)
#define SR_RXNE         (1UL << 5)

#define SYS_FREQ        (16000000)
#define APB1_CLK        (SYS_FREQ)
#define UART_BAUDRATE   (115200)

void uart2_txrx_init(void);
void uart2_write(int ch);
char uart2_read(void);

#endif /* USART_H */