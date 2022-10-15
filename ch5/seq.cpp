/*
FILE: seq.cpp
CLASS IMPLEMENTED: sequence
NAMESPACE: wmacnab_5

INVARIANT of the sequence class:
    1. The elements are stored in a particular order within a linked list
    2. head_ptr always points to the head node and tail_ptr always points to the tail node
    3. cursor always points to the current node or NULL if there is no current node
    4. precursor always points to the node before the current node, or NULL ...
    ... if the current node is the head node or if there is no current node
    4. The number of elements is stored in many_nodes
*/

#include "seq.h"

namespace wmacnab_5
{
    // CONSTRUCTORS
    sequence::sequence()
    {
        head_ptr = tail_ptr = cursor = precursor = NULL;
        many_nodes = 0;
    }
    sequence::sequence(const sequence& source)
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        start();
        tail_ptr = list_locate(head_ptr, many_nodes + 1);
    }
    sequence::~sequence()
    {
        list_clear(head_ptr); // Sets head_ptr to NULL
        tail_ptr = cursor = precursor = head_ptr; // This line is unnecessary but adds clarity
        many_nodes = 0; // This line is unnecessary but adds clarity
    }
    // MODIFICATION METHODS
    void sequence::start()
    {
        cursor = head_ptr;
        precursor = NULL;
    }
    void sequence::advance()
    {
        if (!is_item()) return;
        else if (cursor == head_ptr)
        {
            precursor = cursor;
            cursor = cursor->link();
        }
        else
        {
            precursor = precursor->link();
            cursor = cursor->link();
        }
    }
    void sequence::insert(const value_type& entry)
    {
        if (head_ptr == NULL)
        {
            list_head_insert(head_ptr, entry);
            ++many_nodes;
            start();
        }
        else if (precursor != NULL) list_insert(precursor, entry);
        else
        {
            list_head_insert(head_ptr, entry);
            ++many_nodes;
            precursor = cursor;
            cursor = cursor->link();
        }
        tail_ptr = list_locate(head_ptr, many_nodes + 1);
    }
    void sequence::attach(const value_type& entry)
    {
        if (!is_item()) return;
        else if (head_ptr == NULL)
        {
            list_head_insert(head_ptr, entry);
            ++many_nodes;
            start();
        }
        else
        {
            list_insert(cursor, entry);
            ++many_nodes;
            precursor = cursor;
            cursor = cursor->link();
        }
        tail_ptr = list_locate(head_ptr, many_nodes + 1);
    }
    void sequence::remove()
    // Precondition: is_item() returns true
    // Postcondition: the current item is removed, and the new current item becomes
    // the proceeding item if it exists. If it doesn't, the preceeding item is the
    // current item. If the item removed is the head and there's no proceeding item,
    // all pointers are set to null. Decrement many nodes.
    {
        if (!is_item()) return;
        if (cursor == head_ptr)
        {
            list_head_remove(head_ptr);
            --many_nodes;
            start();
        }
        else
        {
            list_remove(precursor);
            --many_nodes;
            cursor = precursor->link();
        }
        tail_ptr = list_locate(head_ptr, many_nodes + 1);
    }
    void sequence::operator =(const sequence& source)
    {
        if (head_ptr == source.head_ptr) return;
        list_clear(head_ptr);
        many_nodes = 0;
        node *tail_ptr;
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        start();
        tail_ptr = list_locate(head_ptr, many_nodes + 1);
    }
    // CONSTANT METHODS
    sequence::value_type sequence::current() const
    {
        if (!is_item()) return value_type();
        return cursor->data();
    }
    bool sequence::is_item() const
    {
        if (cursor != NULL) return true;
        return false;
    }
}