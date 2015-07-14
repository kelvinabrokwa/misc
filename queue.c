#include "linked_list.c"

struct node* new_queue() {
  return new_list();
}

struct node* enqueue(struct node* head, int i) {
  return append(head, i);
}

struct node dequeue(struct node* head) {
  return remove_first(head);
}
