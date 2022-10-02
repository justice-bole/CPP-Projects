//JB
//Console app, takes two ints, returns the sum and the difference between the two numbers.

# include <iostream>


/*int multiplyNumber(int num, int multiplier)
{
    return num * multiplier;
}*/

int addNumbers(int num1, int num2)
{
    return num1 + num2;
}

int subtractNumbers(int num1, int num2)
{
    return num1 - num2;
}

int main()
{
    std::cout << "Enter an integer: ";
    int inputNumber{ };
    std::cin >> inputNumber;

    std::cout << "Enter another integer: ";
    int inputNumber2{ };
    std::cin >> inputNumber2;

    std::cout << inputNumber << " + " << inputNumber2 << " = " << addNumbers(inputNumber, inputNumber2) << '\n';
    std::cout << inputNumber << " - " << inputNumber2 << " = " << subtractNumbers(inputNumber, inputNumber2) << '\n';

    //std::cout << "Your number doubled is: " << multiplyNumber(inputNumber, 2) << '\n';
    //std::cout << "Your number tripled is: " << multiplyNumber(inputNumber, 3) << '\n';
    
    return 0;
}
