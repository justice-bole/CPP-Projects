//Write a Fraction class that has a constructor that takes a numerator and a denominator.
// If the user passes in a denominator of 0, throw an exception of type std::runtime_error (included in the stdexcept header).
// In your main program, ask the user to enter two integers.
// If the Fraction is valid, print the fraction.
// If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.
//Here’s what one run of the program should output:
//Enter the numerator: 5
//Enter the denominator: 0
//Invalid denominator


#include <iostream>
#include <stdexcept>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int n, int d) : m_numerator{n}, m_denominator{d}
    {
        if(m_denominator == 0)
            throw std::runtime_error("Invalid Denominator");
    }

    friend std::ostream& operator<<(std::ostream& out, Fraction& f)
    {
        out << f.m_numerator << '/' << f.m_denominator;
        return out;
    }

};

int main() {
    std::cout << "Enter the numerator: ";
    int n{};
    std::cin >> n;

    std::cout << "Enter the denominator: ";
    int d{};
    std::cin >> d;

    try
    {
        Fraction f{n, d};
        std::cout << f;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what();
    }

    return 0;
}
