#include <iostream>

int main()
{
    std::cout << "How many names would you like to enter? ";
    int length{};
    std::cin >> length;
    std::string* names{new std::string[]{}};

    for(int i{0}; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ':';
        std::getline(std::cin >> std::ws, names[i]);
    }

    std::sort(names, names + length);

    std::cout << "Here is your sorted list: " << '\n';

    for(int k{0};k < length; ++k)
    {
        std::cout << names[k] << '\n';
    }

    delete[] names;

    return 0;
}
