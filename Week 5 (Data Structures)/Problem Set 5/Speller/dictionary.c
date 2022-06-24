// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node* table[N];

// Counter for total words in dictionary
int wordCount = 0;

// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    // Obtain the hash value of the word
    int hashValue = hash(word);

    // Search the hash table for the word
    node* cursor = table[hashValue];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char* word)
{
    int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ tolower(word[i]);
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // Initialize a buffer to store words
    char buffer[LENGTH];

    // While there are still words in the dictionary file...
    while (fscanf(dict, "%s", buffer) != EOF)
    {
        // Create a new 'node' for the word
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        n->next = NULL;

        // Copy contents of buffer into new node->word
        strcpy(n->word, buffer);

        // Obtain the hash value of the word
        int hashValue = hash(n->word);

        // Insert new node into hash table
        if (table[hashValue] == NULL)
        {
            table[hashValue] = n;
        }
        else
        {
            n->next = table[hashValue];
            table[hashValue] = n;
        }

        // Increment the dictionary word counter
        wordCount++;
    }

    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    while (table[i] != NULL)
    {
        node *temp = table[i]->next;
        free(table[i]);
        table[i] = temp;
    }

    return true;
}
