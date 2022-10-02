#include <iostream>
#include <array>
#include "functions.h"


int main()
{
    auto deck{createDeck()};
    shuffleDeck(deck);

    if(playBlackjack(deck))
    {
        std::cout << "You win! Congratulations! \n";
    }
    else
    {
        std::cout << "Sorry, you lose! Better luck next time! \n";
    }

    return 0;
}
