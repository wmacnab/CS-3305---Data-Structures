/*
Write a recursive function that has two
inputs, first and second , which are both
strings (from <string> ). The function
should print all rearrangements of the letters in
first , followed by second . For example, if first
is the string "CAT" and second is the string "MAN" ,
then the function would print the strings CATMAN ,
CTAMAN , ACTMAN , ATCMAN , TACMAN , and TCAMAN . The
stopping case of the function occurs when the length
of first has zero characters. We’ll leave the recur-
sive thinking up to you, but we should mention that
two string member functions will make things go
smoother. These member functions are
3
void string::insert(
size_type position,
size_type number_of_copies,
char c
);
// Postcondition: The specified number of
// copies of c have been inserted into the
// string at the indicated position. Chars
// that used to be at or after the given
// position have been shifted right one spot.
void string::erase
(size_type position, size_type n);
// Postcondition: n characters have been
// removed from the string, beginning at the
// specified position.
*/
#include <iostream>
#include <string>
using namespace std;
void stringaling(string first, string second)
{
    //cout << first << second << endl;
    //first.insert(0, 1, first[first.length()-1]);
    //first.erase(first.length()-1, 1);
    //stringaling(first, second);
    // 1. ???
    // How do I check that a string has been printed with every combination recursively?
}
int main()
{
    string pizza = "pizza";
    cout << pizza.substr(2, 2) << endl;
    return EXIT_SUCCESS;
}