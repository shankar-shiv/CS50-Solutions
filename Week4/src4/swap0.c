// Fails to swap two integers

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{

    int tmp = *a; // dereferencing the values at the pointers
    *a = *b;      // pass the value at location b and store it in a
    *b = tmp;     // pass the value of tmp and store it in location b
}
