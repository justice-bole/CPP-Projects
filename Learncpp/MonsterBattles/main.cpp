#include <iostream>
#include <string>
#include <array>
#include <cstdlib> // for rand() and srand()
#include <sstream>
#include <ctime> // for time()
#include <random>



namespace Random // capital R to avoid conflicts with functions named random()
{
    std::mt19937 mt{ std::random_device{}() };

    int get(int min, int max)
    {
        std::uniform_int_distribution die{ min, max }; // we can create a distribution in any function that needs it
        return die(mt); // and then generate a random number from our global generator
    }
}
class Potion
{
public:
    enum PotionType
    {
        health,
        strength,
        poison,

        max_type,
    };
    enum PotionSize
    {
        small,
        medium,
        large,

        max_size,
    };
private:
    PotionType m_type{};
    PotionSize m_size{};

public:
    Potion(PotionType type, PotionSize size) : m_type{type}, m_size{size}
    {
    }

    PotionSize getSize() const { return m_size; }
    PotionType getType() const { return m_type; }

    static std::string_view getPotionTypeName(PotionType type)
    {
        static constexpr std::array names{
                "Health",
                "Strength",
                "Poison"
        };

        return names.at(static_cast<std::size_t>(type));
    }

    static std::string_view getPotionSizeName(PotionSize size)
    {
        static constexpr std::array names{
                "Small",
                "Medium",
                "Large"
        };

        return names.at(static_cast<std::size_t>(size));
    }

    std::string getName() const
    {
        std::stringstream result{};

        result << getPotionSizeName(getSize()) << " potion of " << getPotionTypeName(getType());

        return result.str();
    }

    static Potion getRandomPotion()
    {
        return {
                static_cast<PotionType>(Random::get(0, static_cast<int>(PotionType::max_type) - 1)),
                static_cast<PotionSize>(Random::get(0, static_cast<int>(PotionSize::max_size) - 1))
        };
    }
};

class Creature {
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_attack{};
    int m_gold{};

public:
    Creature(const std::string_view name, char symbol, int hp, int atk, int gold)
        : m_name{name}, m_symbol{symbol}, m_health{hp}, m_attack{atk}, m_gold{gold}
    {

    }

    void reduceHealth(int damage) { m_health -= damage; }
    bool isDead() { return m_health <= 0; }
    void addGold(int gold) { m_gold += gold; }

    const std::string_view getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getAttack() const { return m_attack; }
    int getGold() const { return m_gold; }
};

class Player : public Creature
{
private:
    int m_level{1};
    static constexpr int m_maxLevel{20};

public:
    Player(const std::string_view name) : Creature{name, '@', 10, 1, 0}
    {
    }

    void levelUp()
    {
        ++m_level;
        ++m_attack;
    }
    bool hasWon() const { return m_level >= m_maxLevel;}

    int getLevel() const { return m_level;}

    void drinkPotion(const Potion& potion)
    {
        switch (potion.getType())
        {
            case Potion::health:
                m_health += ((potion.getSize() == Potion::large) ? 5 : 2);
                break;
            case Potion::strength:
                ++m_attack;
                break;
            case Potion::poison:
                reduceHealth(1);
                break;
            case Potion::max_type:
                break;
        }
    }

};

class Monster : public Creature
{
public:
    enum class Type
    {
        dragon,
        orc,
        slime,

        max_types,
    };

private:
    static const Creature& getDefaultCreature(Type type)
    {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
                { {"dragon", 'D', 20, 4, 100},
                  {"orc", 'o', 4, 2, 25},
                  {"slime", 's', 1, 1, 10} }
                };

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(Type type) : Creature{getDefaultCreature(type)}
    {
    }

    static Monster getRandomMonster()
    {
        int rand{Random::get(0, static_cast<int>(Type::max_types) - 1)};
        return Monster{static_cast<Type>(rand)};
    }

};



//handles player attacking monster as well as level ups
void attackMonster(Monster& monster, Player& player)
{
    if(player.isDead()) return;
    monster.reduceHealth(player.getAttack());

    std::cout << "You hit the " << monster.getName() << " for " << player.getAttack() << " damage.\n";
    std::cout << "The " << monster.getName() << " has " << monster.getHealth() << " health left.\n";

    if(monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        std::cout << "You found " << monster.getGold() << " gold.\n";
        player.addGold(monster.getGold());
        if(Random::get(1,3) == 1)
        {
            Potion potion{Potion::getRandomPotion()};
            std::cout << "You found a mythical potion! Do you want to drink it? [y/n] \n";
            char decision{};
            std::cin >> decision;
            if(decision == 'y')
            {
                std::cout << "You drank a " << potion.getName() << ".\n";
                player.drinkPotion(potion);
            }
        }
    }
}

//handles monster attacking player
void attackPlayer(Monster& monster, Player& player)
{
        if(monster.isDead()) return;
        player.reduceHealth(monster.getAttack());

        std::cout << "The " << monster.getName() << " hit you for " << monster.getAttack() << " damage.\n";
        std::cout << "You have " << player.getHealth() << " health points remaining.\n";
}

//handles fight between player and monster, including run or fight cases and results
void fightMonster(Player& player)
{
    Monster monster{Monster::getRandomMonster()};
    std::cout << "You have encountered a " << monster.getName() << ' ' << monster.getSymbol() << ".\n";

    while(!monster.isDead() && !player.isDead())
    {
        std::cout << "(R)un or (F)ight: ";
        char decision{};
        std::cin >> decision;

        if(decision == 'r')
        {
            int rand{Random::get(1,2)};
            if(rand == 1)
            {
                std::cout << "You failed to flee.\n";
                attackPlayer(monster, player);
                continue;
            }
            else
            {
                std::cout << "You successfully fled.\n";
                return;
            }
        }
        else
        {
            attackMonster(monster, player);
            attackPlayer(monster, player);
        }
    }


}

int main()
{
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;

    Player p{playerName};

    std::cout << "Welcome, " << p.getName() << '\n';

    while(!p.hasWon() && !p.isDead())
    {
        fightMonster(p);
    }

    if(p.isDead())
    {
        std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
    {
        std::cout << "You reached level 20! Congratulations, you win!";
    }

    return 0;
}