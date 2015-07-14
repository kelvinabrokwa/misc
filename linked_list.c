#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node* next;
};

struct node* new_list() {
  struct node* head = NULL;
  return head;
}

// add data to the end
struct node* append(struct node* head, int data) {
  if (!head) {
    head = (struct node*)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
  } else {
    struct node* curr = head;
    while (curr) {
      if (curr->next) {
        curr = curr->next;
      } else {
        struct node* new = (struct node*)malloc(sizeof(struct node));
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
struct node* push(struct node* head, int data) {
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = head;
  head = new;
  return head;
}

// remove data from the end and return it
int remove_last(struct node* head) {
  struct node* curr = head;
  while ((curr->next)->next) { // find the second to last node
    curr = curr->next;
  }
  struct node* last = curr->next;
  curr->next = NULL;
  int data = last->data;
  free(last);
  return data;
}


// remove data from the beginning and return the new head and the data
// this is wonky, I'm abusing the node struct but YOLO right?
struct node remove_first(struct node* head) {
  struct node values = { head->data, head->next };
  free(head);
  return values;
}
