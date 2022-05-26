#include <iostream>
#include <cmath> //imported math functions

using namespace std;

int main()
{
    //cmath functions

    cout << pow(2, 5) << endl; // 2 to the power of 5
    cout << sqrt(36) << endl; //square root of 36
    cout << round(4.6) << endl; //rounds normal
    cout << ceil(4.1) <<endl; //always rounds UP to whole number ie 5
    cout << floor(4.9) << endl; // always rounds DOWN to whole number ie 4
    cout << fmax(3, 10) << endl; // returns largest of the two numbers ie 10
    cout << fmin(3, 10) <<endl; // returns smalles of the two numbers ie 3


    // regular math - dont need cmath
    int wnum = 5;
    double dnum = 5.5;

    wnum++; //increments
    // wnum--
    // wnum += -= ==

    cout << wnum << endl;

    cout << 40 << endl; // print number plain
    cout << 7 - 4 << endl; //subtraction
    cout << 5 + 7 << endl; //addition
    cout << 4 * 8 << endl; // multiplication
    cout << 10.0 / 3.0 << endl; //division
    cout << 10 % 3 << endl; //modulous or remainder
    //PEMDAS order of operations in math
    //integer and integer always returns integer

    return 0;
    
}
