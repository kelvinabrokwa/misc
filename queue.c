#include "linked_list.c"

node* new_queue() {
  return new_list();
}

node* enqueue(node* head, int i) {
  return append(head, i);
}

node dequeue(node* head) {
  return remove_first(head);
}
