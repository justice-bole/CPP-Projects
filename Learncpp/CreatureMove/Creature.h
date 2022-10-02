//
// Created by Justice Bole on 9/21/22.
//

#ifndef CREATUREMOVE_CREATURE_H
#define CREATUREMOVE_CREATURE_H

#include "Point2d.h"
#include <string>

class Creature {
private:
    std::string m_name{};
    Point2d m_location{};

public:
    Creature(const std::string& name, const Point2d& location) : m_name{name}, m_location{location}
    {

    }

    friend std::ostream& operator<<(std::ostream& out, Creature& creature)
    {
        out << creature.m_name << " is at " << creature.m_location;
        return out;
    }

    void moveTo(int x, int y)
    {
        m_location.setPoint(x, y);
    }




};


#endif //CREATUREMOVE_CREATURE_H
