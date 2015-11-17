#include <assert.h>
#include "../stack.c"

int main() {
    node* stack = new_stack();
    int i;
    for (i=0; i<10; i++) {
       stack_push(stack, i);
    }
    assert(stack_peek(stack) == 9);
    assert(stack_pop(stack) == 9);
    assert(stack_peek(stack) == 8);
}
