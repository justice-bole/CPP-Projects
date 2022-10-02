#include <iostream>
#include <random>
#include "main.h"


void gameLoop(int totalGuesses, int numberToGuess)
{
    for(int currentGuessCount = 1; currentGuessCount <= totalGuesses; currentGuessCount++)
    {
        std::cout << "Guess #" << currentGuessCount << ": ";

        int playerGuess{};
        std::cin >> playerGuess;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(playerGuess == numberToGuess)
        {
            gameOverText(true, numberToGuess);
        }
        else if (playerGuess > numberToGuess)
        {
            std::cout << "Your guess is too high!\n";
        }
        else if (playerGuess < numberToGuess)
        {
            std::cout << "Your guess is too low.\n";
        }
    }
    gameOverText(false, numberToGuess);
}

void gameOverText(bool didWin, int numberToGuess)
{
    if(didWin)
    {
        std::cout << "Correct! You win!\n";
    }
    else
    {
        std::cout << "Sorry, you lose. The correct number was " << numberToGuess << '\n';
    }

    playAgain();
}

bool playAgain()
{
    std::cout << " Would you like to play again? (y/n): ";
    char decision{};
    std::cin >> decision;

    if(decision == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int numberToGuess{Random::get(1, 100)};
    int totalGuesses{7};
    std::cout << "Let's play a game. I'm thinking of a number between 1-100. You have 7 tries to guess what it is. \n ";

    do
    {
        gameLoop(totalGuesses, numberToGuess);
    }
    while(playAgain());

    return 0;
}
