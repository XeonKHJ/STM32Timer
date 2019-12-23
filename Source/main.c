#include "Common.h"
#include "led.h"
#include "key.h"
#include "usart1.h"
#include "exti.h"

void CountDown(void);
void InitiallizeComponents(void);
void ShowMenu(void);
void CountDown(void);
void Timer(void);
int GetSelectedFuntion(void);

int main()
{
    InitiallizeComponents();
	
	while(1);
    ShowMenu();
    int functionNo = GetSelectedFuntion();
    switch (functionNo)
    {
    case 1:
        CountDown();
        break;
    case 2:
        Timer();
        break;
    }
		
		return 0;
}

int GetSelectedFuntion()
{
    int input;
    scanf("%d", &input);
    return input;
}

void InitiallizeComponents()
{
    LED_Config();
    KEY_Config();
    USART1_Config();

    //开中断
    NVIC_Config(EXTI3_IRQn, 0, 0);
    NVIC_Config(EXTI4_IRQn, 1, 0);

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
    Time initialTime = {0,0,0};
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
    TimeToCount = GetInitialTime();
    
    while (!IsTimerStoped && !IsTimeZero(TimeToCount))
    {
        MinuesOneSecond(&TimeToCount);
    }
}

void Timer()
{
    InitializeTime(&TimeToCount);
}
