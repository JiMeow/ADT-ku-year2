#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char *item_t;

typedef struct hash
{
    item_t *table;
    int size;
    int hash_key;
} hash_t;

hash_t *init_hashtable(int m, int hashkey)
{
    hash_t *hashtable = (hash_t *)malloc(sizeof(hash_t));
    hashtable->size = m;
    hashtable->hash_key = hashkey;
    hashtable->table = (item_t *)malloc(sizeof(item_t) * (m + 2));
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

unsigned quadratic_probing(hash_t *hashtable, char *text, int i)
{
    unsigned hash_value = hash(hashtable, text);
    return (hash_value + (i * i + i) / 2) % hashtable->size;
}

void insert(hash_t *hashtable, char *text)
{
    int i = 0;
    unsigned hash_value = quadratic_probing(hashtable, text, 0);
    while (hashtable->table[hash_value] != NULL)
    {
        i++;
        hash_value = quadratic_probing(hashtable, text, i);
    }
    hashtable->table[hash_value] = (char *)malloc(sizeof(char) * TEXTSIZE);
    strcpy(hashtable->table[hash_value], text);
}

int search(hash_t *hashtable, char *text)
{
    unsigned hash_value = quadratic_probing(hashtable, text, 0);
    int i = 0;
    if (hashtable->table[hash_value] == NULL)
    {
        return -1;
    }
    while (hashtable->table[hash_value] != NULL)
    {
        if (strcmp(text, hashtable->table[hash_value]) == 0)
        {
            return hash_value;
        }
        i++;
        hash_value = quadratic_probing(hashtable, text, i);
        if (i > hashtable->size)
            break;
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