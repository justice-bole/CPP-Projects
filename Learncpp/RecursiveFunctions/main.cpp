#include <iostream>

int factorial(int x)
{
    if(x <= 0)
        return 1;
    return factorial(x - 1) * x;
}

int sumofEach(int x)
{
    if(x < 10)
    {
        return x;
    }
    return sumofEach(x / 10) + x % 10;
}

void decimalToBinary(unsigned int x)
{
    if(x > 1)
    {
        decimalToBinary(x / 2);
    }

    std::cout << x % 2;

}

int main()
{
    std::cout << factorial(5) << '\n';
    std::cout << sumofEach(93427) << '\n';

    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;
    decimalToBinary(static_cast<unsigned int>(x));

    return 0;
}
