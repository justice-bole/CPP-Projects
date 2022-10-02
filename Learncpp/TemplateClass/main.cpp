#include <iostream>

template <typename T>
class Pair1
{
private:
    T m_num1{};
    T m_num2{};

public:
    Pair1(const T& num1, const T& num2) : m_num1{num1}, m_num2{num2}
    {
    }
    T first() { return m_num1; }
    T second() { return m_num2; }
    const T first() const { return m_num1; }
    const T second() const { return m_num2; }

};

template <typename T, typename S>
class Pair
{
private:
    T m_num1{};
    S m_num2{};

public:
    Pair(const T& num1, const S& num2) : m_num1{num1}, m_num2{num2}
    {
    }
    T& first() { return m_num1; }
    S& second() { return m_num2; }
    const T& first() const { return m_num1; }
    const S& second() const { return m_num2; }

};

template <typename S>
class StringValuePair : public Pair<std::string, S>
{
public:
    StringValuePair(const std::string& key, const S& value)
            : Pair<std::string, S> { key, value }
    {
    }
};


int main()
{
    StringValuePair<int> svp { "Hello", 5 };
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
