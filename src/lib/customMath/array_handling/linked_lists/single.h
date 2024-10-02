#ifndef SINGLE_H
#define SINGLE_H

typedef struct SLL_Node {
    int data;
    struct SLL_Node *next_node_ptr;
} SLL_Node;


SLL_Node *SLL_add_to_begginging(SLL_Node *head, int data);
SLL_Node *SLL_append(SLL_Node *head, int data);
SLL_Node *SLL_insert(SLL_Node *head, int index, int data);
SLL_Node *SLL_remove(SLL_Node *head, int index);
SLL_Node *SLL_remove_data(SLL_Node *head, int data);
SLL_Node *SLL_convert_to_array(SLL_Node *head, int *return_array);
SLL_Node *SLL_create_from_array(SLL_Node *head, int *input_array);
SLL_Node *SLL_reverse(SLL_Node *head);
int SLL_count(SLL_Node *head); 
void SLL_free_all_nodes(SLL_Node *head);

#endif
