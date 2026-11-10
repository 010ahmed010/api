#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_0)
    {
        // PB0: Turn OFF LED and display '0'
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
        GPIOA->ODR = 0x0040; // Common Anode pattern for '0'
    }
    else if (GPIO_Pin == GPIO_PIN_1)
    {
        // PB1: Turn ON LED and display '1'
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
        GPIOA->ODR = 0x0079; // Common Anode pattern for '1'
    }
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    // Initial State: LED OFF, Display '0'
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
    GPIOA->ODR = 0x0040;

    while (1)
    {
        // Main loop is free; everything handled via interrupts
    }
}
