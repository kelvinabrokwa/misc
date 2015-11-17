#include "linked_list.c"

node* new_queue() {
  return new_list();
}

node* enqueue(node* list, int i) {
  return append(list, i);
}

int dequeue(node* list) {
  return pop_front(list);
}

int queue_peek(node* list) {
    return peek_front(list);
}
