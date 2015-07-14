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

  printf("queue 1...\n");
  queue = enqueue(queue, 1);
  print_list(queue);

  printf("queue 2...\n");
  queue = enqueue(queue, 2);
  print_list(queue);

  printf("queue 3...\n");
  queue = enqueue(queue, 3);
  print_list(queue);

  printf("dequeue...\n");
  struct node dq_data = dequeue(queue);
  queue = dq_data.next;
  int i = dq_data.data;
  printf("%d\n", i);

  print_list(queue);
}
