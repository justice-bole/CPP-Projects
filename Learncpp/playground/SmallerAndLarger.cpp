//
// Created by Justice Bole on 8/23/22.
//

#include "SmallerAndLarger.h"
#include <iostream>

int getInput()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input;
}

int getLargerInput()
{
    std::cout << "Enter a larger integer: ";
    int input{};
    std::cin >> input;
    return input;
}

void swapValues(int small, int large)
{
    std::cout << "Swapping the values \n";
    if(small > large)
    {
        int placeholder{large};
        large = small;
        small = placeholder;
        printResults(small, large);
        return;
    }
    printResults(small, large);
}

void printResults(int s, int l)
{
    std::cout << "The smaller value is " << s << '\n';
    std::cout << "The larger value is " << l << '\n';
}

