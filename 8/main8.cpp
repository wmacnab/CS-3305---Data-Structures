#include <iostream>
#include "queue.h"
using namespace wmacnab_8;

int main()
{
    std::cout << "Hey." << std::endl;
    queue<int> q;
    q.push(5);
    q.push(10);
    q.pop();
    q.pop();
    q.pop();
    queue<int> q2;
    q2.push(13);
    q = q2;
    std::cout << q.front() << std::endl;
    return EXIT_SUCCESS;
}