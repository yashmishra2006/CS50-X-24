// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

unsigned int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashint = hash(word);
    node *cursor = table[hashint];
    while(cursor!=NULL)
    {
        if(strcmp(cursor->word, word)==0)
        {
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
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if(source==NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while(fscanf(source, "%s", word) != EOF)

    {
        node *new_node  = malloc(sizeof(node));
        if(new_node == NULL)
        {
            return false;
        }
        //call the hash function
        int unsigned hashint = hash(word);
        strcpy(new_node->word, word);
        if(table[hashint] == NULL)
        {
            new_node->next = NULL;
        }
        else
        {
            new_node->next = table[hashint];
        }
        table[hashint] = new_node;
        count += 1;
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

void freememory(node *n)
{
    if(n!=NULL)
    {
        freememory(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i=0; i<N; i++)
    {
      if(table[i]!=NULL)
      {
        freememory(table[i]);
      }
    }
    return true;
}
