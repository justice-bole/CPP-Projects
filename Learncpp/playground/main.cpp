//#include "SmallerAndLarger.h"
//#include <iostream>
//
//int main() {
//    int small{getInput()};
//    int large{getLargerInput()};
//
//    swapValues(small, large);
//
//    return 0;
//}

#include <iostream>

void print(int count)
{
    std::cout << count << '\n';
}

int main()
{
    int count{0};
    while(count <= 1000000)
    {
        print(count);
        ++count;
    }
    return 0;
}