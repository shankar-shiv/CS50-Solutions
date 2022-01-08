// Implements a list of numbers as a binary search tree

#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

// 2 prototypes
void free_tree(node *root);
void print_tree(node *root); // print the tree in order

int main(void)
{
    // Tree of size 0
    node *tree = NULL; // just a NULL pointer

    // Add number to list
    node *n = malloc(sizeof(node));

    if (n == NULL) // Safety check
    {
        return 1;
    }

    n->number = 2; // Initialising the node
    n->left = NULL;
    n->right = NULL;
    tree = n; // Intitalising the tree itself

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }

    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n; // Initalise the tree left child to n

    // Add number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n; // Updating the tree right child

    // Print tree
    print_tree(tree);

    // Free tree
    free_tree(tree);
    return 0;
}

void free_tree(node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print_tree()
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}
