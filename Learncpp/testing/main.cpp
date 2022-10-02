#include <iostream>

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents) : m_cents{cents} {}
    int getCents() const { return m_cents;}
    friend Cents operator+(const Cents& c1, const Cents& c2);
};

Cents operator+(const Cents& c1, const Cents& c2)
{
    return Cents{c1.m_cents + c2.m_cents};
}

int main() {
    Cents cent1{2};
    Cents cent2{3};
    Cents cent3{cent1 + cent2};
    std::cout << cent3.getCents();
    return 0;
}
