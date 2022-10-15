

#ifndef WMACNAB_SEQUENCE_H
#define WMACNAB_SEQUENCE_H
#include <cstdlib> // Provides size_t

namespace wmacnab_3_sequence
{
    class sequence
    {
    public:
        // TYPEDEFS and CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;

        // CONSTRUCTORS
        sequence();

        // MODIFICATION METHODS
        void start();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();

        // CONSTANT METHODS
        size_type size() const;
        value_type current() const;
        bool is_item() const;
        
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
}

#endif