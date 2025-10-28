#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    if (head == NULL){
        return NULL;
    }
    return head;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if( head == NULL){
        return NULL;
    }
    struct ll_node *current = head;
    while (current->next != NULL){
        current = current->next;
    }
    return current;
}

/**
 * TODO: Describe what the function does
 */
int ll_size(struct ll_node *head) {
  int count =0;
  struct ll_node *current = head;

  while (current != NULL){
    count ++;
    current = current ->next;

  }
            return count;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
   if (head == NULL){
    return NULL;
   }

   struct ll_node *current = head;

   while (current != NULL){
    if (current->data == value){
        return current;
    }
    current = current ->next;
   }
   return NULL;
}

/**
 * TODO: Describe what the function does
 */
int *ll_toarray(struct ll_node *head) {
   if (head == NULL){
    return NULL;
   }

   int size = 0;
   struct ll_node *current = head;
   while (current != NULL){
    size++;
    current = current->next;
   }

   int *arr = malloc(size * sizeof(int));
   if (((arr ==NULL))){
    return NULL;
   }
   current = head; 
   for (int i =0; i < size; i++){
    arr[i] = current -> data;
    current = current ->next;
   }
   return arr;

}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_create(int data) {
   struct ll_node *node = malloc(sizeof(struct ll_node));
   if (node == NULL){
    return NULL;
   }
   node-> data=data;
   node->next = NULL;

   return node;
}

/**
 * TODO: Describe what the function does
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *current = head;
    struct ll_node *next_node;

    while (current != NULL){
        next_node = current->next;
        free(current);
        current=next_node;
    }
}

/**
 * TODO: Describe what the function does
 */
void ll_append(struct ll_node *head, int data) {
    if (head == NULL){
        return;
    }
    struct ll_node *new_node = ll_create(data);
    if (new_node == NULL){
        return;
    }
    struct ll_node *current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (data == NULL || len <= 0){
        return NULL;
    }
    struct ll_node *head = ll_create(data[0]);
    if (head == NULL){
        return NULL;
    }

    struct ll_node *tail = head;
    for (int i =1; i< len; i++){
        struct ll_node *new_node = ll_create(data[i]);
        if (new_node == NULL){
            ll_destroy(head);
            return NULL;
        }
        tail->next=new_node;
        tail = new_node;
    }
    return head;

}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if(head == NULL){
        return NULL;
    }
    if (head->data == value){
        struct ll_node *new_head = head->next;
        free(head);
        return new_head;
    }
    struct ll_node *current = head;
    struct ll_node *prev = NULL;

    while (current != NULL && current ->data != value){
        prev = current;
        current = current ->next;
    }

    if (current ==NULL){
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

