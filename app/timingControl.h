#ifndef timingControl_H
#define timing_Control_H

uint32_t getCurrentTime();
void delay(uint32_t delayCycle);
int waitWithoutDelay ( int previousTime, int delayMilliSecond);


#endif // timing_Control_H
