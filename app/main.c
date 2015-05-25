#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "initLED.h"
#include  "initButton.h"
#include  "blinkLEDs.h"
#include "defination.h"

#define ONE_SEC 1000
#define THREE_SEC 3000
#define TWO_HUNDRED_FOURTY_MILI_SEC 240
#define ONE_HUNDRED_TWENTY_MILI_SEC 120
#define TWO_HUNDRED_MILI_SEC 200
#define FIVE_HUNDRED_MILI_SEC 500

#define yield(x)		 state = __LINE__; break; case __LINE__:
#define startTask(x)	 switch(state){ case 0;
#define endTask(x)		 }





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
	initLED();
	initButton();

    while(1){
    	//testNestedCase();
    	blinkLED1(&state1,ONE_HUNDRED_TWENTY_MILI_SEC);
    	blinkLED2(&state2,ONE_SEC);
    	blinkLED3(&state3,FIVE_HUNDRED_MILI_SEC);
    }
}


