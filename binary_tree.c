#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} node;

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

