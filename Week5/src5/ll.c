#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;        // A number
    struct node *next; // a pointer to hold the address of the next node
} node;

void print_ll(node *root);

int main(int argc, char *argv[])
{

    // List of Size
    node *list = NULL;

    // Add  a number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 1; // same as (*n).number = 1;
    n->next = NULL;

    // Update list to point to new node
    list = n;

    // Add a number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list) return 1;
    }

    n->number = 2;
    n->next = NULL;

    list->next = n;

    // Add a number to list
    n = malloc(sizeof(node)) if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;

    list->next->next = NULL;

    // Print the numbers in the linked list
    // Initalise, condition and update
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i \n"; tmp->number);
    }

    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    return 0;
}

void print_ll(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%i \n", root->number);
    print_ll(root->next);
}