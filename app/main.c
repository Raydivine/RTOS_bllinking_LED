#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define turnOnLED1()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
#define turnOffLED1()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
#define turnOnLED2()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
#define turnOffLED2()	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
#define turnOnLED3()	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
#define turnOffLED3()	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
#define turnOnLED4()	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
#define turnOffLED4()	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

#define buttonPressed() HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
#define ONE_SEC 1000
#define TWO_HUNDRED_FOURTY_MILI_SEC 240
#define ONE_HUNDRED_TWENTY_MILI_SEC 120
#define TWO_HUNDRED_MILI_SEC 200

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


void initButton(){
  //GPIO_TypeDef GpioType;
  GPIO_InitTypeDef pushButton;

  __GPIOA_CLK_ENABLE();

  pushButton.Mode = GPIO_MODE_INPUT;
  pushButton.Pin = GPIO_PIN_0;
  pushButton.Pull = GPIO_NOPULL;
  pushButton.Speed = GPIO_SPEED_HIGH;

  //GpioInfo.Alternate = GPIO_MODE_AF_PP;
  //Init LED on PA0
  HAL_GPIO_Init(GPIOA, &pushButton);
}


void initLED(){
  GPIO_InitTypeDef GpioInfo ;

  __GPIOG_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();
  __GPIOC_CLK_ENABLE();

  GpioInfo.Mode = GPIO_MODE_OUTPUT_PP ;
  GpioInfo.Pin = GPIO_PIN_13 | GPIO_PIN_14; // Init PG13 and PG14
  GpioInfo.Pull = GPIO_NOPULL ;
  GpioInfo.Speed = GPIO_SPEED_HIGH ;
  HAL_GPIO_Init(GPIOG,&GpioInfo);  //Init LED1 on PG13 , lED 2 on PG14

  GpioInfo.Pin = GPIO_PIN_13;     // Init PB13
  HAL_GPIO_Init(GPIOB,&GpioInfo); //Init LED3 on PB13

  GpioInfo.Pin = GPIO_PIN_5 ;     // Init PC5
  HAL_GPIO_Init(GPIOC,&GpioInfo); //Init LED4 on PC5
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
    	blinkLED1(&state1,ONE_HUNDRED_TWENTY_MILI_SEC);
    	blinkLED2(&state2,ONE_SEC);
    	blinkLED3(&state3,TWO_HUNDRED_MILI_SEC);
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
                          counter = 0 ; // reset the couter to 0
                       }break;

      case  LED3_ON:  if( waitWithoutDelay( previousTime,time) ){
    	  	  	  	  	  previousTime = getCurrentTime();
    	  	  	  	  	  turnOffLED3();
    	  	  	  	  	  *state = LED3_OFF;
    	  	  	  	  	  counter++;
                      }break;

      case LED3_OFF:  if( counter>= 5){
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
