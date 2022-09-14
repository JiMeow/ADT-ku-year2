#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *child;
    struct node *sibling;
} node_t;

typedef node_t node;

node* makenewnode(int val)
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode -> value = val;
    newnode -> child = NULL;
    newnode -> sibling = NULL;
    return newnode;
}

node* serch(node *tree, int v)
{
    if(tree==NULL || tree->value == v)
        return tree;
    node* result = serch(tree->child,v);
    if(result!=NULL)
    {
        return result;
    }
    return serch(tree->sibling,v);
}

node* attach(node *tree, int p, int v)
{
    node* newnode = makenewnode(v);
    node* pos = serch(tree,p);
    if(pos == NULL)
        return newnode;
    if(pos->child == NULL)
    {
        pos->child = newnode;
    }
    else
    {
        pos = pos->child;
        while(pos->sibling != NULL)
        {
            pos = pos->sibling;
        }
        pos -> sibling = newnode;
    }
    return tree;
}

void dfs(node* tree)
{
    //printf("HI");
    if(tree == NULL) return;
    printf("%d ",tree->value);
    dfs(tree->child);
    dfs(tree->sibling);
}

int main()
{
    node* root = NULL;
    attach(root,1,1);
    dfs(root);
    attach(root,1,2);
    dfs(root);
    attach(root,1,3);
    dfs(root);
    attach(root,2,4);
    dfs(root);
    attach(root,2,5);
    dfs(root);
    attach(root,3,6);
    dfs(root);
    attach(root,3,7);
    dfs(root);
    attach(root,4,8);
    dfs(root);
    attach(root,5,9);
    dfs(root);
    attach(root,5,10);
    dfs(root);
    attach(root,6,11);
    dfs(root);
    attach(root,6,12);
    dfs(root);
    attach(root,6,13);
    dfs(root);
    attach(root,6,14);
    dfs(root);
    return 1;
}
