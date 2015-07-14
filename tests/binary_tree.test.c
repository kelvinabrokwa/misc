#include "../binary_tree.c"

int main() {
  node* tree = new_tree();
  tree = add_root(tree, 5);
  insert_node(tree, 6);
  insert_node(tree, 6);
  insert_node(tree, 4);
  insert_node(tree, 2);
  insert_node(tree, 8);
}
