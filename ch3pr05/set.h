/*
Name: William MacNab
Date: 10 September 2021
Book: Data Structures and Other Objects Using C++ by Michael Main and Walter Savitch
Programming project: Chapter 2, Programming Project 18
Programming project statement:
A bag can contain more than one copy of an item. For example, the chapter describes a
bag that contains the number 4 and two copies of the number 8. This bag behavior is different
from a set, which can contain only a single copy of
any given item. Write a new container class called
set , which is similar to a bag, except that a set can
contain only one copy of any given item. You’ll need to change the interface a bit. For example, in-
stead of the bag’s count function, you’ll want a con-
stant member function such as this:
5
bool set::contains
(const value_type& target) const;
// Postcondition: The return value is true if
// target is in the set; otherwise the return
// value is false.
Make an explicit statement of the invariant of the set
class. Do a time analysis for each operation. At this
point, an efficient implementation is not needed. For
example, just adding a new item to a set will take lin-
ear time because you’ll need to check that the new
item isn’t already present. Later we’ll explore more
efficient implementations (including the implemen-
tation of set in the C++ Standard Library).
You may also want to add additional operations
to your set class, such as an operator for subtraction.
*/

/*
FILE: set.h
CLASS IMPLEMENTED: set
NAMEPSACE: wmacnab_3_5

VALUE SEMANTICS for the set class:
The assignment operator and the copy constructor may be used with set objects
*/

#ifndef WMACNAB_SET_H
#define WMACNAB_SET_H
#include <cstdlib>
#include <iostream>

namespace wmacnab_3_5
{
    class set
    {
    public:
        // TYPEDEFS
        typedef int value_type;
        typedef std::size_t size_type;
        const static size_type CAPACITY = 10;

        // CONSTRUCTORS
        set();

        // MODIFICATION METHODS
        bool insert(const value_type& entry);
        // Precondition: count() < size() and contains(entry) returns false
        // Postcondition: entry is now in the set at the leftmost empty position in data[].
        // The value returned is true if the insertion was successful, otherwise false
        bool remove(const value_type& target);
        // Precondition: contains(entry) returns true
        // Postcondition: the target is removed from the set, and all elements to the right
        // are shifted one position to the left.
        // Returns true if the target was removed, otherwise false

        // CONSTANT METHODS
        bool contains(const value_type& target) const;
        // Postcondition: returns true if the target exists in the set. Otherwise, returns false.
        void display() const;
        // Postcondition: prints the elements of the set separated by tabs
        size_type count() const { return used; }
        // Postcondition: returns the number of elements in the set
        size_type size() const { return CAPACITY; }
        // Postcondition: returns the maximum possible capacity of the set
        size_type find(const value_type& target) const;
        // Precondition: contains(entry) is true
        // Postcondition: returns the index in data[] for the target
        value_type get_data(size_type i) const;
        // Precondition: The given index has an element
        // Postcondition: The return value is the element at the specified index

        // OPERATOR OVERLOADS ORDERED
        void operator +=(const set& s);
        void operator -=(const set& s);
    private:
        value_type data[CAPACITY];
        size_type used;
    };
    // OPERATOR OVERLOADS UNORDERED
    set operator +(const set& s1, const set& set2);
    set operator -(const set& s1, const set& set2);
    bool operator ==(const set& s1, const set& s2);
    std::ostream& operator <<(std::ostream& outs, const set& s);
}

#endif