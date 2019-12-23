#include "Common.h"
#include "led.h"
#include "key.h"
#include "usart1.h"

void CountDown();
void InitiallizeComponents();
void ShowMenu();
void CountDown();
void Timer();
int GetSelectedFuntion();

int main()
{
    InitiallizeComponents();
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