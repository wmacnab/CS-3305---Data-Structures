#ifndef _WMACNAB_NODE_H_
#define _WMACNAB_NODE_H_

namespace wmacnab_6
{
    template <typename Item>
    class node
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        //typedef size_t size_type;
        // CONSTRUCTORS
        //node(const Item& init_data = Item(), node* init_link = NULL);
        node(const Item& init_data = Item(), node* init_link = NULL)
        {
            data_field = init_data;
            link_field = init_link;
        }
        // MODIFICATION METHODS
        Item& data() { return data_field; }
        node* link() { return link_field; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_link(node* new_link) { link_field = new_link; }
        // CONSTANT METHODS
        const Item& data() const { return data_field; }
        const node* link() const { return link_field; }
    private:
        Item data_field;
        node *link_field;
    };
    // NodePtr may be either const node<Item>* or node<Item>*
    template <typename Item>
    std::size_t list_length(const node<Item>* head_ptr);

    template <typename NodePtr, typename SizeType> // NodePtr, I guess, will be: node *head_ptr?
    NodePtr list_locate(NodePtr head_ptr, SizeType position);

    template <typename Item>
    void list_clear(node<Item>*& head_ptr);

    template <typename Item>
    void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);

    template <typename Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry);

    template <typename Item>
    void list_head_remove(node<Item>*& head_ptr);

    template <typename Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry);

    template <typename Item>
    void list_remove(node<Item>* previous_ptr);

    template <typename NodePtr, typename Item>
    NodePtr list_search(NodePtr head_ptr, const Item& target);

    // ITERATOR
    template <typename Item>
    class node_iterator : public std::iterator<std::forward_iterator_tag, Item>
    {
    public:
        node_iterator(node<Item>* initial = NULL) { current = initial; }
        Item& operator *() const { return current->data(); }
        node_iterator& operator ++() // Prefix ++
        {
            current = current->link();
            return *this;
        }
        node_iterator operator ++(int) // Postfix ++
        {
            node_iterator original(current);
            current = current->link();
            return original;
        }
        bool operator ==(const node_iterator other) const
        {
            return (current == other.current);
        }
        bool operator !=(const node_iterator other) const
        {
            return (current != other.current);
        }
    private:
        node<Item>* current;
    };
    template <typename Item>
    class const_node_iterator
    {
    public:
        const_node_iterator(const node<Item>* initial = NULL) { current = initial; }
        // Operators *, ++ prefix, postfix ++, ==, !=
        Item operator *() const { return current->data(); }
        const_node_iterator& operator ++()
        {
            current = current->link();
            return *this;
        }
        const_node_iterator operator ++(int)
        {
            const_node_iterator original(current);
            current = current->link();
            return original;
        }
        bool operator ==(const const_node_iterator other) const { return (current == other.current); }
        bool operator !=(const const_node_iterator other) const { return (current != other.current); }
    private:
        const node<Item>* current;
    };
}

#include "node.template"
#endif