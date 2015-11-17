#include <assert.h>
#include "../linked_list.c"

int get_length(node* header) {
  node* curr = header;
  int count = 0;
  while (curr->next != NULL) {
    curr = curr->next;
    count++;
  }
  return count;
}

void print_list(node* list) {
    node* curr = list;
    while (curr->next != NULL) {
        curr = curr->next;
        printf("%d -> ", curr->data);
    }
    printf("\n");
}

int main() {
    node* list = new_list();

    int i;
    for (i=0; i<10; i++) {
        append(list, i);
    }
    for (i=0; i<10; i++) {
        push(list, i*10);
    }

    assert(get_length(list) == 20);

    assert(peek_front(list) == 90);
    assert(pop_front(list) == 90);
    assert(peek_front(list) == 80);

    assert(peek_back(list) == 9);
    assert(pop_back(list) == 9);
    assert(peek_back(list) == 8);
}
