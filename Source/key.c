#include "key.h"
#include "Common.h"
//初始化KEY
void KEY_Config()
{
	//初始化Key0（连接着PE4）
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	//初始化KEY1（连接着PE3）
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

void Key1Release()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_4);
}

void Key2Release()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_3);
}
