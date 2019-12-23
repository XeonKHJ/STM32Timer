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

void KEY_IntrConfig()
{
	EXTI_InitTypeDef EXTI_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);

	//指明EXTI线
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	//指明工作模式
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	//指明触发有效边缘
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	//允许中断
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);


	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	//指明EXTI线
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	//指明工作模式
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	//指明触发有效边缘
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	//允许中断
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void Key1Release()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_4);
}

void Key2Release()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_3);
}
