#ifndef __COMMON_H
#define __COMMON_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"

typedef struct Time
{
    int Hour;
    int Minute;
    int Second;
}Time;

extern int IsTimerStoped;
extern Time TimeToCount;

void AddOneSecond(Time * timePtr);
void MinuesOneSecond(Time * timePtr);
void DisplayContent(char * content);
void InitializeTime(Time * timePtr);

#endif
