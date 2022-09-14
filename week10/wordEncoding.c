#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
this huffman use max heap so in priority queue value of priority is always be negative
cause for change max heap to min heap just change the sign of priority
*/

/// @brief node
typedef struct node
{
    int priority;
    char *str;
    struct node *leftnode;
    struct node *rightnode;
} node_t;
node_t *newNode()
{
    node_t *t = malloc(sizeof(node_t));
    t->priority = 0;
    t->str = malloc(20 * sizeof(char));
    strcpy(t->str, "");
    t->leftnode = NULL;
    t->rightnode = NULL;
    return t;
}

/// @brief heap
typedef struct heap
{
    node_t **data;
    int last_index;
} heap_t;
void swap(heap_t *, int, int);
void upperBalance(heap_t *, int);
void lowerBalance(heap_t *, int);
heap_t *init_heap(int);
void insert(heap_t *, node_t *);
void delete_max(heap_t *);
node_t *find_max(heap_t *);
void bfs(heap_t *);
void dfs(node_t *, char *);

/*
9
a 1
e 2
g 1
h 2
i 3
m 1
s 5
t 1
_ 3
*/

int main()
{
    int n;
    scanf("%d", &n);
    heap_t *h = init_heap(n + 10);
    for (int i = 0; i < n; i++)
    {
        char c[20];
        int f;
        scanf("%s %d", &c, &f);
        node_t *t = newNode();
        strcpy(t->str, c);
        // priority was minus because huffman use min heap but i use max heap so i change to from plus to minus
        t->priority = -f;
        insert(h, t);
    }

    // huffman algorithm
    while (h->last_index > 1)
    {
        node_t *left = find_max(h);
        delete_max(h);
        node_t *right = find_max(h);
        delete_max(h);
        node_t *new = newNode();
        new->priority = left->priority + right->priority;
        new->leftnode = left;
        new->rightnode = right;
        insert(h, new);
    }

    char seq[100010];
    strcpy(seq, "");
    dfs(h->data[1], seq);
}

/// @brief swap two nodes in heap by given index
/// @param t address of heap
/// @param a index of node a
/// @param b index of node b
void swap(heap_t *t, int a, int b)
{
    node_t **temp = t->data;
    node_t *temp2 = temp[a];
    temp[a] = temp[b];
    temp[b] = temp2;
}

/// @brief balance the heap by given index from now index to root
/// @param t address of heap
/// @param index index of node
void upperBalance(heap_t *t, int index)
{
    node_t **temp = t->data;
    while (index > 1)
    {
        if (temp[index]->priority > temp[index / 2]->priority)
        {
            swap(t, index, index / 2);
            index /= 2;
        }
        else
            break;
    }
}

/// @brief balance the heap by given index from now index to leaf
/// @param t address of heap
/// @param index index of node
void lowerBalance(heap_t *t, int index)
{
    node_t **temp = t->data;
    while (index <= t->last_index)
    {
        int left = index * 2;
        int right = index * 2 + 1;
        if (right <= t->last_index)
        {
            if (temp[left]->priority >= temp[right]->priority)
            {
                if (temp[index]->priority < temp[left]->priority)
                {
                    swap(t, index, left);
                    index = left;
                }
                else if (temp[index]->priority >= temp[left]->priority)
                {
                    break;
                }
            }
            else if (temp[left]->priority < temp[right]->priority)
            {
                if (temp[index]->priority < temp[right]->priority)
                {
                    swap(t, index, right);
                    index = right;
                }
                else if (temp[index]->priority >= temp[right]->priority)
                {
                    break;
                }
            }
        }
        else if (left <= t->last_index)
        {
            if (temp[index]->priority < temp[left]->priority)
            {
                swap(t, index, left);
            }
            break;
        }
        else
        {
            break;
        }
    }
}

/// @brief initialize heap by malloc every thing in heap
/// @param n size of heap
/// @return address of heap
heap_t *init_heap(int n)
{
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    h->data = (node_t **)malloc((n + 1) * sizeof(node_t *));
    h->last_index = 0;
    int i;
    for (i = 0; i < n + 1; i++)
    {
        h->data[i] = newNode();
    }
    return h;
}

/// @brief insert node into heap and also balance the heap
/// @param t address of heap
/// @param data address of new node for insert into heap
void insert(heap_t *t, node_t *data)
{
    node_t **temp = t->data;
    t->last_index += 1;

    temp[t->last_index] = data;
    upperBalance(t, t->last_index);
}

/// @brief delete max node in heap and also balance the heap
/// @param t address of heap
void delete_max(heap_t *t)
{
    node_t **temp = t->data;
    temp[1] = temp[t->last_index];
    t->last_index -= 1;
    if (t->last_index < 0)
        t->last_index = 0;
    lowerBalance(t, 1);
}

/// @brief find max node in heap
/// @param t address of heap
/// @return address of max node
node_t *find_max(heap_t *t)
{
    if (t->last_index == 0)
        return NULL;
    return t->data[1];
}

/// @brief breadth first search for debug
/// @param t address of heap
void bfs(heap_t *t)
{
    for (int i = 1; i <= t->last_index; i++)
    {
        printf("%d:%s ", -t->data[i]->priority, t->data[i]->str);
    }
    printf("\n");
}

/// @brief depth first search for print huffman code answer
/// @param t address of node
/// @param seq string for print (left node is 0, right node is 1)
void dfs(node_t *t, char *seq)
{
    if (t == NULL)
        return;
    if (t->leftnode == NULL && t->rightnode == NULL)
    {
        printf("%s: %s\n", t->str, seq);
    }
    else
    {
        char *temp1 = malloc((strlen(seq) + 2) * sizeof(char));
        if (t->leftnode != NULL)
        {
            strcpy(temp1, seq);
            strcat(temp1, "0");
            dfs(t->leftnode, temp1);
        }
        if (t->rightnode != NULL)
        {
            strcat(seq, "1");
            dfs(t->rightnode, seq);
        }
    }
}
