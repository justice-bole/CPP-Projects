#include <iostream>

int main()
{
    constexpr std::string_view names[]{"Alex", "Betty", "Caroline", "Dave",
                                       "Emily","Fred", "Greg", "Holly"};

    std::cout << "Enter a name: ";
    std::string userName{};
    std::getline(std::cin >> std::ws, userName);

    bool foundName{false};

    for(const auto& name : names)
    {
        if(name == userName)
        {
            foundName = true;
            break;
        }
    }

    foundName ? std::cout << userName << " was found." : std::cout << userName << " was not found.";

    return 0;
}
