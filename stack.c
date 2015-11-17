#include "linked_list.c"

node* new_stack() {
    return new_list();
}

node* stack_push(node* list, int data) {
    return push(list, data);
}

int stack_pop(node* list) {
    return pop_front(list);
}

int stack_peek(node* list) {
    return peek_front(list);
}
