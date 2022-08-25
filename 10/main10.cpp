#include  <iostream>
//#include "exptree.h"
#include "bintree.h"
#include "multiset.h"
using namespace wmacnab_10;
void f(int& n)
{
    n = 0;
}
int main()
{
    //
    multiset<int> m1;
    m1.insert(7);
    m1.insert(4);
    m1.insert(9);
    m1.insert(2);
    m1.insert(3);
    m1.insert(5);
    binary_tree_node<int>* arr[m1.size()];
    arr = m1.size();
    return EXIT_SUCCESS;
}