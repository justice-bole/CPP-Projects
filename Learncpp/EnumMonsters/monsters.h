//
// Created by Justice Bole on 8/30/22.
//
#include <string_view>

#ifndef ENUMMONSTERS_MONSTERS_H
#define ENUMMONSTERS_MONSTERS_H

// STRUCTS & ENUMS ======================
enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

struct Monster
{
    MonsterType type{};
    std::string_view name{};
    int health{};
};

// FUNCTIONS ============================
constexpr std::string_view getMonsterTypeName(MonsterType type);
void printMonster(const Monster& mon);

#endif //ENUMMONSTERS_MONSTERS_H
