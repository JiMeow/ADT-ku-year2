#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t bst_t;

int find(bst_t *t, int x)
{
    if (t == NULL)
        return 0;
    if (t->data == x)
        return 1;
    if (x < t->data)
        return find(t->left, x);
    else
        return find(t->right, x);
}

bst_t *createNode(int x)
{
    bst_t *newNode = (bst_t *)malloc(sizeof(bst_t));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bst_t *insert(bst_t *t, int x)
{
    if (t == NULL)
        return createNode(x);
    if (x < t->data)
        t->left = insert(t->left, x);
    else if (x > t->data)
        t->right = insert(t->right, x);
    return t;
}

bst_t *delete (bst_t *t, int x)
{
    if (t == NULL)
        return t;
    if (x < t->data)
        t->left = delete (t->left, x);
    else if (x > t->data)
        t->right = delete (t->right, x);
    else
    {
        if (t->left == NULL)
        {
            bst_t *temp = t->right;
            free(t);
            return temp;
        }
        if (t->right == NULL)
        {
            bst_t *temp = t->left;
            free(t);
            return temp;
        }
        if (t->left != NULL && t->right != NULL)
        {
            bst_t *temp = t->right;
            while (temp->left != NULL)
                temp = temp->left;
            t->data = temp->data;
            t->right = delete (t->right, temp->data);
        }
    }
    return t;
}

int find_min(bst_t *t)
{
    while (t->left != NULL)
        t = t->left;
    return t->data;
}
int find_max(bst_t *t)
{
    while (t->right != NULL)
        t = t->right;
    return t->data;
}

int main(void)
{
    bst_t *t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete (t, data);
            break;
        case 3:
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
    return 0;
}