#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int m;
    int *a;
    int *b = malloc(sizeof(int));
    a = &m;
    a = b; // a and b are going to pint to the same location
    m = 10;
    *b = m + 2; // dereferencing b = 12

    printf("%i \n", *b);

    free(b); // we no longer working this , the system can take back this memory
}