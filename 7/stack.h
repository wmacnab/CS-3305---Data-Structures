/*
FILE: stack.h
CLASS: stack
NAMESPACE: wmacnab_7

VALUE SEMANTICS:
The assignment operator and copy constructor are safe to use

DYNAMIC MEMORY ALLOCATION:
If there is insufficient dynamic memory, the following may throw bad_alloc:
idk, idk
*/

#ifndef WMACNAB_STACK_H
#define WMACNAB_STACK_H

#include "node.h"

namespace wmacnab_7
{
    template <typename Item>
    class stack
    {
    public:
        // CONSTRUCTORS
        stack();
        stack(const stack& source);
        ~stack();
        // MODIFICATION METHODS
        Item pop();
        void push(const Item& entry);
        void operator =(const stack& other);
        // CONSTANT METHODS
        Item top() const;
        bool is_empty() const;
        std::size_t size() const;
    private:
        wmacnab_6::node<Item>* head_ptr;
    };
}

#include "stack.template"
#endif