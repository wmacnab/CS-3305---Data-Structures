/*
File: exptree.h
Class: exptree (an expression tree)
Namespace: wmacnab_10

Description: This is a class for expression trees using binary_tree_node from bintree.h.
An expression tree has two kinds of nodes:
    1. Leaf nodes, which contain a real number as their entry
    2. Nonleaf nodes, which contain either the chatacter + or * as their entry, and have ...
    ... exatly two children.

This class implements operations for building expression trees.
Also included is a recursive function to evaluate a non-empty expression tree using these rules:
    1. If the tree has only one node, the real number in the root is returned.
    2. If there is more than one node and the root is +, evaluate left subtree then ...
    right subtree and add the results. If the root is *, then evaluate the two subtrees ...
    ... and multiply the results

My design:
void insert_operator(char op)
Postcondition: The operator has been

void insert_number(const value_type& entry)
Precondition: idk

void insert_star()

void insert_plus()

2 3 7 + * 4 -
*/

#ifndef WMACNAB_EXPTREE_H
#define WMACNAB_EXPTREE_H

#include <string>
#include "bintree.h"

namespace wmacnab_10
{
    class exptree
    {
    public:
        // Typedefs
        typedef int value_type;
        typedef typename bintree<value_type>::size_type size_type;
        // Constructors and destructor
        exptree(const std::string& prefix_expression);
        exptree(const exptree& source);
        ~exptree();
        // Modification methods
        void insert_num(const value_type& entry);
        void insert_plus();
        void insert_star();
        // Constant methods
    private:
        binary_tree_node<value_type> root_ptr;
    };
}

#endif