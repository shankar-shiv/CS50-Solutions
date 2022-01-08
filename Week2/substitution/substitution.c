#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ciphertext -> plaintext and plaintext -> ciphertext

bool validate(string key);

int main(int argc, string argv[])
{

    // Check if the program must accept a single command-line argument, the key to use for the substitution.
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    // Check if the key has 26 characters and check if all characters in the key are alphabetic characters
    // Start--
    if (strlen(argv[1]) == 26)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]))
            {
                // check if all characters in the key are alphabetic characters
            }
            else
            {
                printf("All charcters must be an alphabetic character \n");
                return 1;
            }
        }
    }
    else
    {
        printf("The key should contain 26 letters \n");
        return 1;
    }
    // End--

    if (validate(argv[1]))
    {
        string plaintext = get_string("plaintext: ");
        int charcount = strlen(plaintext);
        char ciphertext[charcount];
        string abc = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < charcount; i++)
        {
            if (isupper(plaintext[i]) != 0)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (abc[j] == tolower(plaintext[i]))
                    {
                        ciphertext[i] = toupper(argv[1][j]);
                        break;
                    }
                }
            }
            else if (islower(plaintext[i]) != 0)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (abc[j] == plaintext[i])
                    {
                        ciphertext[i] = tolower(argv[1][j]);
                        break;
                    }
                }
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        ciphertext[charcount] = '\0';
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        printf("Please make sure your key is a permutation of all 26 characters - not more, not less.\n");
        return 1;
    }
    return 0;
}

// Validate key
bool validate(string key)
{
    int matches = 0;

    // Check if all characters are alphabetic
    for (int i = 0; i < 26; i += 1)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    // Check if the characters in the key are exactly once
    if (strlen(key) == 26)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == c)
                {
                    matches++;
                    break;
                }
            }
        }

        // Check if each letter is exactly once
        if (matches == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}