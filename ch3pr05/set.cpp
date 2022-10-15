/*
FILE: set.cpp
CLASS IMPLEMENTED: set
NAMESPACE: wmacnab_3_5

INVARIANT of the set class:
1. All elements of the set are contiguous and the first element is located at index 0
*/

#include "set.h"

namespace wmacnab_3_5
{
    // DECLARATIONS
    const set::size_type CAPACITY = set::CAPACITY;

    // CONSTRUCTOR
    set::set() { used = 0; }

    // MODIFICATION METHODS
    bool set::insert(const value_type& entry)
    {
        if (count() >= size() || contains(entry)) return false;
        data[used] = entry;
        ++used;
        return true;
    }

    bool set::remove(const value_type& entry)
    {
        if (!contains(entry)) return false;
        size_type pos = find(entry);
        for (size_type i = count() - 1; i > pos; --i)
        {
            data[i - 1] = data[i];
        }
        --used;
        return false;
    }

    // CONSTANT METHODS
    bool set::contains(const value_type& target) const
    {
        for (size_type i = 0; i < count(); ++i)
        {
            if (target == data[i]) return true;
        }
        return false;
    }

    void set::display() const
    {
        for (size_type i = 0; i < count(); ++i)
        {
            std::cout << data[i] << "\t";
        }
    }

    set::size_type set::find(const value_type& target) const
    {
        size_type counter;
        for (counter = 0; counter < count(); ++counter)
        {
            if (target == data[counter]) break;
        }
        return counter;
    }

    set::value_type set::get_data(size_type i) const
    {
        if (i < count() && i >= 0) return data[i];
        return value_type();
    }

    // OPERATOR OVERLOADS
    set operator +(const set& s1, const set& s2)
    {
        set sum;
        set::size_type i;
        for (i = 0; i < s1.count(); ++i)
        {
            sum.insert(s1.get_data(i));
        }
        for (i = 0; i < s2.count(); ++i)
        {
            if (sum.count() >= sum.size()) break;
            if (sum.contains(s2.get_data(i))) continue;
            sum.insert(s2.get_data(i));
        }
        return sum;
    }

    set operator -(const set& s1, const set& s2)
    {
        set difference;
        for (set::size_type i = 0; i < s1.count(); ++i)
        {
            if (!s2.contains(s1.get_data(i)))
            {
                difference.insert(s1.get_data(i));
            }
        }
        return difference;
    }

    bool operator ==(const set& s1, const set& s2)
    {
        if (s1.count() != s2.count()) return false;
        for (set::size_type i = 0; i < s1.count(); ++i)
        {
            if (!s1.contains(s2.get_data(i))) return false;
        }
        return true;
    }

    std::ostream& operator <<(std::ostream& outs, const set& s)
    {
        for (set::size_type i = 0; i < s.count(); ++i)
        {
            outs << s.get_data(i) << "\t";
        }
        return outs;
    }

    void set::operator +=(const set& s)
    {
        *this = *this + s;
    }

    void set::operator -=(const set& s)
    {
        *this = *this - s;
    }
}