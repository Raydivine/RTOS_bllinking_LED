#ifndef defination_H
#define defination_H

#define turnOnLED1()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
#define turnOffLED1()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
#define turnOnLED2()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
#define turnOffLED2()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
#define turnOnLED3()	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
#define turnOffLED3()	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
#define turnOnLED4()	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
#define turnOffLED4()	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
#define buttonPressed() HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

typedef enum{
	INITIAL,
	LED1_OFF,
	LED2_OFF,
	LED3_OFF,
	LED4_OFF,
	LED1_ON,
	LED2_ON,
	LED3_ON,
	LED4_ON,
	Final
}State;

typedef struct{
	State state;
}TaskBlock;

#endif defination_H
