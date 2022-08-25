/*
File: deque.h
Namespace: wmacnab_8
Class: deque (a simple double-ended queue)

Value semantics:
the assignment operator and copy constructor are safe to use

Dynamic memory allocation:
If there is insufficient dynamic memory, the following may throw bad_alloc:
idk, idk
*/

#ifndef WMACNAB_DEQUE_H
#define WMACNAB_DEQUE_H

#include "node.h"

namespace wmacnab_8
{
    template <typename Item>
    class deque
    {
    public:
        // Constructors and destructor
        deque();
        deque(const deque& source);
        ~deque();
        // Modification methods
        void operator =(const deque& source);
        void push_front(const Item& entry);
        void push_back(const Item& entry);
        Item pop_front();
        Item pop_back();
        // Constant methods
        Item front() const;
        Item back() const;
        std::size_t size() const;
        bool empty() const;
    private:
        wmacnab_6::node<Item>* front_ptr;
        wmacnab_6::node<Item>* back_ptr;
        std::size_t count;
    };
}

#include "deque.template"

#endif