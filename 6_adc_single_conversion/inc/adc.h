#ifndef ADC_H
#define ADC_H
#include "stm32f411re.h"

#define ADC1_EN             (1U << 8)   /* ADC1 clock enable bit in RCC APB2ENR register */
#define GPOIA_EN            (1U << 0)   /* GPIOA clock enable bit in RCC AHB1ENR register */
#define ADC_CHANNEL_1       (1U << 0)   /* ADC channel 1 corresponds to PA1 pin */
#define ADC_SEQ_LENGTH_1    (0x00UL)    /* ADC regular sequence length of 1 conversion */
#define CR2_AD_ON           (1U << 0)   /* ADC on/off bit in ADC_CR2 register */
#define CR2_SWSTART         (1U << 30)  /* ADC software start conversion bit in ADC_CR2 register */
#define ADC_SR_EOC          (1U << 1)   /* ADC End of Conversion bit in ADC_SR register */

void pa1_adc_init(void);
void start_adc_conversion(void);
uint32_t read_adc_value(void);

#endif /* ADC_H */