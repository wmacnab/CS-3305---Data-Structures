#include <iostream>
#include <string>
#include <vector>
//#include "node.h"
#include "node.h"
#include "node.cpp"
#include "multiset.h"
#include "multiset.cpp"
#include "seq.h"
#include "seq.cpp"
using namespace wmacnab_5;
void t1();
void t2();
void t3();
void t4();
void t5();
void move_to_top(std::vector<std::string>& data, std::vector<std::string>::size_type index);

int main()
{
    t4();
    return EXIT_SUCCESS;
}

void move_to_top(std::vector<std::string>& data, std::vector<std::string>::size_type index)
{
    std::string s = data[index - 1];
    data[0] = s;
    for (std::size_t i = 0; i < data.size(); ++i)
    {
        data[i - 1] = data[i];
    }
}

void t5()
{
    std::vector<std::string> v = { "hello", "there", "friend", "how", "are", "you?" };
    move_to_top(v, 4);
    std::vector<std::string>::iterator it = v.begin();
    /*while (it != v.end())
    {
        std::cout << *v.data() << std::endl;
        ++it;
    }*/
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << "\t";
    }
    std::cout << std::endl;
}

void t4()
{
    sequence s;
    std::cout << s.current() << std::endl;
    s.insert(1.5);
    std::cout << s.current() << std::endl;
    s.attach(2.5);
    s.attach(3.5);
    s.attach(4.5);
    s.attach(5.5);
    std::cout << s.current() << std::endl;
    s.start();
    std::cout << s.current() << std::endl;
    s.advance();
    std::cout << s.current() << std::endl;
    s.insert(9.5);
    std::cout << s.current() << std::endl;
    s.start();
    s.advance();
    std::cout << s.current() << std::endl;
    //sequence s2(s);
    sequence s2 = s;
    s2.remove();

    std::cout << "Now printing s2:\n" << std::endl;
    s2.start();
    while (s2.is_item())
    {
        std::cout << s2.current() << std::endl;
        s2.advance();
    }

    std::cout << "Now printing s:\n" << std::endl;
    s.start();
    while (s.is_item())
    {
        std::cout << s.current() << std::endl;
        s.advance();
    }

    for (unsigned int i = 0; i < 15; ++i)
    {
        s.advance();
        if (i == 5) s.start();
        std::cout << s.current() << std::endl;
    }
}

void t3()
{
    multiset m1;
    m1.insert(1.5);
    m1.insert(2.5);
    m1.insert(3.5);
    m1.insert(1.5);
    multiset m2;
    m2.insert(5.5);
    m2.insert(7.5);
    m2.insert(1.5);
    m1 += m2;
    std::cout << "The size of m1 is: " << m1.size() << std::endl;
    std::cout << "1.5 occurs this many times: " << m1.count(1.5) << std::endl;
    std::cout << m1.size() << " and " << m1.size() << std::endl;
    std::cout << "Erased " << m1.erase_one(2.5) << std::endl;
    std::cout << "The size of m1 is: " << m1.size() << std::endl;
    std::cout << "Erased " << m1.erase(1.5) << std::endl;
    std::cout << "The size of m1 is: " << m1.size() << std::endl;
    //std::cout << "Erased " << m1.erase(1) << std::endl;
    std::cout << m1.size() << " and " << m1.size() << std::endl;
}

void t2()
{
    //node *l = new node();
    node *l = NULL;
    list_head_insert(l, 1.1);
    list_insert(l, 2.2);

    list_print(l);
}

void t1()
{
    node *l1, *l1e, *l2, *l2e;// = new node(0.3);
    l1 = new node(1.0);
    list_head_insert(l1, 0.9);
    list_head_insert(l1, 0.8);
    list_head_insert(l1, 0.7);
    l1e = l1;
    list_head_insert(l1, 0.6);
    list_head_insert(l1, 0.5);
    list_head_insert(l1, 0.4);
    list_head_insert(l1, 0.3);
    list_head_insert(l1, 0.2);
    list_head_insert(l1, 0.1);
    list_print(l1);
    list_piece(l1->link(), l1e, l2, l2e);
    list_print(l2);
    list_clear(l1);
    list_head_insert(l1, 2.5);
    list_print(l1);
}