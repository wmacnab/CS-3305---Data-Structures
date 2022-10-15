/*
FILE: mystring.h
CLASS IMPLEMENTED: string (a simple version of STL string class)
NAMESPACE: wmacnab_4
*/

#ifndef WMACNAB_MYSTRING_H
#define WMACNAB_MYSTRING_H
#include <iostream>
#include <cctype>

namespace wmacnab_4
{
    class string
    {
    public:
        // DECLARATIONS
        typedef std::size_t size_type;
        // CONSTRUCTORS and DESTRUCTORS
        string(const char str[] = "");
        string(const char c);
        string(const string& source); // Copy constructor (using dynamic member variables)
        ~string(); // Destructor (using dynamic member variables)
        // MODIFICATION METHODS
        void insert(const string& source, size_type pos);
        void reserve(size_type n);
        void operator +=(const string& addend);
        void operator +=(const char addend[]);
        void operator +=(char addend);
        void operator =(const string& source);
        // Operators to overload: += (x3), +, ==, [], <<, >>, also a getline with istream
        // CONSTANT METHODS
        size_type length() const { return current_length; }
        char operator [](size_type pos) const;
        // FRIEND FUNCTIONS
        friend std::ostream& operator <<(std::ostream& outs, const string& source);
        friend string operator +(const string& s1, const string& s2);
        friend bool operator ==(const string& s1, const string& s2);
        friend std::istream& operator >>(std::istream& ins, string& target);
        friend std::istream& getline(std::istream& ins, string& target, char delimiter/* = '\n'*/);
    private:
        char *characters;
        size_type allocated;
        size_type current_length;
    };
    std::ostream& operator <<(std::ostream& outs, const string& source);
}
#endif