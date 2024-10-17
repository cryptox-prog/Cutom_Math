#include "single.h"
#include "../../error_handling.h"
#include <stdlib.h>

/// @brief Adds a element to the beggining of the list
/// @param head (pointer to Node) The first element of the list, enter NULL if empty
/// @param data (int)
/// @return The new first element of the list
SLL_Node *SLL_add_to_begginging(SLL_Node *head, int data, int *error_code) {
    SLL_Node *new_head_node = (SLL_Node *)malloc(1 * sizeof(SLL_Node));
    if (new_head_node == NULL) {
        *error_code = ERR_MEM_ALLOC;
        return head;
    }
    new_head_node->data = data;
    new_head_node->next_node_ptr = head;
    return new_head_node;
}

/// @brief Adds a element to the end of the list
/// @param head (pointer to Node) The first element of the list
/// @param data (int)
/// @return The first element of the list
SLL_Node *SLL_append(SLL_Node *head, int data, int *error_code) {
    if (head == NULL) {
        // In case list is empty the last elemnt will just be the first element
        return SLL_add_to_begginging(head, data, error_code);
    }

    SLL_Node *current_node = head;
    SLL_Node *prev_node = (SLL_Node *)malloc(1 * sizeof(SLL_Node));
    SLL_Node *new_end_node = (SLL_Node *)malloc(1 * sizeof(SLL_Node));
    if ((prev_node == NULL) || (new_end_node == NULL)) {
        *error_code = ERR_MEM_ALLOC;
        return head;
    }
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

/// @brief Inserts a element at a given index
/// @param head The first element of the list
/// @param index The index at which the element will be inserted (starts from 0)
/// @param data (int)
/// @return The first element of the list
SLL_Node *SLL_insert(SLL_Node *head, int index, int data, int *error_code) {
    if (index == 0) {
        // In case index is 0 the new element will become head
        return SLL_add_to_begginging(head, data, error_code);
    }

    SLL_Node *new_node = (SLL_Node *)malloc(1 * sizeof(SLL_Node));
    if (new_node == NULL) {
        *error_code = ERR_MEM_ALLOC;
        return head;
    }
    new_node->data = data;

    SLL_Node *current_node = head;
    SLL_Node *next_node = current_node->next_node_ptr;

    int counter = 0;
    while ((current_node != NULL) && (counter > index - 1)) {
        current_node = current_node->next_node_ptr;
        next_node = current_node->next_node_ptr;
    }

    if (current_node == NULL) {
        *error_code = INDEX_OUT_OF_RANGE;
        return head;
    }

    current_node->next_node_ptr = new_node;
    new_node->next_node_ptr = next_node;

    return head;
}
