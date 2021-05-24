#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 100

typedef struct Node
{
    char *key;
    char *value;
    struct Node *next;
} Node;
typedef struct Hash
{
    Node *list[HASH_SIZE];
} Hash;

unsigned int hashCode(char *key)
{
    unsigned long hash = 5381;
    unsigned int c;

    while (c = *key++)
    {
        hash = (hash << 5) + hash + c;
    }

    return hash % HASH_SIZE;
}

Node *createNode(char *key, char *value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    return node;
}

void insertNode(Hash *hash, char *key, char *value)
{
    unsigned int index = hashCode(key);
    Node *node = hash->list[index];

    if (node == NULL)
    {
        hash->list[index] = createNode(key, value);
        return;
    }

    while (true)
    {
        if (!strcmp(node->key, key))
        {
            node->value = value;
            return;
        }

        if (node->next == NULL)
        {
            break;
        }

        node = node->next;
    }

    node->next = createNode(key, value);
}

char *search(Hash *hash, char *key)
{
    unsigned int index = hashCode(key);
    Node *node = hash->list[index];

    while (node)
    {
        if (!strcmp(node->key, key))
        {
            return node->value;
        }
    }

    return "";
}

int main()
{
    Hash *hash = (Hash *)malloc(sizeof(Hash));

    insertNode(hash, "hello", "world");
    insertNode(hash, "Kaio", "Viycius");
    insertNode(hash, "bob", "marley");

    printf("%s\n", search(hash, "hello"));
    printf("%s\n", search(hash, "Kaio"));
    printf("%s\n", search(hash, "bob"));
    printf("%s\n", search(hash, "marley"));
    printf("%s\n", search(hash, "bob"));

    insertNode(hash, "bob", "dylan");
    printf("%s\n", search(hash, "bob"));
    printf("%s\n", search(hash, "bob"));
    insertNode(hash, "bob", "sponge");
    printf("%s\n", search(hash, "bob"));

    return 0;
}