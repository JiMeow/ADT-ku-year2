#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int *data;
    int last_index;
} heap_t;

void swap(heap_t *t, int a, int b)
{
    int temp = t->data[a];
    t->data[a] = t->data[b];
    t->data[b] = temp;
}

void upperBalance(heap_t *t, int index)
{
    int *temp = t->data;
    while (index > 1)
    {
        if (temp[index] > temp[index / 2])
        {
            swap(t, index, index / 2);
            index /= 2;
        }
        else
            break;
    }
}

void lowerBalance(heap_t *t, int index)
{
    int *temp = t->data;
    while (index <= t->last_index)
    {
        int left = index * 2;
        int right = index * 2 + 1;
        if (right <= t->last_index)
        {
            if (temp[left] > temp[right])
            {
                if (temp[index] < temp[left])
                {
                    swap(t, index, left);
                    index = left;
                }
                else if (temp[index] >= temp[left])
                {
                    break;
                }
            }
            else if (temp[left] <= temp[right])
            {
                if (temp[index] < temp[right])
                {
                    swap(t, index, right);
                    index = right;
                }
                else if (temp[index] >= temp[right])
                {
                    break;
                }
            }
        }
        else if (left <= t->last_index)
        {
            if (temp[index] < temp[left])
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

heap_t *init_heap(int m)
{
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    h->data = (int *)malloc(sizeof(int) * m + 1);
    h->last_index = 0;
    return h;
}

void insert(heap_t *t, int val)
{
    int *temp = t->data;
    t->last_index += 1;
    temp[t->last_index] = val;
    upperBalance(t, t->last_index);
}

void delete_max(heap_t *t)
{
    int *temp = t->data;
    temp[0] = temp[t->last_index];
    t->last_index -= 1;
    if (t->last_index < 0)
        t->last_index = 0;
    lowerBalance(t, 0);
}

int find_max(heap_t *t)
{
    if (t->last_index == 0)
        return -1;
    return t->data[1];
}

void update_key(heap_t *t, int old_key, int new_key)
{
    int *temp = t->data;
    int index = 0;
    for (int i = 1; i <= t->last_index; i++)
    {
        if (temp[i] == old_key)
            index = i;
    }
    temp[index] = new_key;

    upperBalance(t, index);
    lowerBalance(t, index);
}

void bfs(heap_t *t)
{
    for (int i = 1; i <= t->last_index; i++)
    {
        printf("%d ", t->data[i]);
    }
    printf("\n");
}

int main(void)
{
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;

    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            insert(max_heap, data);
            break;
        case 2:
            delete_max(max_heap);
            break;
        case 3:
            printf("%d\n", find_max(max_heap));
            break;
        case 4:
            scanf("%d %d", &old_key, &new_key);
            update_key(max_heap, old_key, new_key);
            break;
        case 5:
            bfs(max_heap);
            break;
        }
    }
    return 0;
}