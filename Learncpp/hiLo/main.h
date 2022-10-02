//
// Created by Justice Bole on 8/25/22.
//
#include <iostream>
#include <random>

#ifndef HILO_MAIN_H
#define HILO_MAIN_H

namespace Random
{
    std::random_device rd;
    std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{ss};

    int get(int min, int max)
    {
        std::uniform_int_distribution randomNumber{min, max};
        return randomNumber(mt);
    }
}

void gameLoop(int totalGuesses, int numberToGuess);
void gameOverText(bool didWin, int numberToGuess);
bool playAgain();

#endif //HILO_MAIN_H
