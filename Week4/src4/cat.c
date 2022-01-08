#include <stdio.h>
#include <stdlib.h>

/*
 * Cat function
 */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./cat <filename>");
        return 1;
    }

    FILE *ptr = fopen(argv[1], "r");

    // Check for null pointer
    if (!ptr)
    {
        return 1;
    }

    char ch;
    while ((ch = fgetc(ptr)) != EOF)
    {
        printf("%c", ch);
    }
}