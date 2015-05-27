#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "blinkLED1.h"
#include "timingControl.h"
#include "initButton.h"
#include "defination.h"

void blinkLED1(State *state, int time){
	static int previousTime = 0 ;

	switch (*state){
		case INITIAL: 	turnOffLED1();
						*state = LED1_OFF;
						break;

		case LED1_OFF:	if( waitWithoutDelay( previousTime,time) ){
							previousTime = getCurrentTime();
							turnOnLED1();
							*state = LED1_ON;
						}
						break;

		case LED1_ON:	if( waitWithoutDelay( previousTime,time) ){
							previousTime = getCurrentTime();
							turnOffLED1();
							*state = LED1_OFF;
						}
						break;

		default: 		break;
	}
}

