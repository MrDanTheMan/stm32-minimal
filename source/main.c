#include "sys_stm32f4.h"

void Wait(uint32_t ms);

extern uint32_t SysClkMs;
extern uint32_t SysClkFreq;

void main()
{
    // Enable clock for GPIO port A & Set GPIO Pin5 (USR LED) To output mode
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    while(1)
    {
        //Enable LED
        GPIOA->BSRR |= GPIO_BSRR_BS5;
        Wait(80UL);

        // Disable LED
        GPIOA->BSRR |= GPIO_BSRR_BR5;
        Wait(100UL);

        // Enable LED
        GPIOA->BSRR |= GPIO_BSRR_BS5;
        Wait(80UL);

        // Disable LED
        GPIOA->BSRR |= GPIO_BSRR_BR5;
        Wait(500UL);
    }
    
    return;
}

void Wait(uint32_t ms)
{
    uint32_t st = SysClkMs;

    while(SysClkMs - st < ms)
    {
        // wait
    }
}