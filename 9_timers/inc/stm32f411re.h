#ifndef STM32F411RE_H
#define STM32F411RE_H

#include <stdint.h>

/*Vendor Specific Definitions */
#define PRIVATE_PERIPH_BASE   (0xE0000000UL)
#define SCS_OFFSET            (0x0000E000UL)
#define SCS_BASE              (PRIVATE_PERIPH_BASE + SCS_OFFSET)
#define SYSTICK_OFFSET        (0x0010UL)
#define SYSTICK_BASE          (SCS_BASE + SYSTICK_OFFSET)

#define PERIPH_BASE         (0X40000000UL)

#define AHB1_OFFSET         (0X00020000UL)
#define AHB1_BASE           (PERIPH_BASE + AHB1_OFFSET)

#define APB2_OFFSET         (0X00010000UL)
#define APB2_BASE           (PERIPH_BASE + APB2_OFFSET)

#define APB1_OFFSET         (0X00000000UL)
#define APB1_BASE           (PERIPH_BASE + APB1_OFFSET)

/* ---------- AHB1 REGISTERS ---------- */
#define RCC_OFFSET          (0X00003800UL)
#define RCC_BASE            (AHB1_BASE + RCC_OFFSET)

#define GPIOA_OFFSET        (0X00000000UL)
#define GPIOA_BASE          (AHB1_BASE + GPIOA_OFFSET)

#define GPIOC_OFFSET        (0X00000800UL)
#define GPIOC_BASE          (AHB1_BASE + GPIOC_OFFSET)
/* ---------- AHB1 REGISTERS END ---------- */

/* ---------- APB2 REGISTERS ---------- */
#define ADC1_OFFSET         (0X00002000UL)
#define ADC1_BASE           (APB2_BASE + ADC1_OFFSET)
/* ---------- APB2 REGISTERS END ---------- */

/* ---------- APB1 REGISTERS ---------- */
#define USART2_OFFSET       (0X00004400UL)
#define USART2_BASE         (APB1_BASE + USART2_OFFSET)

#define TIM2_OFFSET         (0X00000000UL)
#define TIM2_BASE           (APB1_BASE + TIM2_OFFSET)
/* ---------- APB1 REGISTERS END ---------- */


#define __IO                volatile
#define __IOM               volatile
#define __IM                volatile const

typedef struct
{
  __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  uint32_t      RESERVED7[1];  /*!< Reserved, 0x88                                                                    */
  __IO uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
} RCC_TypeDef;
#define RCC                 ((RCC_TypeDef*)RCC_BASE)


typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFRL;     /*!< GPIO alternate function registers,     Address offset: 0x20      */
  __IO uint32_t AFRH;     /*!< GPIO alternate function registers,     Address offset: 0x24      */
} GPIO_TypeDef;
#define GPIOA               ((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOC               ((GPIO_TypeDef*)GPIOC_BASE)

typedef struct
{
  __IO uint32_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
  __IO uint32_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
  __IO uint32_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
  __IO uint32_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
  __IO uint32_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
  __IO uint32_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
  __IO uint32_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} USART_TypeDef;
#define USART2              ((USART_TypeDef*)USART2_BASE)

typedef struct{
  __IO uint32_t SR;         /*!< ADC status register,                             Address offset: 0x00 */
  __IO uint32_t CR1;        /*!< ADC control register 1,                          Address offset: 0x04 */
  __IO uint32_t CR2;        /*!< ADC control register 2,                          Address offset: 0x08 */
  __IO uint32_t SMPR1;      /*!< ADC sample time register 1,                      Address offset: 0x0C */
  __IO uint32_t SMPR2;      /*!< ADC sample time register 2,                      Address offset: 0x10 */
  __IO uint32_t JOFR1;      /*!< ADC injected channel data offset register 1,     Address offset: 0x14 */
  __IO uint32_t JOFR2;      /*!< ADC injected channel data offset register 2,     Address offset: 0x18 */
  __IO uint32_t JOFR3;      /*!< ADC injected channel data offset register 3,     Address offset: 0x1C */
  __IO uint32_t JOFR4;      /*!< ADC injected channel data offset register 4,     Address offset: 0x20 */
  __IO uint32_t HTR;        /*!< ADC watchdog higher threshold register,          Address offset: 0x24 */
  __IO uint32_t LTR;        /*!< ADC watchdog lower threshold register,           Address offset: 0x28 */
  __IO uint32_t SQR1;       /*!< ADC regular sequence register 1,                 Address offset: 0x2C */
  __IO uint32_t SQR2;       /*!< ADC regular sequence register 2,                 Address offset: 0x30 */
  __IO uint32_t SQR3;       /*!< ADC regular sequence register 3,                 Address offset: 0x34 */
  __IO uint32_t JSQR;       /*!< ADC injected sequence register,                  Address offset: 0x38 */
  __IO uint32_t JDR1;       /*!< ADC injected data register 1,                    Address offset: 0x3C */
  __IO uint32_t JDR2;       /*!< ADC injected data register 2,                    Address offset: 0x40 */
  __IO uint32_t JDR3;       /*!< ADC injected data register 3,                    Address offset: 0x44 */
  __IO uint32_t JDR4;       /*!< ADC injected data register 4,                    Address offset: 0x48 */    
  __IO uint32_t DR;         /*!< ADC regular data register,                       Address offset: 0x4C */ 

} ADC1_TypeDef;
#define ADC1                ((ADC1_TypeDef*)ADC1_BASE)

typedef struct
{
  __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IOM uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __IOM uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  __IM  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_TypeDef;
#define SYSTICK            ((SysTick_TypeDef*)SYSTICK_BASE)

typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
  __IO uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
  __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
  __IO uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
} TIM_TypeDef;
#define TIM2                ((TIM_TypeDef*)TIM2_BASE)

#endif /* STM32F411RE_H */




