#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

node* new_tree()
{
    return 0;
}

void insert(node** tree, int data)
{
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

node* find_right_min(node* root)
{
    node* curr = root->right;
    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}

node** deleteFrom(node** root, int data)
{
    if ((*root)->data == data)
    {
        if (!(*root)->left && !(*root)->right)
        {
            free(*root);
            return 0;
        }
        else if ((*root)->left && (*root)->right)
        {
            node* replacement = find_right_min(*root);
            replacement->left = (*root)->left;
            replacement->right = (*root)->right;
            free(*root);
            *root = replacement;
            return root;
        }
        else if ((*root)->left)
        {
            free(*root);
            *root = (*root)->left;
            return root;
        }
        else
        {
            free(*root);
            *root = (*root)->right;
            return root;
        }
    }
    else if ((*root)->data > data)
    {
        return deleteFrom(&((*root)->left), data);
    }
    else if ((*root)->data < data)
    {
        return deleteFrom(&((*root)->right), data);
    }
    return root;
}



void delete(node** tree, int data)
{
    *tree = *deleteFrom(tree, data);
}
