#include <string>
#include <iostream>
#include <cassert>

class MyString
{
private:
    std::string m_string{};

public:
    MyString(const std::string& str = {}) : m_string{str} {}
    std::string operator()(int index, int length);

};

std::string MyString::operator()(int index, int length)
{
    assert(index >= 0);
    assert(index + length < static_cast<int>(m_string.length()) && "MyString::operator()(int, int): Substring is out of range");
    return m_string.substr(index, length);
}

int main()
{
    MyString string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
