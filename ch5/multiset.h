/*
FILE: multiset.h
CLASS DEFINED: multiset
NAMESPACE: wmacnab_5

VALUE SEMANTICS for the multiset class:
Assignments and the copy constructor may be used with multiset objects

DYNAMIC MEMORY USAGE by the multiset class:
If there is insufficient dynamic memory, then the following may throw bad_alloc:
The constructors, insert, operator +, operator +=, and the assignment operator.
*/

#ifndef WMACNAB_MULTISET_H
#define WMACNAB_MULTISET_H
#include <cstdlib> // Provides size_t and NULL
#include "node.h"

namespace wmacnab_5
{
    class multiset
    {
    public:
        // TYPDEFS
        typedef node::value_type value_type;
        typedef size_t size_type;
        // CONSTRUCTORS
        multiset();
        multiset(const multiset& source);
        ~multiset();
        // MODIFICATION METHODS
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const multiset& addend);
        void operator =(const multiset& source);
        // CONSTANT METHODS
        size_type size() const;
        size_type count(const value_type& target) const;
        value_type grab() const;
        friend multiset operator +(const multiset& ms1, const multiset& ms2);
    private:
        node *head_ptr;
        size_type many_nodes;
    };
    // FUNCTIONS
    //multiset operator +(const multiset& ms1, const multiset& ms2);
}

#endif