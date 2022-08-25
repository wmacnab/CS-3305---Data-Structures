/*
Name: William MacNab
Date: September 30, 2021
Book: Data Structures and Other Objects Using C++ (Main & Savitch)
--- Chapter 6, Programming Project 9 ---
Revise the doubly linked-list implementa-
tion developed in Programming Project 15
in Chapter 5 to be a template class and use a
bidirectional iterator. You will need to provide the
decrement ( -- ) operator to move backward through
the list
--- Chapter 5, Programming Project 15 ---
Use a doubly linked list to implement the
sequence class from Section 5.4. With a
doubly linked list, there is no need to main-
tain a precursor. Your implementation should in-
clude a retreat member function that moves the
cursor backward to the previous element.
*/
// File: double_link_node.h
// Class implemented: 
// Namespace: wmacnab_6_9
/*
TYPEDEFS:
    typedef Item value_type;
        Item is the template parameter

Doubly Linked List Toolkit Functions:
// Insert
// Remove
// Length
// Copy
// Piece
// Search
// Locate

DYNAMIC MEMORY USAGE:
If there is insufficient dynamic memory, the following will throw bad_alloc:
list_insert(), list_head_insert()
*/

#ifndef WMACNAB_NODE_DOUBLY_LINKED_H
#define WMACNAB_NODE_DOUBLY_LINKED_H
#include <cstdlib>

namespace wmacnab_6_9
{
    template <typename Item>
    class double_link_node
    {
    public:
        // TYPEDEFS
        //typedef Item value_type;
        // CONSTRUCTOR
        double_link_node(const Item& init_value = Item(),
                        double_link_node* init_fore = NULL,
                        double_link_node* init_back = NULL)
        {
            data_value = init_value;
            fore_link = init_fore;
            back_link = init_back;
        }
        // MODIFICATION METHODS
        void set_fore(double_link_node* new_fore) { fore_link = new_fore; }
        void set_back(double_link_node* new_back) { back_link = new_back; }
        // These don't modify but non-const pointers may need to access links
        double_link_node* fore() { return fore_link; }
        double_link_node* back() { return back_link; }
        // CONSTANT METHODS
        Item& data() { return data_value; }
        const double_link_node* fore() const { return fore_link; }
        const double_link_node* back() const { return back_link; }
    private:
        Item data_value;
        double_link_node *fore_link;
        double_link_node *back_link;
    };
    template <typename Item>
    void list_insert(double_link_node<Item>* previous_ptr, const Item& entry);
    template <typename Item>
    void list_head_insert(double_link_node<Item>*& head_ptr, const Item& entry);
    template <typename Item>
    void list_remove(double_link_node<Item>* current_ptr);
    template <typename Item>
    void list_head_remove(double_link_node<Item>*& head_ptr);
    template <typename Item>
    size_t list_length(const double_link_node<Item>* any_ptr);
    template <typename Item>
    void list_clear(double_link_node<Item>*& any_ptr);

    // Iterator and const interator classes
    template <typename Item>
    class double_link_node_iterator : public std::iterator<std::bidirectional_iterator_tag, Item>
    {
    public:
        // CONSTRUCTOR
        double_link_node_iterator(double_link_node<Item>* init_current = NULL)
            { current = init_current; }
        // METHODS
        double_link_node_iterator& operator ++() // ++ Prefix
        {
            current = current->fore();
            return *this;
        }
        double_link_node_iterator operator ++(int) // Postfix ++
        {
            double_link_node_iterator original(current);
            current = current->fore();
            return original;
        }
        double_link_node_iterator& operator --() // -- Prefix
        {
            current = current->back();
            return *this;
        }
        double_link_node_iterator operator --(int) // Postfix --
        {
            double_link_node_iterator original(current);
            current = current->back();
            return original;
        }
        Item operator *() const
        {
            return current->data();
        }
        bool operator ==(const double_link_node_iterator other) const
        {
            return (current == other.current);
        }
        bool operator !=(const double_link_node_iterator other) const
        {
            return (current != other.current);
        }
    private:
        double_link_node<Item> *current;
    };

    template <typename Item>
    class const_double_link_node_iterator : public std::iterator<std::bidirectional_iterator_tag, Item>
    {
    public:
        // CONSTRUCTOR
        const_double_link_node_iterator(const double_link_node<Item>* init_current = NULL)
        { current = init_current; }
        // METHODS
        const_double_link_node_iterator& operator ++()
        {
            current = current->fore();
            return *this;
        }
        const_double_link_node_iterator operator ++(int)
        {
            const_double_link_node_iterator original(current);
            current = current->fore();
            return original;
        }
        const_double_link_node_iterator& operator --()
        {
            current = current->back();
            return *this;
        }
        const_double_link_node_iterator operator --(int)
        {
            const_double_link_node_iterator original(current);
            current = current->back();
            return original;
        }
        Item operator *() const
        {
            return current->data();
        }
        const_double_link_node_iterator operator ==(const const_double_link_node_iterator other) const
        {
            return (current == other.current);
        }
        const_double_link_node_iterator operator !=(const const_double_link_node_iterator other) const
        {
            return (current != other.current);
        }
    private:
        double_link_node<Item> *current;
    };
}
#include "double_link_node.template"
#endif

// Iterator Key Overloads:
// ++(), ++(int), *(), --(), --(int), ==(), !=()

// Doubly Linked List Toolkit Functions
// Insert
// Remove
// Length
// Copy
// Piece
// Search
// Locate