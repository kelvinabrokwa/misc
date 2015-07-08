#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node* next;
};

void print_list(struct node* head) {
  struct node* curr = head;
  while (curr) {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
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
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = data;
        curr->next = NULL;
        curr = curr->next;
      }
    }
  }
  return head;
}

struct node* push(struct node* head, int data) {
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = head;
  head = new;
  return head;
}

int main() {
  struct node *head, *curr;
  head = NULL;
  int i;
  for (i=0; i<10; i++) {
    curr = (struct node*)malloc(sizeof(struct node));
    curr->data = i;
    curr->next = head;
    head = curr;
  }
  printf("%d\n", print_length(head));
}
