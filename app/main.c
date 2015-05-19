#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initGPIO.h"

#define turnOnLED1()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
#define turnOffLED1()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
#define turnOnLED2()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
#define turnOffLED2()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
#define turnOnLED3()	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
#define turnOffLED3()	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
#define turnOnLED4()	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
#define turnOffLED4()	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
//#define ButtonPressed() HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

#define ONE_SEC 1000
#define TWO_HUNDRED_FORTY_MILI_SEC 240
#define ONE_HUNDERED_TWENTY_MILI_SEC 120

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

uint32_t getCurrentTime(){
	static uint32_t counter = 0;
	static uint32_t currentTime = 0;

	if(counter++ >= 100){
		counter = 0;
		currentTime++;
	}

	return currentTime;
}

void delay(uint32_t delayCycle){
	static uint32_t previousTime = 0;

	while( (getCurrentTime() - previousTime) < delayCycle);
		previousTime = getCurrentTime();
}

int waitWithoutDelay ( int previousTime, int delayMilliSecond){
	if(getCurrentTime() - previousTime > delayMilliSecond)
		return 1;
	return 0;
}

int main(void){
	static *state1 = INITIAL, *state2 = INITIAL, *state3 = INITIAL, *state4 = INITIAL;
	initLED1();
	initLED2();
	initUserButton();

    while(1){
    	blinkLED1(&state1,TWO_HUNDRED_FORTY_MILI_SEC);
    	blinkLED2(&state2,ONE_SEC);
    }
}

void blinkLED1(State *state, int time){
	static int previousTime = 0 ;

	switch (*state){
		case INITIAL: 	turnOffLED1();
						*state = LED1_OFF;
						break;

		case LED1_OFF:	if( waitWithoutDelay( previousTime,time) ){
							previousTime = getCurrentTime();
							turnOffLED1();
							*state = LED1_ON;
						}
							break;

		case LED1_ON:	if( waitWithoutDelay( previousTime,time) ){
							previousTime = getCurrentTime();
							turnOnLED1();
							*state = LED1_OFF;
						}break;

		default: 		break;
	}
}

void blinkLED2(State *state, int time){
	static int previousTime = 0 ;

	switch (*state){
		case INITIAL: 	turnOffLED2();
						*state = LED2_OFF;
						break;

		case LED2_OFF:	if( waitWithoutDelay( previousTime,time) ){
							previousTime = getCurrentTime();
							turnOffLED2();
							*state = LED2_ON;
						}break;

		case LED2_ON:	if( waitWithoutDelay( previousTime,time) ){
							previousTime = getCurrentTime();
							turnOnLED2();
							*state = LED2_OFF;
						}break;

		default: 		break;
	}
}


void blinkLED3(State *state){
	static int previousTime = 0 ;

	//if(ButtonPressed()){

	//}
}


