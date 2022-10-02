#include <iostream>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double d{};
    std::cin >> d;
    return d;
}

char getSign()
{
    std::cout << "Enter one of the following: +, -, *, or /:";
    char c{};
    std::cin >> c;
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return c;

}

double calculateAnswer(double x, double y, char c)
{
    if(c == '+')
        return x + y;
    else if(c == '-')
        return x - y;
    else if (c == '*')
        return x * y;
    else if (c == '/')
        return x / y;
}

int main() {
    double x { getDouble() };
    double y { getDouble() };
    char c { getSign() };

    if(c != 'x')
        std::cout << x << " " << c << " " <<  y << " is " << calculateAnswer(x, y, c);
    return 0;
}
