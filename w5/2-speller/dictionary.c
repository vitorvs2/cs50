// Implements a dictionary's functionality

// Include for string comparison
#include <cs50.h>
#include <strings.h>

// temp include for intelisense
#include <stdio.h>

// custom include
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// custom function to recursively free nodes
void freenode(node *node);

// custom function to recursively search the word inside nodes
bool checknode(node *node, const char *word);

// TODO: Choose number of buckets in hash table
// const unsigned int N = 26;
const unsigned int N = LENGTH * 122;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if (table[hash(word)] != NULL)
    {
        return checknode(table[hash(word)], word);
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int i = 0, hash = 0;
    int len = strlen(word);
    while (word[i])
    {
        if (word[i] != 96)
        {
            hash = hash + toupper(word[i]);
        }
        i++;
    }

    // int len = strlen(word);
    // // TODO: Improve this hash function
    // for (int i = 0; i < len; i++)
    // {
    //     if (word[i] != 96)

    // }
    // return toupper(word[0]) - 'A';
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (!source)
    {
        return false;
    }

    char *buffer = malloc(LENGTH + 1);
    if (!buffer)
    {
        return false;
    }

    // Read each word in the file
    while (fscanf(source, "%s", buffer) != EOF)
    {
        // Add each word to the hash table
        int index = hash(buffer);

        if (table[index] == NULL)
        {
            node *newnode = malloc(sizeof(node));
            if (!newnode)
            {
                return false;
            }
            strcpy(newnode->word, buffer);
            table[index] = newnode;
            newnode->next = NULL;
        }
        else
        {
            node *newnode = malloc(sizeof(node));
            if (!newnode)
            {
                return false;
            }
            strcpy(newnode->word, buffer);
            newnode->next = table[index];
            table[index] = newnode;
        }
    }

    // Close the dictionary file
    free(buffer);
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // counter to sum the loaded words
    unsigned int counter = 0;

    // scanning the hashtable for the words
    for (int i = 0; i < N; i++)
    {
        // if hashtable has node, start counting
        if (table[i] != NULL)
        {
            counter++;
            node *node = table[i];
            while (node->next != NULL)
            {
                node = node->next;
                counter++;
            }
        }
    }
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Scanning the hashtable for nodes to free
    for (int i = 0; i < N; i++)
    {
        // If the table index has a node, execute the freenode function
        if (table[i] != NULL)
        {
            freenode(table[i]);
        }

        // Set the hashtable's node to null after freeing up all nodes
        table[i] = NULL;
    }
    return true;
}

// Recursively free the hash table's node
void freenode(node *node)
{
    if (node->next != NULL)
    {
        freenode(node->next);
    }
    free(node);
}

// Recursively search the word in the hashtable's nodes
bool checknode(node *node, const char *word)
{
    if (strcasecmp(node->word, word) == 0)
    {
        return true;
    }

    if (node->next != NULL)
    {
        return checknode(node->next, word);
    }

    return false;
}
