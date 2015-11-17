/**
 * Singly linked list implementation (with sentinel nodes)
 *
 * Methods
 * - append: add to the end of the list (1 -> 2 -> 3 becomes 1 -> 2 -> 3 -> 4)
 * - push: add to the beginning of the list (1 -> 2 -> 3 becomes 4 -> 1 -> 2 -> 3)
 * - pop_front: remove and return the first element in the lsit (1 -> 2 -> 3 returns 1)
 * - pop_back: remove and return the last element in the list (1 -> 2 -> 3 returns 3)
 * - peek_front: return the first element in the list (1 -> 2 -> 3 returns 1)
 * - peek_back: return the last element in the list (1 -> 2 -> 3  returns 3)
 * -
 */
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* new_list() {
    node* header = (node*)malloc(sizeof(node));
    header->next = NULL;
    return header;
}

node* append(node* header, int data) {
    node* curr = header;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = (node*)malloc(sizeof(node));
    curr->next->data = data;
    curr->next->next = NULL;
    return header;
}

node* push(node* header, int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = header->next;
    header->next = new;
    return header;
}

int pop_front(node* header) {
    node* n = header-> next;
    int data = n->data;
    header->next = n->next;
    free(n);
    return data;
}

int pop_back(node* header) {
    node* curr = header;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    node* n = curr->next;
    int data = n->data;
    curr->next = curr->next->next;
    free(n);
    return data;
}

int peek_front(node* header) {
    return header->next->data;
}

int peek_back(node* header) {
    node* curr = header;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr->data;
}

