#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "blinkLED3.h"
#include "timingControl.h"
#include "initButton.h"
#include "defination.h"

void blinkLED3FiveTimesWhenButtonPressed(State *state, int time){
	static int previousTime = 0 ;
	static int counter = 0 ;

	switch (*state){
			case  INITIAL:	turnOffLED3();

							if(counter>5){
			                   *state = INITIAL;
			                    break;
			                }

			                if( ButtonIsPressed())
			                	*state = LED3_OFF;
			                else *state = INITIAL;
			                break;

			case LED3_OFF:	if( ButtonIsNotPressed())
                      	  		break;
                      
							if(counter>=5){     //During off state,  counter equal of 5 times means LED3 blinked 5 times
			                	*state = INITIAL;
			                	break;
			                }
      
                      	  	if( waitWithoutDelay( previousTime,time) ){
                      	  		previousTime = getCurrentTime();
                      	  		turnOnLED3();
                      	  		*state = LED3_ON;
                      	  		counter++;
                      	  		break;
                      	  	}

                      
			case  LED3_ON:	if( ButtonIsNotPressed()){
								*state = LED3_OFF;
								break;
							}

							if(counter>5){   //During on state,  counter more than 5 means blinked 5 times
			                	*state = INITIAL;
			                	break;
			                }
                      
							if( waitWithoutDelay( previousTime,time) ){
								previousTime = getCurrentTime();
								turnOffLED3();
								*state = LED3_OFF;
								break;
							}

			default: 		break;
		}
}

int ButtonIsNotPressed(){

	GPIO_PinState readButton ;
	readButton = buttonPressed();

	if(readButton == 0 )
		return 1;
	return 0;
}

int ButtonIsPressed(){

	GPIO_PinState readButton ;
	readButton = buttonPressed();

	if(readButton == 1 )
		return 1;
	return 0;
}

