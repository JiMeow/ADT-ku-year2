#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    float        data;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t* push(stack_t* s, float value)
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

float top(stack_t* s)
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
int main(void)
{
    stack_t* st = NULL;
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int i;
    for(i=0; i<n; i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st = push(st,s[i]-'0');
        }
        else
        {
            float b=top(st);
            st = pop(st);
            float a=top(st);
            st = pop(st);
            if(s[i]=='+')
            {
                st = push(st,a+b);
            }
            if(s[i]=='-')
            {
                st = push(st,a-b);
            }
            if(s[i]=='*')
            {
                st = push(st,a*b);
            }
            if(s[i]=='/')
            {
                st = push(st,a/b);
            }
        }
    }
    printf("%.2f",top(st));
}
