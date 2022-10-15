// FILE: lock.cpp
// CLASS IMPLEMENTED: lock (see lock.h for documentation)

#include "lock.h"

namespace wmacnab_2_1
{
    // Public modification methods
    lock::lock(int init_x = 0, int init_y = 0, int init_z = 0)
    {
        x = init_x, y = init_y, z = init_z, pos = 0;
        distance = 0, locked = true, is_clockwise = true, num_correct = 0;
    }

    void lock::set_combination(int new_x, int new_y, int new_z)
    {
        x = new_x, y = new_y, z = new_z;
        num_correct = 0, distance = 0;
    }

    void lock::rotate(int new_pos, bool clockwise)
    {
        if (new_pos >= 0 && new_pos <= 39)
        {
            if (is_clockwise != clockwise) change_direction();
            distance += (pos >= new_pos) ? ((39 - pos) + (new_pos + 1)) : (new_pos - pos);
            distance %= 80;
            pos = new_pos;
        }
    }

    void lock::close()
    {
        locked = true, distance = 0, num_correct = 0;
    }

    void lock::open()
    {
        if (num_correct == 3) locked = false;
    }

    // Private modification methods
    void lock::check_lock()
    {
        if (distance > 80) num_correct = 0;
        switch (num_correct)
        {
            case 0:
                if ((distance > 39) && (pos == x)) num_correct = 1;
                break;
            case 1:
                if ((distance > 39) && (distance <= 80) && (pos == y)) num_correct = 2;
                break;
            case 2:
                if ((distance <= 39) && (pos == z)) num_correct = 3;
                break;
        }
    }

    void lock::change_direction()
    {
        is_clockwise = !is_clockwise;
        distance = 0;
    }
}