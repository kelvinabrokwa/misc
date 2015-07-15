#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data;
  struct Node* next;
} node;

node* new_list() {
  node* head = NULL;
  return head;
}

// add data to the end
node* append(node* head, int data) {
  if (!head) {
    head = (node*)malloc(sizeof(node));
    head->data = data;
    head->next = NULL;
  } else {
    node* curr = head;
    while (curr) {
      if (curr->next) {
        curr = curr->next;
      } else {
        node* new = (node*)malloc(sizeof(node));
        new->data = data;
        new->next = NULL;
        curr->next = new;
        curr = NULL;
      }
    }
  }
  return head;
}

// add data to the beginning
node* push(node* head, int data) {
  node *new = (node*)malloc(sizeof(node));
  new->data = data;
  new->next = head;
  head = new;
  return head;
}

// remove data from the end and return it
int remove_last(node* head) {
  node* curr = head;
  while ((curr->next)->next) { // find the second to last node
    curr = curr->next;
  }
  node* last = curr->next;
  curr->next = NULL;
  int data = last->data;
  free(last);
  return data;
}


// remove data from the beginning and return the new head and the data
// this is wonky, I'm abusing the Node struct but YOLO right?
node remove_first(node* head) {
  node values = { head->data, head->next };
  free(head);
  return values;
}
