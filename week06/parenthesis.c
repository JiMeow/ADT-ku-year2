#include <stdio.h>
#include <stdlib.h>

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

char s[2000000];

int match(int a,int b)
{
    if(a=='(' && b==')')
    {
        return 1;
    }
    if(a=='{' && b=='}')
    {
        return 1;
    }
    if(a=='[' && b==']')
    {
        return 1;
    }
    if(a==')' && b=='(')
    {
        return 1;
    }
    if(a==']' && b=='[')
    {
        return 1;
    }
    if(a=='}' && b=='{')
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    stack_t *st = NULL;
    int      n, i;

    scanf("%d", &n);
    scanf("%s",s);
    for(i=0; i<n; i++)
    {
        if(s[i] == '{' || s[i]== '(' || s[i]== '[')
            st = push(st,s[i]);
        else
        {
            if(match(s[i],top(st)))
            {
                st = pop(st);
            }
            else
            {
                printf("0");
                return 1;
            }
        }
    }
    if(empty(st)) printf("1");
    else printf("0");
}
