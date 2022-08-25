// I finally figured out why including the header wouldn't work for my test programs.
// It's because I only declared the constructor in the header and I defined it in ...
// ... the implementation file.

#include <iostream>
#include "node.h"
#include "multiset.h"
using namespace wmacnab_6;

void t1();
void t2();
template <typename Item>
void multiset_print(multiset<Item> m);

int main()
{
    t2();
    return EXIT_SUCCESS;
}

void t2()
{
    std::cout << "Hi\n";
    multiset<int> m;
    m.insert(5);
    m.insert(3);
    m.insert(5);
    multiset_print(m);
    multiset<int> l;
    l = m + m;
    multiset_print(l);
}

void t1()
{
    //int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    //int *p = &arr[0];
    //++p;
    //int *p;
    //p = new int[10] { 9, 8, 7 };
    int *p = new int[5] { 7, 6, 5, 4, 3 };
    std::cout << p[0] << std::endl;
    ++p;
    std::cout << p[0] << std::endl;
    --p;
    int fa[10] { 6, 5, 4 };
    for (unsigned int i = 0; i < 10; ++i)
    {
        std::cout << fa[i] << "\t";
    }
    std::cout << std::endl;
    delete [] p;
}

template <typename Item>
void multiset_print(multiset<Item> m)
{
    typename multiset<Item>::iterator p = m.begin();
    typename multiset<Item>::iterator q = m.end();
    typename multiset<Item>::iterator r;
    for (r = p; r != q; ++r)
    {
        std::cout << *r << "\t";
    }
    std::cout << "\n";
}