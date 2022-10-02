#include <iostream>

int getInput()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

bool isEven(int x)
{
    return (x % 2 == 0);
}

void printResult(bool t, int x)
{
    if(t)
        std::cout << x << " is even.\n";
    else
        std::cout << x << " is odd.\n";
}

int main() {
    int num{getInput()};
    printResult(isEven(num), num);
    std::cout << 7 / 4;
    return 0;
}