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
    print_list(list);
    for (i=0; i<10; i++) {
        push(list, i*10);
    }
    print_list(list);
    assert(get_length(list) == 20);
}
