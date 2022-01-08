// Compares two integers

#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    typedef struct
    {
        int row;
        int column;
    } tuple;

    tuple T[9];

    T[0].row = 1;
    T[0].column = 1;

    printf("%i, %i \n", T[0].row, T[0].column);
}
