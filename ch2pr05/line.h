/*
Name: William MacNab
Date: 10 September 2021
Book: Data Structures and Other Objects Using C++ by Michael Main and Walter Savitch
Programming project: Chapter 2, Programming Project 6
Programming project statement:
In three-dimensional space, a line segment is
defined by its two endpoints. Specify, design,
and implement a class for a line segment.
The class should have two private member variables
that are points from the previous project.
*/

/*
FILE: line.h
CLASS IMPLEMENTED: line
NAMESPACE: wmacnab_2_6

CONSTRUCTORS

MODIFICATION METHODS

CONSTANT METHODS

VALUE SEMANTICS for the line class:
Assignments and the copy constructor may be used for line objects.
*/

#ifndef WMACNAB_LINE_H
#define WMACNAB_LINE_H
#include "point.h"
using namespace wmacnab_2_5;

namespace wmacnab_2_6
{
    class line
    {
    public:
        line(point new_p1, point new_p2);
    private:
        point p1;
        point p2;
    };
}

#endif