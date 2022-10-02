#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <random>
#include <unistd.h>

#include "functions.h"

constexpr int g_maxScore{21};
constexpr int g_minimumDealerScore{17};

void printCard(const Card& card)
{
    switch(card.rank)
    {
        case CardRank::rank_two:    std::cout << '2'; break;
        case CardRank::rank_three:  std::cout << '3'; break;
        case CardRank::rank_four:   std::cout << '4'; break;
        case CardRank::rank_five:   std::cout << '5'; break;
        case CardRank::rank_six:    std::cout << '6'; break;
        case CardRank::rank_seven:  std::cout << '7'; break;
        case CardRank::rank_eight:  std::cout << '8'; break;
        case CardRank::rank_nine:   std::cout << '9'; break;
        case CardRank::rank_ten:    std::cout << 'T'; break;
        case CardRank::rank_Jack:   std::cout << 'J'; break;
        case CardRank::rank_Queen:  std::cout << 'Q'; break;
        case CardRank::rank_King:   std::cout << 'K'; break;
        case CardRank::rank_Ace:    std::cout << 'A'; break;
        default:                    std::cout << '?'; break;
    }

    switch(card.suit)
    {
        case CardSuit::club:        std::cout << 'C'; break;
        case CardSuit::diamond:     std::cout << 'D'; break;
        case CardSuit::heart:       std::cout << 'H'; break;
        case CardSuit::spade:       std::cout << 'S'; break;
        default:                    std::cout << '?'; break;
    }
}

deck_type createDeck()
{
    deck_type deck{};
    size_t index{0};
    for(size_t suit{0}; suit < static_cast<size_t>(CardSuit::maxsuit); ++suit)
    {
        for(size_t rank{0}; rank < static_cast<size_t>(CardRank::maxrank); ++rank)
        {
            deck[index].suit = static_cast<CardSuit>(suit);
            deck[index].rank = static_cast<CardRank>(rank);
            ++index;
        }
    }
    return deck;
}

void printDeck(const deck_type& deck)
{
    for(const auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
}

deck_type shuffleDeck(deck_type& deck)
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mt);
    return deck;
}

int getCardValue(const Card& card)
{
    switch(card.rank)
    {
        case CardRank::rank_two:    return 2;
        case CardRank::rank_three:  return 3;
        case CardRank::rank_four:   return 4;
        case CardRank::rank_five:   return 5;
        case CardRank::rank_six:    return 6;
        case CardRank::rank_seven:  return 7;
        case CardRank::rank_eight:  return 8;
        case CardRank::rank_nine:   return 9;
        case CardRank::rank_ten:    return 10;
        case CardRank::rank_Jack:   return 10;
        case CardRank::rank_Queen:  return 10;
        case CardRank::rank_King:   return 10;
        case CardRank::rank_Ace:    return 11;
        default:
            assert(false && "failed to return card value");
    }
}

bool playerWantsHit()
{
    while(true)
    {
        std::cout << "Enter (s) to stand or (h) to hit: ";
        char ch{};
        std::cin >> ch;

        switch(ch)
        {
            case 'h':
                return true;
            case 's':
                return false;
        }
    }
}

bool playerTurn(const deck_type& deck, std::size_t& cardIndex, Player& player)
{
    while(true)
    {
        if(player.score > g_maxScore)
        {
            std::cout << "You busted!\n";
            sleep(1);
            return true;
        }
        else if(playerWantsHit())
        {
            int cardValue{getCardValue(deck.at(cardIndex++))};
            player.score += cardValue;
            std::cout << "You were dealt a " << cardValue << " and now have a " << player.score << '\n';
            sleep(1);
        }
        else
        {
            return false;
        }
    }
}

bool dealerTurn(const deck_type& deck, std::size_t& cardIndex, Player& dealer)
{
    while(dealer.score < g_minimumDealerScore)
    {
        int cardValue{getCardValue(deck.at(cardIndex++))};
        dealer.score += cardValue;
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score << '\n';
        sleep(1);
    }

    if(dealer.score > g_maxScore)
    {
        std::cout << "The dealer busted!\n";
        sleep(1);
        return true;
    }

    return false;
}

bool playBlackjack(deck_type& deck)
{
    std::cout << "Welcome to the blackjack table, let's begin. \n";
    sleep(1);
    std::size_t cardIndex{0};

    Player dealer{getCardValue(deck.at(cardIndex++))};

    std::cout << "The dealer is showing " << dealer.score << '\n';
    sleep(1);

    Player player{getCardValue(deck.at(cardIndex)) + getCardValue(deck.at(cardIndex + 1))};
    cardIndex += 2;

    std::cout << "You have " << player.score << '\n';
    sleep(1);

    if (playerTurn(deck, cardIndex, player))
    {
        return false;
    }

    if (dealerTurn(deck, cardIndex, dealer))
    {
        return true;
    }

    return player.score > dealer.score;
}

//FIRST ATTEMPT ==============================
//    bool isDealerTurn{false};
//    bool isFirstDeal{true};
//    bool didPlayerStand{false};
//    constexpr int dealerMinimum{17};
//    constexpr int maxScore{21};
//
//    while(true)
//    {
//        if(!isDealerTurn && !didPlayerStand)
//        {
//            if(isFirstDeal)
//            {
//                playerScore += getCardValue(deck[cardIndex]);
//                ++cardIndex;
//                isFirstDeal = false;
//            }
//
//            playerScore += getCardValue(deck[cardIndex]);
//            ++cardIndex;
//            std::cout << "Your score is: " << playerScore << '\n';
//
//            if(playerScore == maxScore)
//            {
//                return true;
//            }
//            else if(playerScore > maxScore)
//            {
//                return false;
//            }
//
//            isDealerTurn = true;
//        }
//
//        if((isDealerTurn && dealerScore < dealerMinimum) || (didPlayerStand && dealerScore < dealerMinimum))
//        {
//            dealerScore += getCardValue(deck[cardIndex]);
//            ++cardIndex;
//            std::cout << "The dealers score is: " << dealerScore << '\n';
//
//            if(dealerScore == maxScore)
//            {
//                return false;
//            }
//            else if(dealerScore > maxScore)
//            {
//                return true;
//            }
//
//            if(!didPlayerStand)
//            {
//                std::cout << "Would you like to hit? (y/n): ";
//                char decision{};
//                std::cin >> decision;
//
//                if(decision == 'n')
//                {
//                    didPlayerStand = true;
//                }
//                else
//                {
//                    didPlayerStand = false;
//                }
//            }
//
//            isDealerTurn = false;
//        }
//
//        if(dealerScore >= dealerMinimum)
//        {
//            isDealerTurn = false;
//        }
//
//        if(dealerScore > playerScore && didPlayerStand)
//        {
//            return false;
//        }
//
//        if(dealerScore >= dealerMinimum && didPlayerStand)
//        {
//            if(playerScore > dealerScore)
//            {
//                return true;
//            }
//            else
//            {
//                return false;
//            }
//        }
//    }
