#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "blinkLED2.h"
#include "defination.h"

void blinkLED2AndControlSpeedByButton(State *state){
	static int previousTime = 0 , time = 0;
	
	switch (*state){
		case INITIAL: 	turnOffLED2();
                    	*state = LED2_OFF;
                    	break;

		case LED2_OFF:	time = selectTheDelayValueByPressedButton();
    
                    	if( waitWithoutDelay( previousTime,time) ){
                    		previousTime = getCurrentTime();
                    		turnOnLED2();
                    		*state = LED2_ON;
                    	}
                    	break;

		case LED2_ON:	time = selectTheDelayValueByPressedButton();
                    
                  	  	if( waitWithoutDelay( previousTime,time) ){
                  	  		previousTime = getCurrentTime();
                  	  		turnOffLED2();
                  	  		state = LED2_OFF;
                  	  	}
                  	  	break;

		default: 		break;
	}
}

int selectTheDelayValueByPressedButton(){
	GPIO_PinState readButton ;
	readButton = buttonPressed();

	if(readButton ==1)
		return ONE_HUNDRED_MILI_SEC;
	else
		return ONE_SEC;
}




