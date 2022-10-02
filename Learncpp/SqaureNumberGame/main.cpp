#include <cmath>
#include <iostream>
#include <vector>
#include <random>

//Get starting number
int getNumber()
{
    std::cout << "Choose a number to start at: ";
    int number{};
    std::cin >> number;
    return number;
}

//get array length
int getLength()
{
    std::cout << "How many numbers after your chosen number do you want to include? ";
    int length{};
    std::cin >> length;
    return length;
}

//generate a random number between 2-4
int genRanNum()
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution randomNumber{2, 4};
    return randomNumber(mt);
}

//create array of squared numbers starting from start number, until array is user length
//multiply each element in array by earlier random generated number
std::vector<int> populateArray(int startNum, const int length, const int multiplier)
{
    std::vector<int> numbers(static_cast<std::size_t>(length));
    for(std::size_t i{0}; i < static_cast<std::size_t>(length); ++i)
    {
        numbers[i] = (startNum * startNum) * multiplier;
        ++startNum;
    }
    return numbers;
}

//ask for user to guess number
int getUserGuess()
{
    std::cout << "> ";
    int input{};
    std::cin >> input;
    return input;
}

//check if user guess is correct - continue if so - end if not
void play(std::vector<int>& array)
{
    while(true)
    {
        const int guess{getUserGuess()};
        auto closest{*std::min_element(array.begin(), array.end(), [=](int a, int b){
            return (std::abs(a - guess) < std::abs(b - guess));})};
        auto found{std::find(array.begin(), array.end(), guess)};

        if(found == array.end())
        {
            std::cout << guess << " is wrong! Try " << closest << " next time\n";
            break;
        }
        else
        {
            array.erase(found);
            std::cout << "Nice! " << std::size(array) << " number(s) left.\n";
        }

        if(std::size(array) == 0)
        {
            std::cout << "Congratulations! You found every number!\n";
            break;
        }
    }
}
//return correct answer if guessed answer was close

int main()
{
    //preamble
    std::cout << "Choose a number to start with, then an amount.\n"
                 "I'll square your number by 2, and every number after depending on the amount.\n"
                 "I'll then multiply each number by 2, 3, or 4. You must guess every number to win.\n";

    const int startNum{getNumber()};
    const int length{getLength()};
    const int multiplier(genRanNum());
    std::vector<int> numbersSquared{populateArray(startNum, length, multiplier)};

    std::cout << "I generated " << length
    << " square numbers. Starting from " << startNum <<  ". Do you know what each number is after multiplying it by " << multiplier << "?\n";

    play(numbersSquared);

    return 0;
}

// double max(double x, double y);
