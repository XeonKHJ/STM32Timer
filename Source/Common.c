#include "Common.h"

Time TimeToCount = {0, 0, 0};
int IsTimerStoped = 0;
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