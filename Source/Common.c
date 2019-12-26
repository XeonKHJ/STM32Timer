#include "Common.h"
#include "stdlib.h"

Time TimeToCount = {0, 0, 0};
int IsTimerStoped = 0;
void (* TimerHandler)();
int IsTimeZero(Time time)
{
    if (TimeToCount.Hour == 0 &&
        TimeToCount.Minute == 0 &&
        TimeToCount.Second == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void MinuesOneSecond(Time * timePtr)
{
    if (timePtr->Second != 0)
    {
        (timePtr->Second) -= 1;
    }
    else if (timePtr->Minute != 0)
    {
        (timePtr->Minute) -= 1;
        (timePtr->Second) = 59;
    }
    else if (timePtr->Hour != 0)
    {
        (timePtr->Hour) -= 1;
        timePtr->Second = 59;
        timePtr->Minute = 59;
    }
}

void AddOneSecond(Time * timePtr)
{
    if(timePtr->Second != 59)
    {
        ++(timePtr->Second);
    }
    else if(timePtr->Minute != 59)
    {
        ++(timePtr->Minute);
        timePtr->Second = 0;
    }
    else if(timePtr->Hour != 59)
    {
        ++(timePtr->Hour);
        timePtr->Second = 0;
        timePtr->Minute = 0;
    }
}

void InitializeTime(Time * timePtr)
{
    timePtr->Hour = 0;
    timePtr->Minute = 0;
    timePtr->Second = 0;
}

void DisplayContent(char * content)
{
    printf(content);
}

void TimeToString(Time time, char* time_char) {
	char temp;
	int p = time.Hour / 10;
	p = p + 0x30;
	temp = p;
	time_char[0] = temp;

	p = time.Hour % 10;
	p = p + 0x30;
	temp = p;
	time_char[1] = temp;

	time_char[2] = ':';

	p = time.Minute / 10;
	p = p + 0x30;
	temp = p;
	time_char[3] = temp;

	p = time.Minute % 10;
	p = p + 0x30;
	temp = p;
	time_char[4] = temp;

	time_char[5] = ':';

	p = time.Second / 10;
	p = p + 0x30;
	temp = p;
	time_char[6] = temp;

	p = time.Second % 10;
	p = p + 0x30;
	temp = p;
	time_char[7] = temp;

	time_char[8] = 0;
}