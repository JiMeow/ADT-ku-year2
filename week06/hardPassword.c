#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int          data;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t* push(stack_t* s, int value)
{
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->data = value;
    node->next = NULL;

    if(s==NULL)
    {
        return node;
    }
    else
    {
        node->next = s;
    }
    return node;
}

int top(stack_t* s)
{
    if(s==NULL)
    {
        return;
    }
    return s->data;
}

stack_t* pop(stack_t* s)
{
    if(s==NULL) return s;
    stack_t* node = s->next;
    free(s);
    return node;
}

int empty(stack_t* s)
{
    if(s==NULL)
        return 1;
    else
        return 0;
}

int size(stack_t* s)
{
    int n=0;
    while(s!=NULL)
    {
        n+=1;
        s = s-> next;
    }
    return n;
}

char s[10000000];
int main(void)
{
    stack_t* st=NULL,*temp=NULL;
    scanf("%s",s);
    int n = strlen(s);
    int i,data;
    for(i=0; i<n; i++)
    {
        if(s[i]!='x' && s[i]!='y')
            temp = push(temp,s[i]);
    }
    n = size(temp);
    if(n%2==0)
    {
        for(i=0; i<n/2; i++)
        {
            data = top(temp);
            st = push(st,data);
            temp = pop(temp);
        }
        for(i=n/2; i<n; i++)
        {
            if(top(temp) != top(st))
            {
                printf("0");
                return 0;
            }
            else
            {
                temp = pop(temp);
                st = pop(st);
            }
        }
        printf("1");
    }
    else
    {
        printf("0");
        return;
    }
}
