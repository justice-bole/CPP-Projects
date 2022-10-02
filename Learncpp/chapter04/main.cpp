#include <iostream>
#include <string>

int getNumber()
{
    std::cout << "Enter a number between 0-9: ";
    int number{};
    std::cin >> number;
    return number;
}

bool isPrime(int x)
{
    if (x == 2)
        return true;
    else if (x == 3)
        return true;
    else if (x == 5)
        return true;
    else if (x == 7)
        return true;

    return false;
}

int charConvert(char c)
{
    return c;
}

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    std::cout << "Your age + length of name is: " << std::ssize(name) + age;

    /*std::cout << "Enter a single character: ";
    char inputChar{};
    std::cin >> inputChar;
    std::cout << "You entered " << inputChar << ", which has ASCII code: " << charConvert(inputChar) << '\n';*/

    /*if(isPrime(getNumber()))
        std::cout << "Your number is prime\n";
    else
        std::cout << "Your number is not prime\n";
    std::cout << static_cast<int>(4.2);
    return 0;*/
}
