#include <iostream>
#include <iterator>
#include <utility>

void bubbleSort()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int arrayLength{std::size(array)};

    for(int iteration{0}; iteration < arrayLength - 1; ++iteration)
    {
        bool didSwap = false;
        int endOfArray{arrayLength - iteration};

        for(int index{0}; index < endOfArray - 1; ++index)
        {
            if(array[index] > array[index+1])
            {
                std::swap(array[index], array[index + 1]);
                didSwap = true;
            }
        }

        if(!didSwap)
        {
            std::cout << "Terminated early at iteration " << iteration + 1 << '\n';
            break;
        }
    }

    for(int i{0}; i < arrayLength; ++i)
    {
        std::cout << array[i] << ' ';
    }
}

int main()
{
    bubbleSort();
}

