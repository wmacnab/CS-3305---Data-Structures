#include <iostream>
#include "stack.h"
using namespace wmacnab_7;

int main()
{
    std::cout << "Hey." << std::endl;
    stack<int> s;
    s.push(5);
    s.push(13);
    stack<int> s2;
    s2 = s;
    s2.pop();
    std::cout << s.top() << std::endl;
    std::cout << s2.top() << std::endl;
    std::cout << s.size() << std::endl;
    return EXIT_SUCCESS;
}