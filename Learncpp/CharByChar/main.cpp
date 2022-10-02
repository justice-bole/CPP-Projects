#include <iostream>

void printEachChar(const char* str)
{
    while(*str != '\0')
    {
        std::cout << *str << '\n';
        ++str;
    }
}

int main()
{
    const char* str{"Hello, world!"};
    printEachChar(str);

    return 0;
}
