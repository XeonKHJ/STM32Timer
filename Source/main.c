#include "Common.h"

void CountDown();

int main()
{
    ShowMenu();
    int functionNo = GetSelectedFuntion();
    switch (functionNo)
    {
    case 1:
        CountDown();
        break;
    case 2:
        Timer();
    default:
        Exit();
    }
}

void CountDown()
{
    InitalCount = GetInitialTime();
    
}