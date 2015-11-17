#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

node* new_tree() {
    return 0;
}

void insert(node** tree, int data) {
    if (*tree == 0)
    {
        *tree = (node*)malloc(sizeof(node));
        (*tree)->data = data;
        (*tree)->left = 0;
        (*tree)->right = 0;
    }
    else if ((*tree)->data > data)
    {
        insert(&(*tree)->left, data);
    }
    else if ((*tree)->data < data)
    {
        insert(&(*tree)->right, data);
    }
}

