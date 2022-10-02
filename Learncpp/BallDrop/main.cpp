#include <iostream>

double getHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double heightM{};
    std::cin >> heightM;
    return heightM;
}

void calculateDrop(int seconds, double height)
{
    //distance fallen = gravity_constant(9.8) * x_seconds^2 / 2
    constexpr double gravity{9.8};
    const double distanceFallen = gravity * (seconds * seconds) / 2;
    const double currentHeight{height - distanceFallen};

    if(currentHeight > 0)
        std:: cout << "At " << seconds << " seconds, " << "the ball is at height: " << currentHeight << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

int main() {
    const double towerHeight{getHeight()};

    calculateDrop(0, towerHeight);
    calculateDrop(1, towerHeight);
    calculateDrop(2, towerHeight);
    calculateDrop(3, towerHeight);
    calculateDrop(4, towerHeight);
    calculateDrop(5, towerHeight);

    return 0;
}
