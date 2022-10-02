#include <iostream>
#include <numeric> // for std::gcd

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator=0, int denominator=1):
            m_numerator{numerator}, m_denominator{denominator}
    {
        // We put reduce() in the constructor to ensure any new fractions we make get reduced!
        // Any fractions that are overwritten will need to be re-reduced
        reduce();
    }

    void reduce()
    {
        int gcd{ std::gcd(m_numerator, m_denominator) };
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    friend std::istream& operator>>(std::istream& in, Fraction& f);

    friend bool operator== (const Fraction& c1, const Fraction& c2);
    friend bool operator!= (const Fraction& c1, const Fraction& c2);

    friend bool operator< (const Fraction& c1, const Fraction& c2);
    friend bool operator> (const Fraction& c1, const Fraction& c2);

    friend bool operator<= (const Fraction& c1, const Fraction& c2);
    friend bool operator>= (const Fraction& c1, const Fraction& c2);

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction& f1, int value)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction& f1)
{
    return Fraction(f1.m_numerator * value, f1.m_denominator);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.m_numerator << '/' << f.m_denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    in >> f.m_numerator;
    in >> f.m_denominator;

    return in;
}

bool operator== (const Fraction& c1, const Fraction& c2)
{
    return (c1.m_numerator == c2.m_numerator) && (c1.m_denominator == c2.m_denominator);
}

bool operator!= (const Fraction& c1, const Fraction& c2)
{
    return !(operator==(c1, c2));
}

bool operator< (const Fraction& c1, const Fraction& c2)
{
    return c1.m_numerator * c2.m_denominator < c2.m_numerator * c1.m_denominator;
}

bool operator> (const Fraction& c1, const Fraction& c2)
{
    return operator<(c2, c1);
}

bool operator<= (const Fraction& c1, const Fraction& c2)
{
    return !(operator>(c1, c2));
}

bool operator>= (const Fraction& c1, const Fraction& c2)
{
    return !(operator<(c1, c2));
}


int main()
{
    Fraction f1{ 3, 2 };
    Fraction f2{ 5, 8 };

    std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
    std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
    std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
    std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
    std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
    std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
    return 0;
}