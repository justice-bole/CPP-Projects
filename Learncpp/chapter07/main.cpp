#include <iostream>

void asciiChart()
{
    int count=97;
    while(count <= 122)
    {
        std::cout << count << ": " << static_cast<char>(count) << '\n';
        ++count;
    }
}

void invertLoop() // my solution
{
    int outer{1};
    while (outer <= 5)
    {
        int spaces(5 - outer);
        while(spaces > 0)
        {
            std::cout << "  ";
            --spaces;
        }

        int inner{outer};
        while(inner >= 1)
        {
            std::cout << inner-- << ' ';
        }

        std::cout << '\n';
        ++outer;
    }
}

void invertLoop_V2() // reference solution
{
    int outer{ 1 };
    while (outer <= 5)
    {
        int inner{ 5 };
        while (inner >= 1)
        {
            if (inner <= outer)
                std::cout << inner << ' ';
            else
                std::cout << "  ";

            --inner;
        }

        std::cout << '\n';

        ++outer;
    }

}

void evenNumbersTo20()
{
    for(int i{2}; i <= 20; i+=2)
        std::cout << i << '\n';
}

int sumTo(int x) //my solution
{
    int total{0};
    for( ; x > 0; x--)
    {
        total += x;
    }

    return total;
}

int sumTo_V2(int value) //reference solution
{
    int total{ 0 };
    for (int count{ 1 }; count <= value; ++count)
        total += count;

    return total;
}

int main()
{
    std::cout << sumTo(5);
    return 0;
}
