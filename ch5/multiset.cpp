/*
FILE: multiset.cpp
CLASS IMPLEMENTED: multiset
NAMESPACE: wmacnab_5

INVARIANT for the multiset class:
1. The elements of the multiset are stored in a linked list
2. The head pointer of the linked list is stored in the member variable head_ptr
3. The total number of elements in the linked list is stored in the member variable many_nodes
*/

#include <cstdlib>
#include "multiset.h"

namespace wmacnab_5
{
    // CONSTRUCTORS AND DESTRUCTOR
    multiset::multiset()
    {
        head_ptr = NULL;
        many_nodes = 0;
    }
    multiset::multiset(const multiset& source)
    {
        node *tail_ptr = NULL;
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
    }
    multiset::~multiset()
    {
        list_clear(head_ptr);
        many_nodes = 0; // No need for this line, but it adds clarity
    }
    // MODIFICATION METHODS
    multiset::size_type multiset::erase(const value_type& target)
    {
        size_type i = 0;
        while (list_search(head_ptr, target) != NULL)
        {
            if (erase_one(target)) ++i; // This decrements many_nodes
        }
        return i;
    }
    bool multiset::erase_one(const value_type& target)
    {
        node *delete_ptr = list_search(head_ptr, target);
        if (delete_ptr == NULL) return false;
        delete_ptr->set_data(head_ptr->data());
        list_head_remove(head_ptr);
        --many_nodes;
        return true;
    }
    void multiset::insert(const value_type& entry)
    {
        list_head_insert(head_ptr, entry);
        ++many_nodes;
    }
    void multiset::operator +=(const multiset& addend)
    {
        *this = *this + addend;
    }
    void multiset::operator =(const multiset& source)
    {
        node *tail_ptr = NULL; // Needed for argument to list_copy

        if (this == &source) return;

        list_clear(head_ptr);
        many_nodes = 0; // We want the object to be valid whenever we ...
        // ... call methods that allocate dynamic memory, so we set many_nodes ...
        // ... to zero before calling list_copy

        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
    }
    // CONSTANT METHODS
    multiset::size_type multiset::size() const
    {
        return many_nodes;
    }
    multiset::size_type multiset::count(const value_type& target) const
    {
        size_type answer = 0;
        node *cursor;
        for (cursor = list_search(head_ptr, target); cursor != NULL; cursor = list_search(cursor, target))
        {
            ++answer;
            cursor = cursor->link();
        }
        return answer;
    }
    multiset::value_type multiset::grab() const
    {
        if (size() < 1) return 0;
        size_type i = (rand() % size()) + 1;
        node *cursor;
        cursor = list_locate(head_ptr, i);
        return cursor->data();
    }
    // FUNCTION
    multiset operator +(const multiset& ms1, const multiset& ms2)
    {
        multiset sum = ms1;
        const node *cursor;
        for (cursor = ms2.head_ptr; cursor != NULL; cursor = cursor->link())
        {
            list_head_insert(sum.head_ptr, cursor->data());
            ++sum.many_nodes;
        }
        return sum;
    }
}