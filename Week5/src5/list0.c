// Implements a list of numbers with an array of fixed size

#include <stdio.h>

int main(void)
{
    // List of size 3
    int list[3];

    // Initialize list with numbers
    *list = 1;       // list[0] = 1;
    *(list + 1) = 2; // list[1] = 2;
    *(list + 2) = 3; // list[2] = 3;

    // Print list
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    // typedef struct node
    // {
    //     int number;
    //     struct node *next;
    // } node;

    // node *n = malloc(sizeof(node));
}
