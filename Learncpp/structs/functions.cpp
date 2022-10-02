//
// Created by Justice Bole on 8/30/22.
//

#include <iostream>
#include "functions.h"

void calculateAndPrintRevenue(Advertising& ads)
{
    std::cout << "Ads shown: " << ads.adsShown << '\n';
    std::cout << "Percentage clicked: " << ads.percentClickedOn << "%\n";
    std::cout << "Earning per click: $" << ads.averageAdEarning << '\n';
    std::cout << "Total Revenue: $" << (ads.adsShown * ads.percentClickedOn / 100 * ads.averageAdEarning) << '\n';
}

Advertising getAdDataInput()
{
    Advertising temp;
    std::cout << "Ads shown: ";
    std::cin >> temp.adsShown;

    std::cout << "Percentage clicked: ";
    std::cin >> temp.percentClickedOn;

    std::cout << "Average ad earning: ";
    std::cin >> temp.averageAdEarning;

    return  temp;
}

Fraction getFractionInput()
{
    Fraction temp{};
    std::cout << "Enter numerator: ";
    std::cin >> temp.numerator;

    std::cout << "Enter denominator: ";
    std::cin >> temp.denominator;

    return temp;
}

Fraction multiplyFractions(const Fraction& f1, const Fraction &f2)
{
    return {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

void printFraction(const Fraction& f)
{
    std::cout << "Your fraction multiplied together: " << f.numerator << "/" << f.denominator << '\n';
}