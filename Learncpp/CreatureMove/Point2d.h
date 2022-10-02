//
// Created by Justice Bole on 9/21/22.
//

#ifndef CREATUREMOVE_POINT2D_H
#define CREATUREMOVE_POINT2D_H

#import <iostream>

class Point2d {
private:
    int m_x{};
    int m_y{};

public:
    Point2d() = default;

    Point2d(int x, int y) : m_x{x}, m_y{y}
    {

    }

    friend std::ostream& operator<<(std::ostream& out, Point2d& point2d)
    {
        out << '(' << point2d.m_x << ", " << point2d.m_y << ')';
        return out;
    }

    void setPoint(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

};


#endif //CREATUREMOVE_POINT2D_H
