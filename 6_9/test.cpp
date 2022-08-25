#include <iostream>
#include "sequence.h"
using namespace wmacnab_6_9;

void printit(sequence<int>& s)
{
    typename sequence<int>::iterator i;
    std::cout << "Printing: ";
    for (i = s.begin(); i != s.end(); ++i)
    {
        std::cout << *i << "\t";
    }
    std::cout << std::endl;
}
void pback(sequence<int>& s)
{
    typename sequence<int>::iterator i;
    i = s.begin();
    ++i;++i;
    std::cout << "Printing: ";
    for (int j = 0; j < 2; --i)
    {
        std::cout << *i << "\t";
    }
    std::cout << std::endl;
}

void t1()
{
    sequence<int> s1;
    s1.attach(10);
    s1.attach(5);
    s1.attach(20);
    typename sequence<int>::iterator i;
    i = s1.begin();
    std::cout << *i << "\t";
    ++i;
    std::cout << *i << "\t";
    ++i;
    std::cout << *i << "\t";
    --i;
    std::cout << *i << "\t";
    --i;
    std::cout << *i << "\t";
    --i;
    --i;
    //std::cout << *i << "\t";
}

/*void pl(double_link_node<int>* m)
{
    std::cout << "Printing: ";
    for (; m != NULL; m = m->fore())
    {
        std::cout << m->data() << "\t";
    }
    std::cout << "\n";
}*/
int main()
{
    t1();
    /*std::cout << "Hey\n";
    double_link_node<int> *l = NULL, *m = NULL;
    list_head_insert(l, 1);
    list_insert(l, 3);
    list_insert(l, 2);
    list_copy(l, m);
    pl(l);
    list_insert(m, 382938);
    list_clear(m);
    pl(m);*/
    return EXIT_SUCCESS;
}