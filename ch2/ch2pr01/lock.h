/*
Name: William MacNab
Date: 10 September 2021
Book: Data Structures and Other Objects Using C++ by Michael Main and Walter Savitch
Programming project: Chapter 2, Programming Project 1
Programming project statement:
Specify, design, and implement a class that can be used in a program that simulates
a combination lock. The lock has a circular knob, with the numbers 0 through 39 marked on the edge,
and it has a three-number combination, which we'll call x, y, z. To open the lock, you must turn
the knob clockwise at least one entire revolution, stopping with x at the top; then turn the knob
counter-clockwise, stopping the second time that y appears at the top; finally turn the knob
clockwise again, stopping the next time that z appears at the top. At this point, you may open the
lock.
Your lock class should have a constructor that initializes the three-number combination
(use 0, 0, 0) for default arguments). Also provide member functions:
a) to alter the lock's combination to a new three-number combination
b) to turn the knob in a given direction until a specified number appears at the top
c) to close the lock
d) to attempt to open the lock
e) to inquire about the status of the lock (open or shut)
f) to tell you what number is currently at the top
*/

/*
FILE: lock.h
CLASS IMPLEMENTED: lock
NAMESPACE: wmacnab_2_1

CONSTRUCTOR
lock(int init_x = 0, int init_y = 0, int init_z = 0)
Postcondition: The lock's combination is x, y, z.

MODIFICATION METHODS
void set_combination(int new_x, int new_y, int new_z);
Postcondition: The lock's combination is x, y, z, and any current unlocking progress has been reset.

void rotate(int new_pos, bool clockwise);
Postcondition: If new_pos is in the range [0, 39], it is rotated to that position in the specified direction.

void close();
Postcondition: The lock is closed

void open();
Postcondition: If the combination has been input correctly, the lock will open. Otherwise, nothing happens.

CONSTANT METHODS
bool is_locked() const
Postcondition: returns false if the lock is open, returns true if the lock is closed

int position() const
Postcondition: returns the integer position that the dial is on

VALUE SEMANTICS for the lock class:
Assignments and the copy constructor may be used with lock objects.
*/

#ifndef WMACNAB_LOCK_H
#define WMACNAB_LOCK_H

namespace wmacnab_2_1
{
    class lock
    {
    public:
        // Constructor
        lock(int init_x = 0, int init_y = 0, int init_z = 0);
        // Modification methods
        void set_combination(int new_x, int new_y, int new_z);
        void rotate(int new_pos, bool clockwise);
        void close();
        void open();
        // Constant methods
        bool is_locked() const { return locked; }
        int position() const { return pos; }
    private:
        bool locked, is_clockwise;
        int pos, x, y, z, distance, num_correct;
        // Private modification methods
        void check_lock();
        void change_direction();
    };
}

#endif