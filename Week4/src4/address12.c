// Prints an array using pointer arithmetic

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

int main(void)
{
    // An array of numbers also in java
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    *(numbers + 1) = 100;
    // Print numbers
    printf("%p\n", numbers);
    printf("%i\n", *numbers);
    printf("%i\n", *(numbers + 1));
    printf("%i\n", *(numbers + 2));
    printf("%i\n", *(numbers + 3));
    printf("%i\n", *(numbers + 4));
    printf("%i\n", *(numbers + 5));
    printf("%i\n", *(numbers + 6));
    printf("%i\n", *(numbers + 7));

    const char *word = "zz";
    int result[2];
    int index = 0;
    // TODO: Improve this hash function
    *result = toupper(word[0]) - 'A';
    printf("memory address at result[0] = %d \n", *result);
    *(result + 1) = toupper(word[1]) - 'A';
    printf("memory address at result[1] = %d \n", *result + 1);
    index = *result + *(result + 1);
    // index = result[0] + result[1];
    printf("index = %i \n", index);
}
