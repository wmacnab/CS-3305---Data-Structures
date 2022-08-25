// FILE: multiset.h
// CLASS IMPLEMENTED: multiset
// NAMESPACE: wmacnab_6
/*

VALUE SEMANTICS for the multiset class:
The assignment operator and copy constructor may be used with multiset objects

DYNAMIC MEMORY ALLOCATION for the multiset class:
The following methods may throw bad_alloc if there is insufficient dynamic memory:
The copy constructor, 
*/

#ifndef WMACNAB_MULTISET_H_TEMPLATE
#define WMACNAB_MULTISET_H_TEMPLATE

#include <cstdlib> // Provides size_t
#include "node.h"

namespace wmacnab_6
{
    template <typename Item>
    class multiset
    {
    public:
        // Typedefs
        typedef Item value_type;
        typedef size_t size_type;
        typedef node_iterator<Item> iterator;
        typedef const_node_iterator<Item> const_iterator;
        // CONSTRUCTORS AND DESTRUCTOR
        multiset();// { head_ptr = NULL; many_nodes = 0; }
        multiset(const multiset& source); // Value semantics
        ~multiset(); // Value semantics
        // MODIFICATION METHODS
        void operator =(const multiset& source); // Value semantics
        void operator +=(const multiset& addend);
        void insert(const Item& entry);
        bool erase_one(const Item& target);
        size_type erase(const Item& target);
        // CONST METHODS
        size_type size() const { return many_nodes; }
        // ITERATOR FUNCTIONS
        iterator begin() { return iterator(head_ptr); }
        const_iterator begin() const { return const_iterator(head_ptr); }
        iterator end() { return iterator(); } // Calls default constructor
        // From stack overflow: this declares function iterator(); and returns object
        // iterator.
        const_iterator end() const { return const_iterator(); } // Calls default constructor
    private:
        node<Item>* head_ptr;
        size_type many_nodes;
    };
    template <typename Item>
    multiset<Item> operator +(const multiset<Item>& m1, const multiset<Item>& m2);
}

#include "multiset.template"
#endif

// METHODS:
// Insert an element
// Remove one matching element by element value
// Remove all matching elements by element value
// Size to get the number of elements in the multiset
// Count to... what?
// Operator + to add two multisets
// Operator - to subtract two multisets
// Operator += and -=

// Remember, we will be using an iterator
// begin() method creates and returns an iterator to first item (and a const version)
// end() methods