#include <iostream>

int calculate(int x, int y, char c)
{
    switch(c)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '%':
            return x % y;
        default:
            std::cerr << "calculate(): Unhandled Case\n";
    }
}

int main()
{
    std::cout << calculate(2, 77, '-') << '\n';
    return 0;
}
