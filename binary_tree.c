#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} node;

#include "utils/print_tree.h" // fix this

node* new_tree() {
  node* root_ptr = NULL;
  return root_ptr;
}

node* add_root(node* root_ptr, int data) {
  node* root = (node*)malloc(sizeof(node));
  root->data = data;
  root->left = root->right = NULL;
  return root;
}

void insert_node(node* root_ptr, int data) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = new_node->right = NULL;

  node* ptr = root_ptr;

  while (ptr->left && ptr->right) { // find the parent
    if (data < ptr->data) {
      ptr = ptr->left;
    } else if (data > ptr->data) {
      ptr = ptr->right;
    } else {
      return;
    }
  }

  if (data < ptr->data) {
    ptr->left = new_node;
  } else {
    ptr->right = new_node;
  }
}


// test
int main() {
  node* tree = new_tree();
  tree = add_root(tree, 5);
  insert_node(tree, 6);
  insert_node(tree, 6);
  insert_node(tree, 4);
  insert_node(tree, 2);
  insert_node(tree, 8);
  print_tree(tree);
}
