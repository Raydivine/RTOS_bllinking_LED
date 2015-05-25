#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "blinkLEDs.h"
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
							turnOnLED2();
							*state = LED2_ON;
						}break;

		case LED2_ON:	if( waitWithoutDelay( previousTime,time) ){
							previousTime = getCurrentTime();
							turnOffLED2();
							*state = LED2_OFF;
						}break;

		default: 		break;
	}
}

void blinkLED3(State *state, int time){
	static int previousTime = 0 ;
	static int counter = 0 ;

	GPIO_PinState readButton ;
	readButton = buttonPressed()

    switch (*state){
      case  INITIAL:   if(readButton == 1 ){
                          turnOnLED3();
                          *state = LED3_ON;
                          counter = 0 ; // reset the counter to 0
                       }break;

      case  LED3_ON:  if( waitWithoutDelay( previousTime,time) ){
    	  	  	  	  	  previousTime = getCurrentTime();
    	  	  	  	  	  turnOffLED3();
    	  	  	  	  	  *state = LED3_OFF;
    	  	  	  	  	  counter++;

                      }break;

      case LED3_OFF:  if( counter> 5){
    	  	  	  	  	  *state = INITIAL;
    	  	  	  	  	  break;
      	  	  	  	  }
                      if( waitWithoutDelay( previousTime,time) ){
                    	  previousTime = getCurrentTime();
                    	  turnOnLED3();
                    	  *state = LED3_ON;
                      }break;

      default: 		break;
    }
}
