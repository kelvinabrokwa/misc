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

void print_list(struct node* head) {
  struct node* curr = head;
  while (curr) {
    printf("%d - ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int print_length(struct node* head) {
  struct node* curr = head;
  int count = 0;
  while (curr) {
    curr = curr->next;
    count++;
  }
  return count;
}

// add data to the end
struct node* append(struct node* head, int data) {
  if (!head) {
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

// remove data from the end
struct node* remove_last(struct node* head) {
  struct node* curr = head;
  while ((curr->next)->next) { // find the second to last node
    curr = curr->next;
  }
  struct node* last = curr->next;
  curr->next = NULL;
  free(last);
  return head;
}

struct node* remove_first(struct node* head) {
  struct node* first = head;
  head = first->next;
  free(first);
  return head;
}

// test
int main() {
  struct node* head = new_list();
  int i;
  for (i=0; i<10; i++) {
    head = push(head, i);
  }
  for (i=10; i<20; i++) {
    head = append(head, i);
  }
  printf("length: %d\n", print_length(head));
  print_list(head);
  head = remove_last(head);
  print_list(head);
  head = remove_first(head);
  print_list(head);
}
