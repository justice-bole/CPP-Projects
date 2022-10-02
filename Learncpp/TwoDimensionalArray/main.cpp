#include <iostream>

void multiplicationTable()
{
    constexpr int numRow{10};
    constexpr int numColumn{10};
    int array[numRow][numColumn]{};

    for(int row{1}; row < numRow; ++row)
    {
        for( int column{1}; column < numColumn; ++column)
        {
            array[row][column] = row * column;
        }
    }

    for(int iteration{1}; iteration < numRow; ++iteration)
    {
        for(int insideIteration{1}; insideIteration < numColumn; ++insideIteration)
        {
            std::cout << array[iteration][insideIteration] << '\t';
        }

        std::cout << '\n';
    }
}

void getAndPrintName()
{
    char text[255] {};
    std::cout << "What's your name? ";
    std::cin.getline(text, std::size(text));
    std::cout << text << '\n';
}

int main()
{
    int array[5]{1, 2, 3, 4, 5};
    std::cout << array << '\n';
    std::cout << &array << '\n';
    //getAndPrintName();
    multiplicationTable();
    return 0;
}
