#include <iostream>

namespace animals
{
    enum Animals
    {
        chicken,
        cat,
        dog,
        elephant,
        duck,
        snake,
        maxAnimals,
    };
}

int main() {
    float highTemp[365]{ };
    int animalLegs[animals::maxAnimals]{2, 4, 4, 4, 2, 0};

    std::cout << "An elephant has " << animalLegs[animals::elephant] << " legs.";

    return 0;
}
