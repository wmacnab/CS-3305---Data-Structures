/*
File: bintree.h
Namespace: wmacnab_10
Class: binary_tree_node

// Dynamic memory usage:
*/

#ifndef WMACNAB_BINTREE_H
#define WMACNAB_BINTREE_H

#include <iostream>
#include <iomanip>

namespace wmacnab_10
{
    template <typename Item>
    class binary_tree_node
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        typedef int size_type;
        // CONSTRUCTOR
        binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
        {
            data_field = init_data;
            left_field = init_left;
            right_field = init_right;
        }
        // MODIFICATION METHODS
        Item& data() { return data_field; }
        binary_tree_node*& left() { return left_field; }
        binary_tree_node*& right() { return right_field; }
        // CONSTANT METHODS
        const Item& data() const { return data_field; }
        const binary_tree_node* left() const { return left_field; }
        const binary_tree_node* right() const { return right_field; }
        bool is_leaf() const
        {
            return (left_field == NULL) && (right_field == NULL);
        }
        size_type kids() const
        {
            size_type answer = 0;
            if (left() != NULL) answer++;
            if (right() != NULL) answer++;
            return answer;
        }
    private:
        Item data_field;
        binary_tree_node *left_field;
        binary_tree_node *right_field;
    };
    // Binary Tree Toolkit
    template <typename Item>
    void tree_clear(binary_tree_node<Item>*& root_ptr);
    // Precondition: root_ptr is the root pointer of a binary tree (which may be NULL for ...
    // ... the empty tree)
    // Postcondition: All nodes at the root or below have been returned to the heap, ...
    // ... and root_ptr has been set to null
    template <typename Item>
    binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr);
    // Precondition: root_ptr is the root pointer of a binary tree (which may be NULL for ...
    // ... the empty tree)
    // Postcondition: A copy of the binary tree has been made, and the return value is ...
    // ... a pointer to the root of this copy
    template <typename Item>
    typename binary_tree_node<Item>::size_type tree_depth(const binary_tree_node<Item>* root_ptr);
    // Postcondition: The return value is the depth of the tree, with the empty tree being -1,
    // a single node tree being 0, and then every subsequent level adding 1.
    template <typename Item>
    typename binary_tree_node<Item>::size_type tree_size(const binary_tree_node<Item>* root_ptr);
    // Postcondition: The return value is the number of nodes in the tree, root inclusive
    template <typename Item>
    void tree_print(const binary_tree_node<Item>* root_ptr, typename binary_tree_node<Item>::size_type depth);
    // Postcondition: The tree is printed with indentations in a backwards pre-order traversal.
    // This is useful for debugging.
    template <typename Process, typename BTNode>
    void tree_preorder(Process f, BTNode* node_ptr);
    // Precondition: node_ptr is a pointer to a node in a binary tree (or NULL to indicate empty tree)
    // Postcondition: If node_ptr is non-NULL, then the function f has been applied to the contents
    // of *node_ptr and all its descendants, using a pre-order traversal.
    // Note: BTNode may be a binary_tree_node or a const binary tree node
    // Process is the type of function that may be called with a single Item argument,
    // with Item being from the binary tree node class.
    template <typename Process, typename BTNode>
    void tree_inorder(Process f, BTNode* node_ptr);
    template <typename Process, typename BTNode>
    void tree_postorder(Process f, BTNode* node_ptr);
}

#include "bintree.template"

#endif