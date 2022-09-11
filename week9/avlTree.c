#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t avl_t;
#endif

int maxx(int a, int b)
{
    return (a > b) ? a : b;
}

avl_t *createNode(int val)
{
    avl_t *node = (avl_t *)malloc(sizeof(avl_t));
    node->data = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int height(avl_t *node)
{
    if (node == NULL)
        return -1;
    return node->height;
}
avl_t *leftRotate(avl_t *t)
{
    avl_t *r = t->right;
    avl_t *rl = r->left;
    t->right = rl;
    r->left = t;
    t->height = 1 + maxx(height(t->left), height(t->right));
    r->height = 1 + maxx(height(r->left), height(r->right));
    return r;
}
avl_t *rightRotate(avl_t *t)
{
    avl_t *l = t->left;
    avl_t *lr = l->right;
    l->right = t;
    t->left = lr;
    t->height = maxx(height(t->left), height(t->right)) + 1;
    l->height = maxx(height(l->left), height(l->right)) + 1;
    return l;
}

avl_t *left_rightRotate(avl_t *t)
{
    avl_t *l = t->left;
    t->left = leftRotate(l);
    return rightRotate(t);
}

avl_t *right_leftRotate(avl_t *t)
{
    avl_t *r = t->right;
    t->right = rightRotate(r);
    return leftRotate(t);
}

int get_balance(avl_t *t)
{
    if (t == NULL)
        return 0;
    return height(t->left) - height(t->right);
}

avl_t *insert(avl_t *node, int val)
{
    if (node == NULL)
    {
        return createNode(val);
    }
    if (val < node->data)
        node->left = insert(node->left, val);
    if (val > node->data)
        node->right = insert(node->right, val);

    node->height = 1 + maxx(height(node->left), height(node->right));
    int balance = height(node->left) - height(node->right);
    if (balance > 1 && val < node->left->data)
        return rightRotate(node);
    if (balance < -1 && val > node->right->data)
        return leftRotate(node);
    if (balance > 1 && val > node->left->data)
        return left_rightRotate(node);
    if (balance < -1 && val < node->right->data)
        return right_leftRotate(node);
    return node;
}

avl_t *delete (avl_t *node, int val)
{
    if (node == NULL)
        return node;
    if (val < node->data)
        node->left = delete (node->left, val);
    if (val > node->data)
        node->right = delete (node->right, val);
    if (val == node->data)
    {
        if (node->left == NULL)
        {
            avl_t *temp = node->right;
            free(node);
            return temp;
        }
        if (node->right == NULL)
        {
            avl_t *temp = node->left;
            free(node);
            return temp;
        }
        if (node->left != NULL && node->right != NULL)
        {
            avl_t *temp = node->right;
            while (temp->left != NULL)
                temp = temp->left;
            node->data = temp->data;
            node->right = delete (node->right, temp->data);
        }
    }
    node->height = 1 + maxx(height(node->left), height(node->right));
    int balance = height(node->left) - height(node->right);

    if (balance > 1 && height(node->left->left) >= height(node->left->right))
        return rightRotate(node);
    if (balance < -1 && height(node->right->right) >= height(node->right->left))
        return leftRotate(node);
    if (balance > 1 && height(node->left->right) > height(node->left->left))
        return left_rightRotate(node);
    if (balance < -1 && height(node->right->left) > height(node->right->right))
        return right_leftRotate(node);

    return node;
}

int main(void)
{
    avl_t *t = NULL;
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
            print_tree(t);
            break;
        }
    }
    return 0;
}