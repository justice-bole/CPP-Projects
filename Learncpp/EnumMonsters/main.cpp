#include <iostream>
#include "monsters.h"

int main() {
    Monster ogre{MonsterType::ogre, "Torg", 145};
    Monster slime{MonsterType::slime, "Blurp", 23};
    Monster dragon{MonsterType::dragon, "Sylandros The Unbecoming", 1015};

    printMonster(ogre);
    printMonster(slime);
    printMonster((dragon));
    return 0;
}
