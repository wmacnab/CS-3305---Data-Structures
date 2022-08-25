/*
File: multiset.h
Class: multiset (template container class using a binary search tree)
Namespace: wmacnab_10

Dynamic memory allocation for the multiset class:

Value semantics for the multiset class:
The assignment operator and copy constructor are safe to use
*/

#ifndef WMACNAB_MULTISET_H
#define WMACNAB_MULTISET_H

#include "bintree.h"

namespace wmacnab_10
{
    template <typename Item>
    class multiset
    {
    public:
        // Typedefs
        typedef typename binary_tree_node<Item>::size_type size_type;
        typedef typename binary_tree_node<Item>::value_type value_type;
        // Constructors and destructor
        multiset();
        multiset(const multiset& source);
        ~multiset();
        // Modification methods
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator =(const multiset& source);
        void operator +=(const multiset& addend);
        // Constant methods
        size_type size() const;
        size_type count(const Item& target) const;
        void print() const;
    private:
        binary_tree_node<Item>* root_ptr;
        // Other private member variables may be added as needed
        // Helper methods
        void insert_all(const binary_tree_node<Item>* addroot_ptr);
    };
    // Functions for the multiset<Item> template class
    template <typename Item>
    multiset<Item> operator +(const multiset<Item>& m1, const multiset<Item>& m2);
}

#include "multiset.template"

#endif