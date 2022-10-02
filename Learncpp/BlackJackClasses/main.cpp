#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

constexpr int g_maximumScore{ 21 };
constexpr int g_minimumDealerScore{ 17 };

class Card
{
public:
    enum CardSuit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum CardRank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };

private:
    CardRank m_rank{};
    CardSuit m_suit{};

public:
    Card(CardRank rank = rank_ace, CardSuit suit = spade) : m_rank{rank}, m_suit{suit} {}

    void print() const
    {
        switch (m_rank)
        {
            case CardRank::rank_2:      std::cout << '2';   break;
            case CardRank::rank_3:      std::cout << '3';   break;
            case CardRank::rank_4:      std::cout << '4';   break;
            case CardRank::rank_5:      std::cout << '5';   break;
            case CardRank::rank_6:      std::cout << '6';   break;
            case CardRank::rank_7:      std::cout << '7';   break;
            case CardRank::rank_8:      std::cout << '8';   break;
            case CardRank::rank_9:      std::cout << '9';   break;
            case CardRank::rank_10:     std::cout << 'T';   break;
            case CardRank::rank_jack:   std::cout << 'J';   break;
            case CardRank::rank_queen:  std::cout << 'Q';   break;
            case CardRank::rank_king:   std::cout << 'K';   break;
            case CardRank::rank_ace:    std::cout << 'A';   break;
            default:
                std::cout << '?';
                break;
        }

        switch (m_suit)
        {
            case CardSuit::club:       std::cout << 'C';   break;
            case CardSuit::diamond:    std::cout << 'D';   break;
            case CardSuit::heart:      std::cout << 'H';   break;
            case CardSuit::spade:      std::cout << 'S';   break;
            default:
                std::cout << '?';
                break;
        }
    }

    int value() const
    {
        switch (m_rank)
        {
            case CardRank::rank_2:        return 2;
            case CardRank::rank_3:        return 3;
            case CardRank::rank_4:        return 4;
            case CardRank::rank_5:        return 5;
            case CardRank::rank_6:        return 6;
            case CardRank::rank_7:        return 7;
            case CardRank::rank_8:        return 8;
            case CardRank::rank_9:        return 9;
            case CardRank::rank_10:       return 10;
            case CardRank::rank_jack:     return 10;
            case CardRank::rank_queen:    return 10;
            case CardRank::rank_king:     return 10;
            case CardRank::rank_ace:      return 11;
            default:
                assert(false && "should never happen");
        }
    }

};

class Deck
{
private:
    std::array<Card, 52> m_deck{};
    int m_cardIndex{0};

public:
    Deck()
    {
        std::array<Card, 52>::size_type index{ 0 };
        for (int suit{ 0 }; suit < Card::max_suits; ++suit)
        {
            for (int rank{ 0 }; rank < Card::max_ranks; ++rank)
            {
                m_deck[index] = {static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit)};
                ++index;
            }
        }
    }

    void print() const
    {
        for (const auto& card : m_deck)
        {
            card.print();
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    const Card& dealCard()
    {
        assert(m_cardIndex < m_deck.size());

        return m_deck[m_cardIndex++];
    }

    void shuffle()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);
        m_cardIndex = 0;
    }
};

class Player
{
private:
    int m_score;

public:
    int drawCard(Deck& deck)
    {
        return m_score += deck.dealCard().value();
    }

    int score() const
    {
        return m_score;
    }

    bool isBust() const
    {
        return (m_score > g_maximumScore);
    }
};

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
            case 'h':
                return true;
            case 's':
                return false;
        }
    }
}

bool playerTurn(Deck deck, Player& player)
{
    while (true)
    {
        if (player.isBust())
        {
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                auto playerCard{player.drawCard(deck)};
                std::cout << "You were dealt a " << playerCard << " and now have " << player.score() << '\n';
            }
            else
            {
                return false;
            }
        }
    }
}

bool dealerTurn(Deck& deck, Player& dealer)
{
    while (dealer.score() < g_minimumDealerScore)
    {
        auto dealerCard{ dealer.drawCard(deck)};
        std::cout << "The dealer turned up a " << dealerCard << " and now has " << dealer.score() << '\n';

    }

    if (dealer.score() > g_maximumScore)
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(Deck& deck)
{
    Player dealer{};
    dealer.drawCard(deck);

    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);

    std::cout << "You have: " << player.score() << '\n';

    if (playerTurn(deck, player))
    {
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        return true;
    }

    return (player.score() > dealer.score());
}

int main()
{
    Deck deck{};
    deck.shuffle();

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
};