#include <iostream>
#include "deque.h"
using namespace std;
using namespace wmacnab_8;
int main()
{
    cout << "If this compiles I poop my pants\n";
    deque<int> d;
    d.push_front(5);
    d.push_front(15);
    d.push_back(23);
    // 15, 5, 23
    cout << "The front is: " << d.front() << endl;
    cout << "The back is: " << d.back() << endl;
    return EXIT_SUCCESS;
}