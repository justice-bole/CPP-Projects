#include <iostream>
#include <array>

class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,

        max_monster_types,
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitpoints{};

public:
    Monster(Type monType, const std::string_view name, const std::string_view roar, int hp)
        : m_type{monType}, m_name{name}, m_roar{roar}, m_hitpoints{hp}
    {
    }

    std::string_view getTypeString() const
    {
        switch(m_type)
        {
            case Type::dragon:      return "Dragon";
            case Type::goblin:      return "Goblin";
            case Type::ogre:        return "Ogre";
            case Type::orc:         return "Orc";
            case Type::skeleton:    return "Skeleton";
            case Type::troll:       return "Troll";
            case Type::vampire:     return "Vampire";
            case Type::zombie:      return "Zombie";
            default:                return "ERROR";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitpoints
            << " hit points and says " << m_roar << '\n';
    }

};

class MonsterGenerator
{
public:
    static Monster generateMonster()
    {
        Monster::Type type{getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1)};
        const int hitpoints{getRandomNumber(1, 100)};

        static constexpr std::array<std::string_view, 6> s_names{"Bones", "Grom'gol", "Serethezene", "Chubb", "Reginald", "Treeko"};
        static constexpr std::array<std::string_view, 6> s_roars{"*rattle*", "*growl*", "*grunt*", "hello", "GRAAAA", "come closer..."};

        auto name{s_names[getRandomNumber(0, std::size(s_names) - 1)]};
        auto roar{s_roars[getRandomNumber(0, std::size(s_names) - 1)]};

        return {type, name, roar, hitpoints};
    }

    static int getRandomNumber(int min, int max)
    {
        static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }
};

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); // If using Visual Studio, discard first random value

    Monster m{ MonsterGenerator::generateMonster() };
    Monster n{ MonsterGenerator::generateMonster() };
    m.print();
    n.print();

    return 0;
}
