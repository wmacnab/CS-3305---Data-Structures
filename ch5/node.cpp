#include "node.h"

namespace wmacnab_5
{
    size_t list_length(const node* head_ptr)
    {
        size_t answer = 0;
        const node* cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link()) ++answer;
        return answer;
    }
    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    // Beautiful implementation of head_insert!
    {
        node *insert_ptr = new node(entry, head_ptr);
        head_ptr = insert_ptr;
        //head_ptr = new node(entry, head_ptr);
    }
    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
        node *insert_ptr = new node(entry, previous_ptr->link());
        previous_ptr->set_link(insert_ptr);
        // The following didn't work for some reason:
        //previous_ptr = new node(entry, previous_ptr->link());
    }
    node* list_search(node* head_ptr, const node::value_type& target)
    {
        node *cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        {
            if (cursor->data() == target) return cursor;
        }
        return NULL;
    }
    const node* list_search(const node* head_ptr, const node::value_type& target)
    {
        const node *cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        {
            if (cursor->data() == target) return cursor;
        }
        return NULL;
    }
    node* list_locate(node* head_ptr, size_t position)
    {
        size_t i = 1;
        node *cursor;
        for (cursor = head_ptr; cursor != NULL; ++i)
        {
            if (position == i) return cursor;
            cursor = cursor->link();
        }
        return NULL;
    }
    const node* list_locate(const node* head_ptr, size_t position)
    {
        size_t i = 1;
        const node *cursor;
        for (cursor = head_ptr; cursor != NULL; ++i)
        {
            if (position == i) return cursor;
            cursor = cursor->link();
        }
        return NULL;
    }
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    {
        // The NULL condition
        head_ptr = tail_ptr = NULL;
        if (source_ptr == NULL) return;
        // Copying the head to the new linked list
        list_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;
        // Inserting new nodes and moving the tail pointer one by one
        source_ptr = source_ptr->link();
        while(source_ptr != NULL)
        {
            list_insert(tail_ptr, source_ptr->data());
            tail_ptr = tail_ptr->link();
            source_ptr = source_ptr->link();
        }
    }
    void list_head_remove(node*& head_ptr)
    {
        node *remove_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete remove_ptr;
    }
    void list_remove(node* previous_ptr)
    {
        node *remove_ptr = previous_ptr->link();
        previous_ptr->set_link(remove_ptr->link());
        delete remove_ptr;
    }
    void list_clear(node*& head_ptr)
    {
        while (head_ptr != NULL) list_head_remove(head_ptr);
    }
    void list_piece(const node* start_ptr, const node* end_ptr, node*& head_ptr,  node*& tail_ptr)
    {
        head_ptr = tail_ptr = NULL;
        if (start_ptr == NULL) return;
        list_head_insert(head_ptr, start_ptr->data());
        tail_ptr = head_ptr;
        start_ptr = start_ptr->link();
        while (start_ptr != end_ptr)
        {
            list_insert(tail_ptr, start_ptr->data());
            start_ptr = start_ptr->link();
            tail_ptr = tail_ptr->link();
        }
    }
    void list_print(const node* head_ptr)
    {
        if (head_ptr == NULL) return;
        for (size_t i = 1; i <= list_length(head_ptr); ++i)
        {
            std::cout << list_locate(head_ptr, i)->data() << "\t";
        }
        std::cout << std::endl;
    }
}