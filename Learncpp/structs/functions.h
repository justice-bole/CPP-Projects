//
// Created by Justice Bole on 8/30/22.
//

#ifndef STRUCTS_FUNCTIONS_H
#define STRUCTS_FUNCTIONS_H

// STRUCTS -----------------------------
struct Advertising
{
    int adsShown{0};
    float percentClickedOn{0};
    float averageAdEarning{0};
};

struct Fraction
{
    int numerator{0};
    int denominator{1};
};

//FUNCTIONS -----------------------------
Advertising getAdDataInput();
void calculateAndPrintRevenue(Advertising& ads);

Fraction getFractionInput();
Fraction multiplyFractions(const Fraction& f1, const Fraction &f2);
void printFraction(const Fraction& f);

#endif //STRUCTS_FUNCTIONS_H
