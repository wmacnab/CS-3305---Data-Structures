/*
FILE: mystring.cpp
CLASS IMPLEMENTED: string (a simple version of the STL string class)
NAMESPACE: wmacnab_4
*/

/*
INVARIANT of the string class:
1. The string is stored in a dynamically allocated cstring that characters points to.
2. The total length of the dynamic array is stored in allocated.
3. The number of characters in the string = current_length < allocated.
*/

#include "mystring.h"
#include <cstring>

namespace wmacnab_4
{
    // CONSTRUCTORS
    string::string(const char str[]/* = ""*/)
    {
        current_length = strlen(str);
        allocated = current_length + 1;
        characters = new char[allocated];
        strcpy(characters, str);
    }
    string::string(const char c)
    {
        current_length = 1;
        allocated = 2;
        characters = new char[allocated];
        characters[0] = c;
    }
    string::string(const string& source)
    {
        current_length = source.length();
        allocated = current_length + 1;
        characters = new char[allocated];
        strcpy(characters, source.characters);
    }
    string::~string()
    {
        delete [] characters;
    }

    // MODIFICATION METHODS
    /*
    void string::insert(const string& source, size_type pos)
    {
        if (pos < 0) return;
        if (pos >= source.current_length) pos = current_length;
        source.allocated
    }*/
    void string::reserve(size_type n)
    {
        if (n <= allocated) return; // Not increasing allocation, so return.
        char *bigger_cstring;
        bigger_cstring = new char[n];
        strcpy(bigger_cstring, characters);
        delete [] characters;
        characters = bigger_cstring;
        allocated = n;
    }
    void string::operator +=(const string& addend)
    {
        size_type newlen = length() + addend.length();
        if (allocated <= newlen) reserve(newlen + 1);
        strcat(characters, addend.characters);
        current_length = newlen;
    }
    void string::operator +=(const char addend[])
    {
        size_type newlen = length() + strlen(addend);
        if (allocated <= newlen) reserve(newlen + 1);
        strncat(characters, addend, strlen(addend));
        current_length = newlen;
    }
    void string::operator +=(char addend)
    {
        size_type newlen = length() + 1;
        if (allocated <= newlen) reserve(newlen + 1);
        characters[current_length] = addend;
        current_length = newlen;
    }
    void string::operator =(const string& source)
    {
        if (this == &source) return; // Check for a case of self-equality
        if (allocated <= source.length()) reserve(source.length() + 1);
        strcpy(characters, source.characters);
        current_length = source.length();
    }
    // CONSTANT METHODS
    char string::operator [](size_type pos) const
    {
        if (pos < 0 || pos >= length()) return '\0';
        return characters[pos];
    }

    // FUNCTIONS
    bool operator ==(const string& s1, const string& s2)
    {
        return (strcmp(s1.characters, s2.characters) == 0);
    }
    string operator +(const string& s1, const string& s2)
    {
        // Create and return a new string object with the new cstring
        string sum(strcat(s1.characters, s2.characters));
        return sum;
    }
    std::ostream& operator <<(std::ostream& outs, const string& source)
    {
        outs << source.characters;
        return outs;
    }
    std::istream& operator >>(std::istream& ins, string& target)
    {
        while (ins && isspace(ins.peek())) ins.ignore();
        target = "";
        for (string::size_type i = 0; ins && isalpha(ins.peek()); ++i)
        {
            if (target.allocated <= i + 1) target.reserve(i + 1);
            target += ins.get();
        }
        return ins;
    }
    std::istream& getline(std::istream& ins, string& target, char delimiter = '\n')
    {
        target = "";
        for (string::size_type i = 0; ins && ins.peek() != delimiter; ++i)
        {
            if (target.allocated <= i) target.reserve(i + 1);
            target += ins.get();
        }
        return ins;
    }
}