#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initLED.h"
#include "initButton.h"
#include "blinkLED1.h"
#include "blinkLED2.h"
#include "blinkLED3.h"
#include "defination.h"
#include "timingControl.h"

int main(void){
	State state1 = INITIAL, state2 = INITIAL, state3 = INITIAL;

	initLED();
	initButton();

    while(1){
    	blinkLED1( &state1,ONE_HUNDRED_TWENTY_MILI_SEC );
    	blinkLED2AndControlSpeedByButton( &state2 );
    	blinkLED3FiveTimesWhenButtonPressed( &state3,TWO_HUNDRED_MILI_SEC);
    }
}


