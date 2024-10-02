#include "single.h"
#include <stdlib.h>

/// @brief Adds a element to the beggining of the list
/// @param head (pointer to Node) The first element of the list, enter NULL if empty
/// @param data (int)
/// @return The new first element of the list
SLL_Node *SLL_add_to_begginging(SLL_Node *head, int data) {
    SLL_Node *new_head_node;
    new_head_node->data = data;
    new_head_node->next_node_ptr = head;
    return new_head_node;
}

/// @brief Adds a element to the end of the list
/// @param head (pointer to Node) The first element of the list
/// @param data (int)
/// @return The first element of the list
SLL_Node *SLL_append(SLL_Node *head, int data) {
    if (head == NULL) {
        // In case list is empty the last elemnt will just be the first element
        return SLL_add_to_begginging(head, data);
    }

    SLL_Node *current_node = head;
    SLL_Node *prev_node;
    SLL_Node *new_end_node = (SLL_Node *)malloc(1 * sizeof(SLL_Node));
    new_end_node->data = data;

    new_end_node->next_node_ptr = NULL;

    while (current_node != NULL) {
        // Get to the last element
        prev_node = current_node;
        current_node = current_node->next_node_ptr;
    }

    prev_node->next_node_ptr = new_end_node;
    return head;
}

/// @brief 
/// @param head 
/// @param index 
/// @param data 
/// @return 
SLL_Node *SLL_insert(SLL_Node *head, int index, int data) {
    if (index == 0) {
        // In case index is 0 the new element will become head
        return SLL_add_to_begginging(head, data);
    }

    SLL_Node *new_node = (SLL_Node *)malloc(1 * sizeof(SLL_Node));
    new_node->data = data;

    SLL_Node *current_node = head;
    SLL_Node *next_node = current_node->next_node_ptr;

    int counter = 0;
    while ((current_node != NULL) && (counter > index - 1)) {
        current_node = current_node->next_node_ptr;
        next_node = current_node->next_node_ptr;
    }

    if (current_node == NULL) {
        // The index is out of range
        return head;
    }

    current_node->next_node_ptr = new_node;
    new_node->next_node_ptr = next_node;

    return head;
}
