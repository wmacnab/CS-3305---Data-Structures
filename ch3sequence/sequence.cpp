/*
FILE: sequence.cpp
CLASS IMPLEMENTED: sequence
NAMESPACE: wmacnab_3_sequence

INVARIANT of the sequence class:
1. The number of items in the sequence is stored in the member variable used
2. For an empty sequence, we do not care what is stored in any of data ; for
a non-empty sequence, the items are stored in their sequence order from
data[0] to data[used-1] , and we don’t care what is stored in the rest of
data.
3. If there is a current item, then it lies in data[current_index] ; if there is
no current item, then current_index equals used .
*/

#include <cassert>
#include "sequence.h"

namespace wmacnab_3_sequence
{
    const sequence::size_type CAPACITY = sequence::CAPACITY;

    sequence::sequence() { }

    void sequence::start()
    {
        current_index = 0;
    }

    void sequence::advance()
    {
        assert(is_item());
        ++current_index;
    }

    void sequence::insert(const sequence::value_type& entry)
    {
        assert(size() < CAPACITY);
        unsigned int pos = (current_index > 0) ? current_index - 1 : 0;
        for (unsigned int i = used; i > pos; --i)
        {
            data[i] = data[i - 1];
        }
        data[pos] = entry;
        used++;
    }

    void sequence::attach(const sequence::value_type& entry)
    {
        assert(size() < CAPACITY);
        unsigned int pos = (is_item()) ? 0 : current_index + 1;
        for (unsigned int i = used; i < pos; --i)
        {
            data[i] = data[i - 1];
        }
        data[pos] = entry;
        used++;
    }

    void sequence::remove_current()
    {
        assert(is_item());
        data[current_index] = data[used - 1];
        --used;
    }

    sequence::size_type sequence::size() const
    {
        return used;
    }

    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return data[current_index];
    }

    bool sequence::is_item() const
    {
        return (current_index == used);
    }
}