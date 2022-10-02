#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int getInteger()
{
    std::cout << "Enter an integer: ";
    int temp{};
    std::cin >> temp;
    return temp;
}

char getOperator()
{
    char op{};

    do
    {
        std::cout << "Enter a sign (+ - * /): ";
        std::cin >> op;
    }
    while(op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char op)
{
    switch(op)
    {
        case '+':   return &add;
        case '-':   return &subtract;
        case '*':   return &multiply;
        case '/':   return &divide;
    }

    return nullptr;
}

int main() {
    int x{getInteger()};
    char op{getOperator()};
    int y{getInteger()};
    ArithmeticFunction fcn{getArithmeticFunction(op)};
    std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x,y);

    return 0;
}
