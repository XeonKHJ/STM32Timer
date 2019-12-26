#include "Common.h"
#include "led.h"
#include "key.h"
#include "usart1.h"
#include "exti.h"
#include "TIM.h"

void CountDown(void);
void InitiallizeComponents(void);
void ShowMenu(void);
void CountDown(void);
void Timer(void);
int GetSelectedFuntion(void);
void StartTimer(void);
void StopTimer(void);
Time GetInitialTime(void);

int main()
{
	BOOL toExit = FALSE;
	IsTimerStoped = TRUE;
	InitiallizeComponents();
	LED_On_all();
	Delay(0xFFFFFF);
	LED_Off_all();
	while (!toExit)
	{
		if (!IsTimerStoped)
		{
			StartTimer();
			while (!IsTimerStoped);
		}
		StopTimer();
		
		ShowMenu();
		int functionNo = GetSelectedFuntion();
		switch (functionNo)
		{
		case 1:
			TimeToCount = GetInitialTime();
			TimerHandler = CountDown;
			break;
		case 2:
			InitializeTime(&TimeToCount);
			TimerHandler = Timer;
			break;
		default:
			toExit = TRUE;
		}
		IsTimerStoped = FALSE;
	}

	return 0;
}

void StartTimer()
{
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

void StopTimer()
{
	TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
}

int GetSelectedFuntion()
{
	int input;
	scanf("%d", &input);
	return input;
}

void InitiallizeComponents()
{
	StopTimer();
	LED_Config();
	KEY_Config();
	USART1_Config();
	TIM2_Config();

	//开中断
	NVIC_Config(TIM2_IRQn, 2, 0, ENABLE);
	NVIC_Config(EXTI3_IRQn, 0, 0, ENABLE);
	NVIC_Config(EXTI4_IRQn, 1, 0, ENABLE);
	

	//配置KEY的中断
	KEY_IntrConfig();
}

void ShowMenu()
{
	char menu[] = "STM32Timer\n1. CountDown\n2. Timer\nOther. Exit\n";
	DisplayContent(menu);
}

Time GetInitialTime()
{
	Time initialTime = { 0, 0, 0 };
	printf("Enter second \n");
	scanf("%d", &(initialTime.Second));
	printf("Enter minute \n");
	scanf("%d", &(initialTime.Minute));
	printf("Enter hour \n");
	scanf("%d", &(initialTime.Hour));
	return initialTime;
}

void CountDown()
{
	if (!IsTimerStoped && !IsTimeZero(TimeToCount))
	{
		MinuesOneSecond(&TimeToCount);
	}
}

void Timer()
{
	AddOneSecond(&TimeToCount);
}
