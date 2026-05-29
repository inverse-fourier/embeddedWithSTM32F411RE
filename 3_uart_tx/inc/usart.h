#ifndef USART_H
#define USART_H

#include "stm32f411re.h"

void uart2_tx_init(void);
void uart2_write(int ch);

#endif /* USART_H */