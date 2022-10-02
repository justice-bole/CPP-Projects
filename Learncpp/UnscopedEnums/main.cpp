#include <iostream>
#include <string_view>
#include "monster.h"
#include "Animal.h"


constexpr std::string_view getAnimalName(Animal animal)
{
    using enum Animal;
    switch(animal)
    {
        case pig: return "pig";
        case chicken: return "chicken";
        case goat: return "goat";
        case cat: return "cat";
        case dog: return "dog";
        case duck: return "duck";
        default: return "Error: No case found for getAnimalName()";
    }
}

void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";
    using enum Animal;
    switch(animal)
    {
        case pig:
        case goat:
        case cat:
        case dog:
            std::cout << 4;
            break;
        case chicken:
        case duck:
            std::cout << 2;
            break;
        default:
            std::cout << "Error: No case found for getAnimalName()";
    }
    std::cout << " legs.\n";
}


int main() {
    monster::MonsterType monster{ monster::troll };
    std::cout << monster << '\n';
    Color shirt{Color::red};
    std::cout << static_cast<int>(shirt) << '\n';
    printNumberOfLegs(Animal::goat);
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}
