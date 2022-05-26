#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int luckyNums[20] = {4, 8, 15, 16, 23, 42};

    luckyNums[10] = 100; //modifies index in array

    cout << luckyNums[0]; //access individual element of array

    return 0;
}