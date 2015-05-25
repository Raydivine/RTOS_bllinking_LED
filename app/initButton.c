#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initButton.h"

void initButton(){
  //GPIO_TypeDef GpioType;
  GPIO_InitTypeDef pushButton;

  __GPIOA_CLK_ENABLE();

  pushButton.Mode = GPIO_MODE_INPUT;
  pushButton.Pin = GPIO_PIN_0;
  pushButton.Pull = GPIO_NOPULL;
  pushButton.Speed = GPIO_SPEED_HIGH;

  //GpioInfo.Alternate = GPIO_MODE_AF_PP;
  //Init LED on PA0
  HAL_GPIO_Init(GPIOA, &pushButton);
}
