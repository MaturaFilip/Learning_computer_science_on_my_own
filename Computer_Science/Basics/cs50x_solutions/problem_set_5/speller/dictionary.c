// Implements a dictionary's functionality

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

// TODO: Choose number of buckets in hash table
const unsigned long N = 26 * 100;

// number of words in dictionary
unsigned int words_in_dict = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int get_hash = hash(word);

    // access linked list
    node *cursor = table[get_hash];

    while (cursor != NULL) {
        if (strcasecmp(cursor->word, word) == 0) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int ch = toupper(word[0]) - 'A';
    unsigned int l = strlen(word);
    return ch + l;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    unsigned int hashed_num;
    // TODO
    // open up dictionary file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    // read strings from file one at a time
    // return EOF once it reached end of file
    char word[100];
    while (fscanf(input, "%s", word) == 1) {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            printf("Could not allocated memory for node\n");
            return false;
        }
        // Insert node into hash table at that location
        strcpy(n->word, word);

        // hash word to optain a hash value
        hashed_num = hash(n->word);

        // hashed array
        n->next = table[hashed_num];
        table[hashed_num] = n;

        // keep track of words_in_dict during loading dictionary
        words_in_dict++;
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words_in_dict;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++) {
        node *cursor = table[i];

        while (cursor != NULL) {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}

