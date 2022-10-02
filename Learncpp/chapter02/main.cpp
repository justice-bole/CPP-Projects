//gets user input (int) then doubles it and outputs it to console
//JB

#include "add.h"
#include <iostream>

void promptUser()
{
    std::cout << "Enter an Integer: ";
}

int getInput()
{
    int input{};
    std::cin >> input;
    return input;
}

int doubleInput(int input)
{
    return input * 2;
}

void outputAnswer()
{
    std::cout << doubleInput(getInput()) << '\n';
}

int main() {
    promptUser();
    outputAnswer();
    std::cout << add(1, 1);
    return 0;
}
