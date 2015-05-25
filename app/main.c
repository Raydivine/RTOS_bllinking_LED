#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initLED.h"
#include "initButton.h"
#include "blinkLEDs.h"
#include "defination.h"
#include "timingControl.h"

/*
void testNestedCase(){
	static int state =0, here =0;

	startTask();
			    here =1;
				yield();
				state = 3;
				yield();
				here =3;

}
*/

void testCase(){
	static int state = 0, here =0;

	switch(state){

	case 1:	here =1;
			state =2;
			break;

	case 2: here =2;
			state = 3;
			break;

	case 3: here =3;
			break;
	default:	break;

	}
}

int main(void){
	static *state1 = INITIAL, *state2 = INITIAL, *state3 = INITIAL, *state4 = INITIAL;

	initLED();
	initButton();

    while(1){

    	blinkLED1(&state1,ONE_HUNDRED_TWENTY_MILI_SEC);
    	blinkLED2(&state2);
    	blinkLED3(&state3,FIVE_HUNDRED_MILI_SEC);
    }
}


