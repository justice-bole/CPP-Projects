#include <iostream>
#include <array>
#include <numeric>

enum Items
{
    potions,
    torchs,
    arrows,
    maxitems,
};


int countTotalItems(std::array<int, Items::maxitems> &arr)
{
    return std::reduce(arr.begin(), arr.end());
}

int main()
{
    std::array<int, Items::maxitems> playerItemCount{2, 5, 10};

    std::cout << "The player has " << countTotalItems(playerItemCount) << " items in total.\n";
    std::cout << "The number of torches the player has is: " << playerItemCount[Items::arrows];
    return 0;
}
