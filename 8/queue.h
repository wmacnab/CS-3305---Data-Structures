/*
FILE: queue.h
NAMESPACE: wmacnab_8
CLASS: queue

VALUE SEMANTICS for the queue class:
The assignment operator and copy constructor are safe to use

DYNAMIC MEMORY ALLOCATION for the queue class:
If there is insufficient dynamic memory, the following may throw bad_alloc:
idk, idk
*/

#ifndef WMACNAB_QUEUE_H
#define WMACNAB_QUEUE_H

#include "node.h"

namespace wmacnab_8
{
    template <typename Item>
    class queue
    {
    public:
        // Constructors and destructor
        queue();
        queue(const queue& source);
        ~queue();
        // Modification methods
        void push(const Item& entry);
        Item pop();
        void operator =(const queue& source);
        // Constant methods
        Item front() const;
        bool empty() const;
        std::size_t size() const;
    private:
        wmacnab_6::node<Item>* front_ptr;
        wmacnab_6::node<Item>* rear_ptr;
        std::size_t count;
    };
}

#include "queue.template"

#endif