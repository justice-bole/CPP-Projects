//
// Created by Justice Bole on 8/17/22.
//

#include "io.h"
#include <iostream>

int readNumber()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input;
}

void writeAnswer(int x, int y)
{
    std::cout << x << " + " << y << " = " << x + y;
}