#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << "\n";
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight {};
    int timeOut{999};
    std::cin >> initialHeight;
    for(int i = 0; i < timeOut; i++)
    {
        if(calculateHeight(initialHeight, i))
        {
            calculateAndPrintHeight(initialHeight, i);
        }
        else
        {
            calculateAndPrintHeight(initialHeight, i);
            break;
        }
    }



    return 0;
}