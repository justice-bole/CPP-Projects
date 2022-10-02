//
// Created by Justice Bole on 9/14/22.
//

#ifndef FRIENDFUNCTIONS_POINT3D_H
#define FRIENDFUNCTIONS_POINT3D_H

class Vector3d;

class Point3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3d(double x = 0.0, double y = 0.0, double z = 0.0);

    void print() const;

    void moveByVector(const Vector3d& v);

};

#endif //FRIENDFUNCTIONS_POINT3D_H
