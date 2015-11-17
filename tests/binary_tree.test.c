#include <assert.h>
#include "../binary_tree.c"

int main() {
  node* tree = new_tree();
  insert(&tree, 5);
  insert(&tree, 4);
  insert(&tree, 6);
  insert(&tree, 3);

  assert(tree->data == 5);
  assert(tree->left->data == 4);
  assert(tree->right->data == 6);
  assert(tree->left->left->data == 3);
}
