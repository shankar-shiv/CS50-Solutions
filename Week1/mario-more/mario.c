#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

void space(int n);
void hash(int n);

int main(void)
{
    int user_input = 0;
    int indent = 0;
    int empty_space = 2;

    do
    {
        user_input = get_int("input a positive integer between 1 and 8, inclusive \n");
        // printf("Height : %i \n", user_input);
    } while (user_input <= 0 || user_input >= 9);

    for (int counter = 1; counter <= user_input; counter += 1)
    {
        indent = user_input - counter;
        space(indent);
        hash(counter);
        space(2);
        hash(counter);
        printf("\n");
    }

    return 0;
}

void space(int n)
{
    for (int j = 0; j < n; j++)
    {
        printf(" ");
    }
}

void hash(int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }
}
