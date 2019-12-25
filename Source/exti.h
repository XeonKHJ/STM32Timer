#pragma once

#include "stm32f10x.h"
void NVIC_Config(uint8_t iRQChannel, uint8_t PreemptionPriority, uint8_t SubPriority, int status);
