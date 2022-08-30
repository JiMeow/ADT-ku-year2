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

void top(stack_t* s)
{
    if(s==NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("%d\n",s->data);
}

stack_t* pop(stack_t* s)
{
    if(s==NULL) return s;
    stack_t* node = s->next;
    free(s);
    return node;
}

void empty(stack_t* s)
{
    if(s==NULL)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}

void size(stack_t* s)
{
    int n=0;
    while(s!=NULL)
    {
        n+=1;
        s = s-> next;
    }
    printf("%d\n",n);
}

int main(void)
{
    stack_t *s = NULL;
    int      n, i, command, value;

    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &command);
        switch(command)
        {
        case 1:
            scanf("%d", &value);
            s = push(s, value);
            break;
        case 2:
            top(s);
            break;
        case 3:
            s = pop(s);
            break;
        case 4:
            empty(s);
            break;
        case 5:
            size(s);
            break;
        }
    }
    return 0;
}
