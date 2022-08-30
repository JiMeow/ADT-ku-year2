#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *child;
    struct node *sibling;
} node_t;

typedef node_t tree_t;

tree_t* makenewnode(int val)
{
    tree_t* newnode = (tree_t*) malloc(sizeof(tree_t));
    newnode -> value = val;
    newnode -> child = NULL;
    newnode -> sibling = NULL;
    return newnode;
}

tree_t* find(tree_t *tree, int v)
{
    if(tree==NULL || tree->value == v)
        return tree;
    tree_t* result = find(tree->child,v);
    if(result!=NULL)
    {
        return result;
    }
    return find(tree->sibling,v);
}

tree_t* attach(tree_t *tree, int p, int v)
{
    tree_t* newnode = makenewnode(v);
    tree_t* pos = find(tree,p);
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

void helperdetach(tree_t* tree, int v)
{
    if(tree==NULL) return;
    //printf("%d ", tree->value);
    if(tree->value == v) return;
    if(tree->sibling != NULL && tree->sibling->value == v)
    {
        //printf("complete\n");
        tree->sibling = tree->sibling->sibling;
    }
    else if(tree->child != NULL && tree->child->value == v)
    {
        //printf("complete\n");
        tree->child = tree->child->sibling;
    }
    else
    {
        if(tree->sibling != NULL)
        {
            helperdetach(tree->sibling,v);
        }
        if(tree->child != NULL )
        {
            helperdetach(tree->child,v);
        }
    }

}

tree_t* detach(tree_t* tree, int v)
{
    if(tree==NULL) return NULL;
    if(tree->value==v) return NULL;
    helperdetach(tree,v);
    return tree;
}

int search(tree_t* tree, int v)
{
    if(find(tree,v) == NULL) return 0;
    return 1;
}

int degree(tree_t* tree,int v)
{
    tree_t* pos = find(tree,v);
    if(pos == NULL) return 0;
    int ans=0;
    if(pos->child == NULL) return ans;
    pos = pos->child;
    ans++;
    while(pos->sibling != NULL)
    {
        pos = pos->sibling;
        ans++;
    }
    return ans;
}

int is_root(tree_t* tree,int v)
{
    if(tree->value == v) return 1;
    return 0;
}

int is_leaf(tree_t* tree,int v)
{
    tree_t* pos = find(tree,v);
    if(pos==NULL) return 0;
    if(pos->child==NULL) return 1;
    return 0;
}

tree_t* findsibling(tree_t* tree,int v)
{
    tree_t* temp = tree;
    while(temp!=NULL)
    {
        if(temp->value == v)
        {
            return tree;
        }
        else
        {
            if(temp->child !=NULL)
            {
                tree_t* ans = findsibling(temp->child,v);
                if(ans!=NULL)
                {
                    return ans;
                }
            }
        }
        temp = temp->sibling;
    }
    return NULL;
}

void siblings(tree_t* tree,int v)
{
    tree_t* pos = findsibling(tree,v);
    while(pos != NULL)
    {
        if(pos->value != v)
            printf("%d ", pos->value);
        pos = pos->sibling;
    }
    printf("\n");
}

int depth(tree_t* tree,int v)
{
    if(tree==NULL) return -1;
    tree_t* arr[10000];
    int dep[10000];
    int index=0;
    int cnt=1;
    arr[0] = tree;
    dep[0] = 0;
    if(tree->value == v) return 0;
    while(index<cnt)
    {
        int nowdepth = dep[index]+1;
        tree_t* now = arr[index]->child;
        index++;
        while(now!=NULL)
        {
            arr[cnt] = now;
            dep[cnt] = nowdepth;
            cnt++;
            if(now->value == v) return nowdepth;
            now = now->sibling;
        }
    }

}
void printdfs(tree_t* tree)
{
    if(tree == NULL) return;
    printf("%d ",tree->value);
    printdfs(tree->child);
    printdfs(tree->sibling);
}

int findpath(tree_t* now,int end,int* ans)
{
    if(now==NULL) return 0;
    *ans = now->value;
    if(now -> value == end)
    {
        return 1;
    }
    if(findpath(now->child,end,ans+1) == 1)
        return 1;
    if(findpath(now->sibling,end,ans) == 1)
        return 1;
}

void print_path(tree_t* tree,int start,int end)
{
    int* ans = (int*) malloc(10000*sizeof(int));
    tree_t* pos = find(tree,start);
    findpath(pos,end,ans);
    int i=0;
    for(; ans[i]!=end; i++)
        printf("%d ",ans[i]);
    printf("%d\n",end);
}

int path_length(tree_t* tree,int start,int end)
{
    int* ans = (int*) malloc(10000*sizeof(int));
    tree_t* pos = find(tree,start);
    findpath(pos,end,ans);
    int i=0;
    for(; ans[i]!=end; i++) {}
    i+=1;
    return i;
}

void ancestor(tree_t* tree,int v)
{
    print_path(tree,tree->value,v);
}

void descendant(tree_t* tree,int v)
{
    if(tree==NULL) return;
    tree_t* arr[10000];
    int index=0;
    int cnt=1;
    arr[0] = find(tree,v);
    while(index<cnt)
    {
        printf("%d ",arr[index]->value);
        tree_t* now = arr[index]->child;
        index++;
        while(now!=NULL)
        {
            arr[cnt] = now;
            cnt++;
            now = now->sibling;
        }
    }
    printf("\n");
}

void bfs(tree_t* tree)
{
    if(tree==NULL) return;
    tree_t* arr[10000];
    int index=0;
    int cnt=1;
    arr[0] = tree;
    while(index<cnt)
    {
        printf("%d ",arr[index]->value);
        tree_t* now = arr[index]->child;
        index++;
        while(now!=NULL)
        {
            arr[cnt] = now;
            cnt++;
            now = now->sibling;
        }
    }
    printf("\n");
}

void dfs(tree_t* tree)
{
    printdfs(tree);
    printf("\n");
}

void depthdfs(tree_t* tree,int d)
{
    if(tree==NULL) return;
    int i;
    for(i=0; i<d; i++)
    {
        printf("    ");
    }
    printf("%d\n", tree->value);
    depthdfs(tree->child,d+1);
    depthdfs(tree->sibling,d);
}

void print_tree(tree_t* tree)
{
    depthdfs(tree,0);
}

int main(void)
{
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;

    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &command);
        switch(command)
        {
        case 1:
            scanf("%d %d", &parent, &child);
            t = attach(t, parent, child);
            break;
        case 2:
            scanf("%d", &node);
            t = detach(t, node);
            break;
        case 3:
            scanf("%d", &node);
            printf("%d\n", search(t, node));
            break;
        case 4:
            scanf("%d", &node);
            printf("%d\n", degree(t, node));
            break;
        case 5:
            scanf("%d", &node);
            printf("%d\n", is_root(t, node));
            break;
        case 6:
            scanf("%d", &node);
            printf("%d\n", is_leaf(t, node));
            break;
        case 7:
            scanf("%d", &node);
            siblings(t, node);
            break;
        case 8:
            scanf("%d", &node);
            printf("%d\n", depth(t, node));
            break;
        case 9:
            scanf("%d %d", &start, &end);
            print_path(t, start, end);
            break;
        case 10:
            scanf("%d %d", &start, &end);
            printf("%d\n", path_length(t, start, end));
            break;
        case 11:
            scanf("%d", &node);
            ancestor(t, node);
            break;
        case 12:
            scanf("%d", &node);
            descendant(t, node);
            break;
        case 13:
            bfs(t);
            break;
        case 14:
            dfs(t);
            break;
        case 15:
            print_tree(t);
            break;

        }
    }
    return 0;
}

