#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initGPIO.h"


void initLED1(){
	//GPIO_TypeDef 	 GpioType;
	GPIO_InitTypeDef Gpio_Pin13;

	__GPIOG_CLK_ENABLE();

	Gpio_Pin13.Mode = GPIO_MODE_OUTPUT_PP;
	Gpio_Pin13.Pin = GPIO_PIN_13;
	Gpio_Pin13.Pull = GPIO_NOPULL;
	Gpio_Pin13.Speed = GPIO_SPEED_HIGH;
	Gpio_Pin13.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG13
	HAL_GPIO_Init(GPIOG, &Gpio_Pin13);

}

void initLED2(){
	//GPIO_TypeDef 	 GpioType;
	GPIO_InitTypeDef Gpio_Pin14;

	__GPIOG_CLK_ENABLE();

	Gpio_Pin14.Mode = GPIO_MODE_OUTPUT_PP;
	Gpio_Pin14.Pin = GPIO_PIN_14;
	Gpio_Pin14.Pull = GPIO_NOPULL;
	Gpio_Pin14.Speed = GPIO_SPEED_HIGH;
	Gpio_Pin14.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG14
	HAL_GPIO_Init(GPIOG, &Gpio_Pin14);
}

void initLED3(){
	//GPIO_TypeDef 	 GpioType;
	GPIO_InitTypeDef Gpio_Pin13;

	__GPIOG_CLK_ENABLE();

	Gpio_Pin13.Mode = GPIO_MODE_OUTPUT_PP;
	Gpio_Pin13.Pin = GPIO_PIN_13;
	Gpio_Pin13.Pull = GPIO_NOPULL;
	Gpio_Pin13.Speed = GPIO_SPEED_HIGH;
	Gpio_Pin13.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG13
	HAL_GPIO_Init(GPIOB, &Gpio_Pin13);

}

void initLED4(){
	//GPIO_TypeDef 	 GpioType;
	GPIO_InitTypeDef Gpio_Pin14;

	__GPIOG_CLK_ENABLE();

	Gpio_Pin14.Mode = GPIO_MODE_OUTPUT_PP;
	Gpio_Pin14.Pin = GPIO_PIN_14;
	Gpio_Pin14.Pull = GPIO_NOPULL;
	Gpio_Pin14.Speed = GPIO_SPEED_HIGH;
	Gpio_Pin14.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG14
	HAL_GPIO_Init(GPIOC, &Gpio_Pin14);
}

void initUserButton(){
	//GPIO_TypeDef 	 GpioType;
	GPIO_InitTypeDef Gpio_Button;
	__GPIOA_CLK_ENABLE();

	Gpio_Button.Mode = GPIO_MODE_INPUT;
	Gpio_Button.Pin  = GPIO_PIN_0;
	Gpio_Button.Pull = GPIO_NOPULL;
	Gpio_Button.Speed = GPIO_SPEED_HIGH;
	Gpio_Button.Alternate = GPIO_MODE_AF_PP;

	//Init LED on button
	HAL_GPIO_Init(GPIOA, &Gpio_Button);
}
