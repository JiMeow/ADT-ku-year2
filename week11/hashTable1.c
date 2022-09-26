#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item
{
    char *text;
    struct item *next;
} item_t;

typedef struct hash
{
    item_t **table;
    int size;
    int hash_key;
} hash_t;

hash_t *init_hashtable(int m, int hashkey)
{
    hash_t *hashtable = (hash_t *)malloc(sizeof(hash_t));
    hashtable->size = m;
    hashtable->hash_key = hashkey;
    hashtable->table = (item_t **)malloc(sizeof(item_t *) * (m + 2));
    for (int i = 0; i < m; i++)
    {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

unsigned hash(hash_t *hashtable, char *text)
{
    unsigned i, sum = 0;
    for (i = 0; i < strlen(text); i++)
    {
        sum = sum * hashtable->hash_key + text[i];
    }
    return sum % hashtable->size;
}

void insert(hash_t *hashtable, char *text)
{
    unsigned hash_value = hash(hashtable, text);
    item_t *new_item = (item_t *)malloc(sizeof(item_t));
    new_item->text = (char *)malloc(sizeof(char) * TEXTSIZE);
    strcpy(new_item->text, text);
    new_item->next = hashtable->table[hash_value];
    hashtable->table[hash_value] = new_item;
}

int search(hash_t *hashtable, char *text)
{
    unsigned hash_value = hash(hashtable, text);
    item_t *item = hashtable->table[hash_value];
    while (item != NULL)
    {
        if (strcmp(item->text, text) == 0)
        {
            return hash_value;
        }
        item = item->next;
    }
    return -1;
}

int main(void)
{
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;

    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char) * TEXTSIZE);

    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &command, text);
        switch (command)
        {
        case 1:
            insert(hashtable, text);
            break;
        case 2:
            printf("%d\n", search(hashtable, text));
            break;
        }
    }
    return 0;
}