#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[])
{

    float letters = 0;
    float words = 1;
    float sentences = 0;

    float L = 0;
    float S = 0;

    // Get string from user.
    string s = get_string("Text: ");

    // Ensure string was read
    if (s == NULL)
    {
        return 1;
    }

    // Parse the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            letters += 1;
        }
        if (isspace(s[i]))
        {
            words += 1;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences += 1;
        }
    }

    // Display the results
    // printf("%f letter(s)\n", letters);
    // printf("%f word(s)\n", words);
    // printf("%f sentence(s)\n", sentences);

    L = (100 / words) * letters;
    // printf("L is %f\n", round(L));

    S = (100 / words) * sentences;
    // printf("S is %f\n", round(S));

    float index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("index is %d\n", index);

    int indexi = round(index);

    if (indexi >= 1 && indexi <= 16)
    {
        printf("Grade %i\n", indexi);
    }
    else
    {
        if (indexi < 1)
        {
            printf("Before Grade 1\n");
        }
        if (indexi > 16)
        {
            printf("Grade 16+\n");
        }
    }

    return 0;
}
