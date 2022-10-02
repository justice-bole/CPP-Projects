//
// Created by Justice Bole on 9/8/22.
//

#ifndef CARDGAME_FUNCTIONS_H
#define CARDGAME_FUNCTIONS_H

//ENUMS AND STRUCTS ============================================
enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    maxsuit,
};

enum class CardRank
{
    rank_two,
    rank_three,
    rank_four,
    rank_five,
    rank_six,
    rank_seven,
    rank_eight,
    rank_nine,
    rank_ten,
    rank_Jack,
    rank_Queen,
    rank_King,
    rank_Ace,

    maxrank,
};

struct Card
{
    CardSuit suit{};
    CardRank rank{};
};

struct Player
{
    int score{};
};

//USING ==============================================================
using deck_type = std::array<Card, 52>;

//FUNCTIONS ===========================================================
deck_type createDeck();
deck_type shuffleDeck(deck_type& deck);

bool playBlackjack(deck_type& deck);
bool dealerTurn(const deck_type& deck, std::size_t& cardIndex, Player& dealer);
bool playerTurn(const deck_type& deck, std::size_t& cardIndex, Player& player);
bool playerWantsHit();

int getCardValue(const Card& card);

void printCard(const Card& card);
void printDeck(const deck_type& deck);




#endif //CARDGAME_FUNCTIONS_H
