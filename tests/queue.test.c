#include <assert.h>
#include "../queue.c"

int main() {
  node* queue = new_queue();

  int i;
  for (i=0; i<10; i++) {
    enqueue(queue, i);
  }

  assert(queue_peek(queue) == 0);
  assert(dequeue(queue) == 0);
  assert(queue_peek(queue) == 1);
}
