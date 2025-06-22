#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Define number of buckets in hash table
const unsigned int N = 20007;  // A larger number of buckets to reduce collisions maybe?

// Hash table
node *table[N];


unsigned int dsize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get the hash value for the word
    unsigned int ind = hash(word);
    node *ptr = table[ind];

    // Traverse the linked list at the hash table ind
    while (ptr != NULL)
    {
        // Compare word case-insensitively
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // A better hash function based on the djb2 algorithm
    unsigned long hashfunc = 5381;
    int charac;

    while ((charac = *word++))
    {
        hashfunc = ((hashfunc << 5) + hashfunc) + tolower(charac);  // hash * 33 + c
    }

    return hashfunc % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer to hold each word
    char word[LENGTH + 1];

    // Read each word from the dictionary
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *nn = malloc(sizeof(node));
        if (nn == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy the word into the new node
        strcpy(nn->word, word);

        // Get the hash value for the word
        unsigned int ind = hash(word);

        // Insert the node into the hash table at that ind
        nn->next = table[ind];
        table[ind] = nn;

        // Increment the word count
        dsize++;
    }

    // Close the dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dsize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over each bucket in the hash table
    for (unsigned int i = 0; i < N; i++)
    {
        node *ptr = table[i];

        // Traverse and free the linked list
        while (ptr != NULL)
        {
            node *now = ptr;
            ptr = ptr->next;
            free(now);
        }
    }

    return true;
}
