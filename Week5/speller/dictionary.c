// Implements a dictionary's functionality
// Incidentally, to be clear, by “misspelled” we simply mean that some word is not in the dictionary provided.

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1]; // + 1 includes the NULL character '\0' too
    struct node *next;
} node;

void free_ll(node *root);

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

unsigned int hash_number = 0;
// Size of the dictionary
unsigned int word_count = 0;

// Hash table
// An array where every element is a pointer to a node
node *table[N]; // Array of node pointers

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO : Check function should be case-insensitive
    // Hash word to obtain a hash value
    // Access linked list at that index in the hash table
    // Traverse linked list, looking for the word (strcasecmp)

    hash_number = hash(word);
    node *cursor = table[hash_number];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // Move cursor to next node
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
// Function takes a string and returns an index
// Hashes word to a number
// Adapted from : http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    unsigned long hash_result = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash_result = ((hash_result << 5) + hash_result) + c; /* hash * 33 + c */
    }
    return hash_result % N;
}

// Loads dictionary into memory, returning true if successful, else false
// Load into hash table
bool load(const char *dictionary)
{
    char word[LENGTH + 1];

    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }

    // Read strings from file one at at time
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        // fscanf will return EOF once it reaches end of file
        node *n = malloc(sizeof(node));

        // If malloc returns doesn't return a valid pointer, return false
        if (n == NULL)
        {
            return false;
        }
        // string copy
        strcpy(n->word, word);
        n->next = NULL;

        // Hash word to obtain a hash value
        hash_number = hash(word);

        // Insert node into hash table at that location
        n->next = table[hash_number];
        // Set head to new pointer
        table[hash_number] = n;
        // Increment word count
        word_count += 1;
    }

    // Remember to close file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through buckets
    for (int i = 0; i < N; i++)
    {
        // Set cursor to this each bucket location
        node *cursor = table[i];
        // If cursor is not NULL, free
        while (cursor)
        {
            // Create temp
            node *tmp = cursor;
            // Move cursor to next node
            cursor = cursor->next;
            // Free up temp
            free(tmp);
        }
        // If cursor is NULL
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}

void free_ll(node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }
    free_ll(root->next);
    free(root);
}