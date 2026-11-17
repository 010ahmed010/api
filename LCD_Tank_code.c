#include "main.h"
#include "lcd_txt.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

char zeroMessage[16] = "The level is 0%";
char half[16]        = "The level is 50%";
char full[16]        = "The level is 100%";
char errorMessage[16] = "Error";

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  
  /* USER CODE BEGIN 2 */
  lcd_init();

  while (1)
  {
    // Note: Input pins on Port B (PB0 and PB1)
    // Output pins on Port A (PA0 to PA5 for LCD)

    // 0% Level
    if ((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 1) &&
        (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1))
    {
      lcd_puts(0, 0, zeroMessage);
    }
    // 50% Level
    else if ((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0) &&
             (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 1))
    {
      lcd_puts(0, 0, half);
    }
    // 100% Level
    else if ((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0) && 
             (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 0))
    {
      lcd_puts(0, 0, full);
    }
    // Error: Invalid sequence 
    else
    {
      lcd_puts(0, 0, errorMessage);
    }

    HAL_Delay(50);
    lcd_clear();
  }
}