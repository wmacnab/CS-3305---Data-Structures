// FILE: test.cpp
// A versatile test program to test C++ code I work with.
// To use, implement display_menu() and select(char c) along with the
// desired functionality for each switch case. The menu already includes
// a menu header and footer along with the option 'Q' to quit the program.
// Implement these in a different file and include it here for modular testing.

//#include <iostream>
//#include <cctype> // Provides char toupper(char c)
//#include "mystring.cpp"
//using namespace wmacnab_4;

//#include "set.cpp"
//using namespace wmacnab_3_5;

//void display_menu();
// Postcondition: All desired functionalities are printed line by line including
// the key the user needs to press to activate the function. These keys need to
// be correctly mapped to the select(char c) function.

//void select(char c);
// Contains selection statements, usually a switch statement, to decide which
// implemented functionality to test.

/*
char get_user_input()
{
    char c;
    std::cin >> c; // Input of characters skips blanks and newline characters
    return c;
}

void display_menu_top()
{
    std::cout << std::endl;
    std::cout << "-----MENU-----" << std::endl;
    std::cout << "Q) Exit" << std::endl;
    std::cout << "1) Say \"Hello World!\"" << std::endl;
}

void display_menu_bottom()
{
    std::cout << std::endl;
}
*/

/*
void test_program_menu()
{
    char user_input;
        do
        {
            display_menu_top();
            display_menu();
            display_menu_bottom();
            user_input = toupper(get_user_input());
            select(user_input);
        } while (user_input != 'Q');
}*/

/*
void test_set()
{
    set s1;
    s1.insert(1);
    s1.insert(3);
    s1.insert(5);
    s1.remove(3);
    std::cout << s1 << std::endl;
}
*/

#include <iostream>
#include "poly.h"
using namespace wmacnab_4_poly;

int main()
{
    poly p1;
    p1.assign_coef(1, 32);
    p1.assign_coef(4, 3);
    p1.assign_coef(2, 2);
    p1.assign_coef(5, 1);
    p1.assign_coef(15, 0);
    p1.add_to_coef(3, 5);
    std::cout << p1 << std::endl;
    std::cout << "Evaluating the following for x = 1: " << p1(1) << std::endl;
    std::cout << "The derivative is: " << p1.derivative() << std::endl;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
