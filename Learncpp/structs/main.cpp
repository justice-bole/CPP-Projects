#include "functions.h"

//asks user for three variables: ads shown, ads clicked, and average earning per ad clicked.
//these three variables are multiplied together to give a total ad revenue earning which is output to the console.
void adProgram()
{
    Advertising data{getAdDataInput()};
    calculateAndPrintRevenue(data);
}

//asks user for two fractions then multiplies them together returning the product as a fraction to the console.
//the output fraction is not reduced
void fractionProgram()
{
    Fraction f1{getFractionInput()};
    Fraction f2{getFractionInput()};
    Fraction fProduct{multiplyFractions(f1, f2)};
    printFraction(fProduct);
}

int main() {
    //comment out a program to skip/disable it
     adProgram();
     fractionProgram();

    return 0;
}
