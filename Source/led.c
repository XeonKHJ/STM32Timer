#include "led.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

void LED_Config(void)
{
	//启动外设GPIOB和GPIOE的外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);
	
	//定义一个用于初始化的GPIO_InitTypeDef结构体实例
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	
	//用GPIO_InitStructure来初始化CPIOB和GPIOE端口
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	//将GPIOB和GPIOE置为（即将灯关了）
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
	GPIO_SetBits(GPIOE, GPIO_Pin_5);
}

//LED全亮
void LED_On_all()
{
	//即将GPIOB和GPIOE置位
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	GPIO_ResetBits(GPIOE, GPIO_Pin_5);
}

void LED_Off_all()
{
	GPIO_SetBits(GPIOB, GPIO_Pin_5);
	GPIO_SetBits(GPIOE, GPIO_Pin_5);
}

void LED_On(uint8_t led)
{
	switch(led)
	{
		case 0:
			GPIO_ResetBits(GPIOB, GPIO_Pin_5);
			break;
		case 1:
			GPIO_ResetBits(GPIOE, GPIO_Pin_5);
			break;
		default:
			break;
	}
}

void LED_Off(uint8_t led)
{
	switch(led)
	{
		case 0:
			GPIO_SetBits(GPIOB, GPIO_Pin_5);
			break;
		case 1:
			GPIO_SetBits(GPIOE, GPIO_Pin_5);
			break;
		default:
			break;
	}
}

void Delay(__IO uint32_t nCount)
{
	for(; nCount != 0; --nCount);
}
