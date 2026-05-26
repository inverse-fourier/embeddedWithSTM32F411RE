#include <stdint.h>
#define PERIPH_BASE         (0X40000000UL)
#define AHB1PERIPH_OFFSET   (0X00020000UL)
#define AHB1PERIPH_BASE     (PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOA_OFFSET        (0X00000000UL)
#define GPIOA_BASE          (AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET          (0X00003800UL)
#define RCC_BASE            (AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET     (0X30UL)
#define RCC_AHB1EN_R        (*(volatile uint32_t*)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET       (0X0000UL)
#define GPIOA_MODE_R        (*(volatile uint32_t*)(GPIOA_BASE + MODE_R_OFFSET))

#define ODR_OFFSET          (0X14UL)
#define GPIOA_OD_R          (*(volatile uint32_t*)(GPIOA_BASE + ODR_OFFSET))

#define GPIOAEN             (1U << 0)

#define PIN5                (1U << 5)
#define LED_PIN             (PIN5)

int main(void){
    // 1. Enable clock access to GPIOA
    RCC_AHB1EN_R  |= GPIOAEN;

    // 2. Set PA5 a output pin
    GPIOA_MODE_R |= (1U << 10);
    GPIOA_MODE_R &= ~(1U << 11);

    while(1){
    // 3. Set PA5 as high
    //GPIOA_OD_R |= LED_PIN;
    
    GPIOA_OD_R ^= LED_PIN;
    for(int i=0;i<500000;i++){}
    
    }
    return 0;
}











