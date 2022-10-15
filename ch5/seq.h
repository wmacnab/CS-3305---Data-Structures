// FILE: seq.h
// CLASS IMPLEMENTED: sequence
// NAMESPACE: wmacnab_5

/*
TYPEDEFS:
typedef _____ size_type;
    sequence::size_type is the data type of any variable that keeps track of how many
    items are in the sequence

typedef _____ value_type;
    sequence::value_type is the data type of the items in the sequence.
    It may be any of the built in C++ types or any class with a default constructor,
    a copy constructor, an assignment operator, and a test for equality (x == y)

METHODS
    void start()
        Precondition:
        Postcondition: The current item is now the first item of the sequence

    value_type current() const
        Precondition:
        Postcondition: The return value is the current item of the sequence, no NULL
        if there is no current item

    void advance()
        Precondition: is_item() returns true
        Postcondition: The current item becomes the item after the current item, or NULL
        if the current item is the last item in the sequence

    void insert(const value_type& entry)
        Precondition:
        Postcondition: entry is inserted before the current item in the sequence

    void attach(const value_type& entry)
        Precondition:
        Postcondition: entry is inserted after the current item in the sequence

    void remove()
        Precondition: is_item() returns true
        Postcondition: The current item of the sequence is removed

    size_type size() const
        Precondition:
        Postcondition: The return value is the number of items in the sequence

    bool is_item() const
        Precondition:
        Postcondition: The return value is true if there exists a current item, otherwise false.

VALUE SEMANTICS for the sequence class:
    The copy constructor and assignment operator are safe to use

DYNAMIC MEMORY ALLOCATION by the sequence class:
    The following may throw bad_alloc if there is insufficient dynamic memory:
    idk1, idk2, idk3, ect...
*/

#ifndef WMACNAB_SEQ_H
#define WMACNAB_SEQ_H
#include <cstdlib> // Provides size_t
#include "node.h"

namespace wmacnab_5
{
    class sequence
    {
    public:
        // DECLARATIONS
        typedef size_t size_type;
        typedef node::value_type value_type;
        // CONSTRUCTORS
        sequence();
        sequence(const sequence& source);
        ~sequence();
        // MODIFICATION METHODS
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void start();
        void advance();
        void remove();
        void operator =(const sequence& addend);
        // CONSTANT METHODS
        value_type current() const;
        size_type size() const;
        bool is_item() const;
    private:
        node *head_ptr, *tail_ptr; // Points to the first and last node of the linked list
        node *cursor; // Points to the current item in the sequence
        node *precursor; // Points to the item before the current item or NULL
        size_type many_nodes;
    };
}

#endif