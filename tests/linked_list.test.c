#include "../linked_list.c"

int print_length(struct node* head) {
  struct node* curr = head;
  int count = 0;
  while (curr) {
    curr = curr->next;
    count++;
  }
  return count;
}

void print_list(struct node* head) {
  struct node* curr = head;
  while (curr) {
    printf("%d - ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  struct node* head = new_list();
  int i;
  for (i=0; i<10; i++) {
    head = push(head, i);
    head = append(head, i + 10);
  }
  print_list(head);
  printf("length: %d\n", print_length(head));
  printf("last: %d\n", remove_last(head));
  print_list(head);
  struct node pop_results = remove_first(head);
  head = pop_results.next;
  int first = pop_results.data;
  printf("first: %d\n", first);
  print_list(head);
}
