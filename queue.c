#include "linked_list.c"

struct node* new_queue() {
  return new_list();
}

struct node* enqueue(struct node* head, int i) {
  return append(head, i);
}

// dequeue an item and return it
struct node dequeue(struct node* head) {
  return remove_first(head);
}

// test
int main() {
  struct node* queue = new_queue();
  queue = enqueue(queue, 1);
  queue = enqueue(queue, 2);
  print_list(queue);
}
