//
// Created by Justice Bole on 8/31/22.
//
#include <iostream>
#include "functions.h"

int getUserInput()
{
    int number{};

    do
    {
        std::cout << "Enter a number between 1-9: ";
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }

    } while(number > 9 || number < 1);

    return number;
}

int getUserNumIndexInArray(const int array[], const int sizeOfArray, int userNumber)
{
    for(int index{ 0 }; index < sizeOfArray; ++index)
    {
        if(array[index] == userNumber)
        {
            return index;
        }
    }

    return 1;
}

void printArray(const int array[], const int sizeOfArray)
{
    for(int index{ 0 }; index < sizeOfArray; ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';
}