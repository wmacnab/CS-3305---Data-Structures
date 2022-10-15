/*
Name: William MacNab
Date: 10 September 2021
Book: Data Structures and Other Objects Using C++ by Michael Main and Walter Savitch
Programming project: Chapter 2, Programming Project 5
Programming project statement:
Specify, design, and implement a class that can be used to keep track of the position of a
point in three-dimensional space. For example, consider the point drawn at the top of the next col-
umn. The point shown there has three coordinates: x = 2.5, y = 0, and z = 2.0. Include member func-
tions to set a point to a specified location, to shift a
point a given amount along one of the axes, and to retrieve the coordinates of a point. Also provide
member functions that will rotate the point by a specified angle around a specified axis.
To compute these rotations, you will need a bit of trigonometry. Suppose you have a point with coor-
dinates x, y, and z. After rotating this point (counter-clockwise)
by an angle θ , the point will have new coordinates, which we’ll call x′ , y′ , and z′ . The
equations for the new coordinates use the cmath library functions sin and cos , as shown here:
After a θ rotation around the x-axis:
x′ = x
y′ = y cos ( θ ) – z sin ( θ )
z′ = y sin ( θ ) + z cos ( θ )
After a θ rotation around the y-axis:
x′ = x cos ( θ ) + z sin ( θ )
y′ = y
z′ = – x sin ( θ ) + z cos ( θ )
After a θ rotation around the z-axis:
x′ = x cos ( θ ) – y sin ( θ )
y′ = x sin ( θ ) + y cos ( θ )
z′ = z
*/

/*
FILE: point.h
CLASS IMPLEMENTED: point
NAMESPACE: wmacnab_2_5

// CONSTRUCTORS
point(double init_x = 0, double init_y = 0, double init_z = 0)
Postcondition: A point is created with coordinates init_x, init_y, init_z.

// MODIFICATION METHODS
void set_x(double new_x)
Postcondition: The point's new x-coordinate is new_x

void set_y(double new_y)
Postcondition: The point's new y-coordinate is new_y

void set_z(double new_z)
Postcondition: The point's new z-coordinate is new_z

void shift_pos(double x_addend, double y_addend, double z_addend)
Postcondition: The point's x, y, and z coordinate are changed. The values may be negative.

void shift_x(double addend)
Postcondition: The point's x value is added by the addend

void shift_y(double addend)
Postcondition: The point's y value is added by the addend

void shift_z(double addend)
Postcondition: The point's z value is added by the addend

void xrot(double theta)
Postcondition: The point is rotated about the x-axis by the angle theta

void yrot(double theta)
Postcondition: The point is rotated about the y-axis by the angle theta

void zrot(double theta)
Postcondition: The point is rotated about the z-axis by the angle theta

// CONSTANT METHODS
double get_x() const
Postcondition: returns x

double get_y() const
Postcondition: returns y

double get_z() const
Postcondition: returns z

// OPERATOR OVERLOADS
+, -, +=, -=, *, /, ==, <<

// VALUE SEMANTICS for the point class:
Assignments and the copy constructor may be used with point objects.
*/

#ifndef WMACNAB_POINT_H
#define WMACNAB_POINT_H
#include <iostream>
#include <cmath>

namespace wmacnab_2_5
{
    class point
    {
    public:
        // Constructor
        point(double init_x = 0, double init_y = 0, double init_z = 0);

        // Modification methods
        void set_x(double new_x) { x = new_x; }
        void set_y(double new_y) { y= new_y; }
        void set_z(double new_z) { z = new_z; }
        void shift_pos(double x_addend, double y_addend, double z_addend);
        void shift_x(double addend) { x += addend; }
        void shift_y(double addend) { y += addend; }
        void shift_z(double addend) { z += addend; }
        void xrot(double theta);
        void yrot(double theta);
        void zrot(double theta);

        // Constant methods
        double get_x() const { return x; }
        double get_y() const { return y; }
        double get_z() const { return z; }

        // Member operator overloading
        void operator +=(const point& p);
        void operator -=(const point& p);
        void operator *(const double& scalar);
        void operator /(const double& scalar);
        //friend std::istream& operator >>(const std::istream& ins, const point& p);

    private:
        double x, y, z;
    };
    // Operator overloading
    point operator +(const point& p1, const point& p2);
    point operator -(const point& p1, const point& p2);
    bool operator ==(const point& p1, const point& p2);
    std::ostream& operator <<(const std::ostream& outs, const point& p);
}

#endif