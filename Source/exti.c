#include "exti.h"
#include "Common.h"

void NVIC_Config(uint8_t iRQChannel, uint8_t PreemptionPriority, uint8_t SubPriority)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = iRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PreemptionPriority; //缁勪紭鍏堢骇涓?
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = SubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
