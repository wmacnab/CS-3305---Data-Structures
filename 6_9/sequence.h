/*
File: sequence.h
Class: sequence
Namespace: wmacnab_6_9

MODIFICATION METHODS:
void start()
void advance()
void insert()
void attach()
void remove()

CONSTANT METHODS:
Item current()

DYNAMIC MEMORY ALLOCATION for the sequence class:
If there is unsufficient dynamic memory, the following may throw bad_alloc:
idk, idk

VALUE SEMANTICS for the sequence class:
The assignment operator and copy constructor are safe to use.
*/
// Hallelujah, Christ will come again.
#ifndef WMACNAB_SEQUENCE_H
#define WMACNAB_SEQUENCE_H
#include "double_link_node.h"
namespace wmacnab_6_9
{
    template <typename Item>
    class sequence
    {
    public:
        // TYPEDEF statements
        typedef Item value_type;
        typedef double_link_node_iterator<Item> iterator;
        typedef const_double_link_node_iterator<Item> const_iterator;
        // CONSTRUCTORS
        sequence();
        sequence(const sequence& source);
        ~sequence();
        // MODIFICATION METHODS
        void operator =(const sequence& source);
        void start();
        void advance();
        void retreat();
        void insert(const Item& entry);
        void attach(const Item& entry);
        void remove();
        // CONSTANT METHODS
        Item current() const;
        double_link_node_iterator<Item> begin() const;
        double_link_node_iterator<Item> end() const;
        //const_double_link_node_iterator<Item> begin() const;
        //const_double_link_node_iterator<Item> end() const;
    private:
        double_link_node<Item> *head_ptr;
        //double_link_node<Item> *tail_ptr;
        double_link_node<Item> *current_ptr;
        //double_link_node<Item> *head_ptr;
        //double_link_node<Item> *current_ptr;
    };
}
#include "sequence.template"
#endif