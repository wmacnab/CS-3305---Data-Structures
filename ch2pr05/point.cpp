// FILE: point.cpp
// CLASS IMPLEMENTED: point (see point.h for documentation)

#include "point.h"

namespace wmacnab_2_5
{
    // CONSTRUCTOR
    point::point(double init_x = 0, double init_y = 0, double init_z = 0)
    {
        x = init_x, y = init_y, z = init_z;
    }

    // MODIFICATION METHODS
    void point::shift_pos(double x_addend, double y_addend, double z_addend)
    {
        x += x_addend;
        y += y_addend;
        z += z_addend;
    }

    void point::xrot(double theta)
    {
        y = (y * cos(theta)) - (z * sin(theta));
        z = (y * sin(theta)) + (z * cos(theta));
    }

    void point::yrot(double theta)
    {
        x = (x * cos(theta)) - (z * sin(theta));
        z = ((-1 * x) * sin(theta)) + (z * cos(theta));
    }

    void point::zrot(double theta)
    {
        x = (x * cos(theta)) - (y * sin(theta));
        y = (x * sin(theta)) + (y * cos(theta));
    }

    // OPERATOR OVERLOADING
    point operator +(const point& p1, const point& p2)
    {
        point sum(p1.get_x() + p2.get_x(), p1.get_y() + p2.get_y(), p1.get_z() + p2.get_z());
        return sum;
    }

    point operator -(const point& p1, const point& p2)
    {
        point dif(p1.get_x() - p2.get_x(), p1.get_y() - p2.get_y(), p1.get_z() - p2.get_z());
        return dif;
    }
    
    bool operator ==(const point& p1, const point& p2)
    {
        return (p1.get_x() == p2.get_x() && p2.get_y() == p2.get_y() && p1.get_z() && p2.get_z());
    }

    void point::operator +=(const point& p)
    {
        x += p.get_x();
        y += p.get_y();
        z += p.get_z();
    }

    void point::operator -=(const point& p)
    {
        x -= p.get_x();
        y -= p.get_y();
        z -= p.get_z();
    }

    void point::operator *(const double& s)
    {
        x *= s;
        y *= s;
        z *= s;
    }

    void point::operator /(const double& s)
    {
        x /= s;
        y /= s;
        z /= s;
    }

    std::ostream& operator <<(const std::ostream& outs, const point& p)
    {
        std::cout << p.get_x() << " " << p.get_y() << " " << p.get_z();
    }
}