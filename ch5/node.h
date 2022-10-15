#ifndef WMACNAB_NODE_H
#define WMACNAB_NODE_H
#include <cstdlib>

namespace wmacnab_5
{
    class node
    {
    public:
        // TYPEDEF
        typedef double value_type;
        // CONSTRUCTOR
        node(const value_type& init_data = value_type(), node *init_link = NULL)
        {
            data_field = init_data;
            link_field = init_link;
        }
        // MODIFICATION METHODS
        void set_data(const value_type& new_value) { data_field = new_value; }
        void set_link(node* new_link) { link_field = new_link; }
        // CONSTANT METHODS
        value_type data() const { return data_field; }
        const node* link() const { return link_field; }
        // const pointers can use and the return value can't modify
        node* link() { return link_field; } // regular version
    private:
        node *link_field;
        value_type data_field;
        // I like the _field practice as this can be distinguished from methods
    };
    // LINKED LIST TOOLKIT FUNCTIONS
    size_t list_length(const node* head_ptr);
    // Since we are not going to change the list, the parameter is
    // a const pointer: const node*
    // Precondition: head_ptr is the head pointer to a linked list
    // Postcondition: returns the number of nodes in the linked list
    void list_head_insert(node*& head_ptr, const node::value_type& entry);
    // Precondition: head_ptr is the head pointer of a linked list
    // Postcondition: a new node containing the given entry has been ...
    // ... added at the head of the list. head_ptr now points to the head ...
    // ... of the new, longer linked list.
    // NOTE: if there is insufficient dynamic memory for a new node, then ...
    // ... bad_alloc is thrown
    void list_insert(node* previous_ptr, const node::value_type& entry);
    // Precondition: previous_ptr points to a node in a linked list
    // Postcondition: entry is inserted after previous_ptr
    node* list_search(node* head_ptr, const node::value_type& target);
    // Precondition: head_ptr points to the head node of a linked list
    // Postcondition: returns pointer to a node with the target, or NULL if not found
    // Uses: <cstdlib>
    const node* list_search(const node* head_ptr, const node::value_type& target);
    // Precondition: head_ptr points to the head node of a linked list
    // Postcondition: returns pointer to a node with the target, or NULL if not found
    // Uses: <cstdlib>
    node* list_locate(node* head_ptr, size_t position);
    const node* list_locate(const node* head_ptr, size_t position);
    // Precondition: head_ptr points to a head node in a linked list and position > 0
    // Postcondition: a pointer to the node at the given position is returned, where
    // counting starts at 1 at head_ptr. If the position doesn't exist, nullpointer
    // is returned
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
    // Precondition: source_ptr is the head pointer of a linked list
    // Postcondition: head_ptr and tail_ptr are the head and tail pointers for a new
    // list that contains the same items as the list pointed to by source_ptr
    // NOTE: if there is insufficient dynamic memory, bad_alloc is thrown
    void list_head_remove(node*& head_ptr);
    // Precondition: head_ptr points to the head node of a linked list
    // Postcondition: the head node has been removed and returned to the heap, and
    // head_ptr is now the head pointer of a new, shorter linked list
    void list_remove(node* previous_ptr);
    // Precondition: previous_ptr points to a node in a linked list and this is not
    // the tail node of the list
    // Postcondition: the node after previous_ptr has been removed from the linked list
    void list_clear(node*& head_ptr);
    // Precondition: head_ptr points to the head node of a linked list
    // Postcondition: All nodes of the list have been deleted and head_ptr is now NULL
    // Used: <cstdlib>
    void list_piece(const node* start_ptr, const node* end_ptr, node*& head_ptr, node*& tail_ptr);
    // Precondition: start_ptr and end_ptr are pointers to nodes of the same linked list, where
    // start_ptr is at or before end_ptr.
    // Postcondition: head_ptr and tail_ptr are the head and tail pointers for a new linked list
    // that contains items from start_ptr up to but not including end_ptr. The end_ptr may also
    // be NULL which means the new list contains nodes from start_ptr to the end of the list
    void list_print(const node* head_ptr);
    // Precondition: head_ptr is the head pointer of a linked list
    // Postcondition: The data of each node is printed to cout on one line
    // separated by horizontal tabs
}

#endif