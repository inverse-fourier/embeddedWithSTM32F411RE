#include "adc.h"

void pa1_adc_init(void)
{
    /*  Configure the ADC module    */

    /* Enable clock access to GPIOA */
    RCC->AHB1ENR |= GPOIA_EN;

    /* Set PA1 mode to analog */
    GPIOA->MODER |= (3U << 2); /* Set bits 2-3 to 11 for analog mode */

    /* Enable the clock for ADC1 peripheral */
    RCC->APB2ENR |= ADC1_EN;

    /* Configure ADC1 */
    /* Conversion sequence start */
    ADC1->SQR3 = ADC_CHANNEL_1; /* Set the first conversion in regular sequence to channel 1 (PA1) */

    /* Configure conversion sequence length */
    ADC1->SQR1 = ADC_SEQ_LENGTH_1; /* Set regular sequence length to 1 conversion */

    /* Enable the ADC1 Module */
    ADC1->CR2 |= CR2_AD_ON; /* Set the ADON bit to enable the ADC */

}

void start_adc_conversion(void)
{
    /* Start ADC conversion */
    ADC1->CR2 |= CR2_SWSTART; /* Set the SWSTART bit to start conversion */
}

uint32_t read_adc_value(void)
{
    /* Wait until conversion is complete */
    while (!(ADC1->SR & ADC_SR_EOC)); /* Wait for EOC (End of Conversion) bit to be set */

    /* Read and return the converted value */
    return ADC1->DR; /* Return the data register value which contains the conversion result */
}