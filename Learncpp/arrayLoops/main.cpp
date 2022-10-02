#include <iostream>
#include "functions.h"


void arrayIndexProgram()
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int sizeOfArray{std::size(array)};
    int userNumber{getUserInput()};
    int arrayIndex{getUserNumIndexInArray(array, sizeOfArray, userNumber)};

    printArray(array, sizeOfArray);

    std::cout << "The number " << userNumber << " has index " << arrayIndex;
}

void maxScoreProgram()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };

    int maxIndex{ 0 };

    for (int student{ 0 }; student < static_cast<int>(std::size(scores)); ++student)
    {
        if (scores[student] > scores[maxIndex])
        {
            maxIndex = student;
        }
    }

    std::cout << "The best score was " << scores[maxIndex] << '\n';
}

void sortArrayProgram()
{
    int array[]{30, 50, 20, 10, 40};
    constexpr int length{static_cast<int>(std::size(array))};

    for(int index{0}; index < length; ++index)
    {

    }
}

int main() {

    //arrayIndexProgram();
    //maxScoreProgram();

    return 0;
}
