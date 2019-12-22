#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

void LED_Config(void);
void LED_On_all(void);
void LED_Off_all(void);
void LED_On(uint8_t led);
void LED_Off(uint8_t led);
void Delay(__IO uint32_t nCount);

#endif
