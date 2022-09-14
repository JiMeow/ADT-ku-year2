#include <stdio.h>
#include <stdlib.h>
#include<week8.h>

#ifndef __bin_tree__
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif

// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header

int is_full(tree_t *t)
{
    if (t == NULL)
        return 1;
    if (t->left != NULL && t->right == NULL || t->left == NULL && t->right != NULL)
        return 0;
    return is_full(t->left) && is_full(t->right);
}

int size(tree_t *t)
{
    if (t == NULL)
        return 0;
    return 1 + size(t->left) + size(t->right);
}

int maxx(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return power(a, b / 2) * power(a, b / 2);
    return a * power(a, b / 2) * power(a, b / 2);
}

int height(tree_t *t)
{
    if (t == NULL)
        return 0;
    return 1 + maxx(height(t->left), height(t->right));
}

int is_perfect(tree_t *t)
{
    if (t == NULL)
        return 1;
    int h = height(t);
    return power(2, h) - 1 == size(t);
}

int is_perfect_helper(tree_t *t, int h)
{
    if (h < 0)
        return 0;
    if (t == NULL && h == 0)
        return 1;
    int hlocal = height(t);
    if (hlocal != h)
        return 0;
    return is_perfect(t);
}

int is_complete_helper(tree_t *t, int h)
{
    if (h < 0)
        return 0;
    if (t == NULL && h == 0)
        return 1;
    int hlocal = height(t);
    if (hlocal != h)
        return 0;
    return is_complete_helper(t->left, h - 1) && is_perfect_helper(t->right, h - 2) || is_perfect_helper(t->left, h - 1) && is_complete_helper(t->right, h - 1);
}

int is_complete(tree_t *t)
{
    if (t == NULL)
        return 1;
    int h = height(t);
    return is_complete_helper(t->left, h - 1) && is_perfect_helper(t->right, h - 2) || is_perfect_helper(t->left, h - 1) && is_complete_helper(t->right, h - 1);
}

int is_degenerate(tree_t *t)
{
    if (t == NULL)
        return 1;
    if (t->left != NULL && t->right != NULL)
        return 0;
    return is_degenerate(t->left) && is_degenerate(t->right);
}

int is_skewed(tree_t *t)
{
    if (t == NULL)
        return 1;
    if (t->left != NULL && t->right != NULL)
        return 0;
    if (t->left != NULL && t->left->right != NULL)
        return 0;
    if (t->right != NULL && t->right->left != NULL)
        return 0;
    return is_skewed(t->left) && is_skewed(t->right);
}
// ...

int main(void)
{
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }

    printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

    return 0;
}
