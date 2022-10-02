//
// Created by Justice Bole on 8/30/22.
//
#include <iostream>
#include "monsters.h"

constexpr std::string_view getMonsterTypeName(MonsterType type) {
    switch (type)
    {
        case MonsterType::ogre:         return "Ogre";
        case MonsterType::dragon:       return "Dragon";
        case MonsterType::orc:          return "Orc";
        case MonsterType::giantSpider:  return "Giant Spider";
        case MonsterType::slime:        return "Slime";
    }
        return "Unknown Monster Type";
}

void printMonster(const Monster& mon)
{
    std::cout << "This " << getMonsterTypeName(mon.type) <<
    " is named " << mon.name << " and has " << mon.health << " health.\n";
}