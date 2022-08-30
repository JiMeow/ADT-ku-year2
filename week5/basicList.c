#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} node_t;

node_t* append(node_t* startNode)
{
    int val;
    scanf("%d",&val);
    if(startNode == NULL)
    {
        startNode = (node_t*) malloc(sizeof(node_t));
        startNode->data = val;
        startNode->next = NULL;
    }
    else
    {
        node_t* newnode = (node_t*) malloc(sizeof(node_t));
        newnode -> data = val;
        newnode -> next = NULL;
        node_t* temp=startNode;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newnode;
    }
    return startNode;
}

void get(node_t* n)
{
    int index;
    scanf("%d",&index);
    while(index>0)
    {
        index--;
        n = n->next;
    }
    printf("%d\n",n->data);
}

void show(node_t* n)
{
    while(n!=NULL)
    {
        printf("%d ",n->data);
        n = n-> next;
    }
    printf("\n");
}

node_t* reverse(node_t* n)
{
    int* arr = (int*)malloc(10000*sizeof(int));
    int h=0;
    node_t* head = n;
    while(head!=NULL)
    {
        arr[h] = head->data;
        head = head->next;
        h++;
    }
    head = n;
    int i=1;
    while(head!=NULL)
    {
        head->data = arr[h-1];
        head = head->next;
        h--;
    }
    return n;
}

node_t* cut(node_t* n)
{
    int a,b;
    scanf("%d%d",&a,&b);
    int tempa=a;
    while(a--)
    {
        n = n->next;
    }
    node_t* n2 = n;
    int c=b-tempa;
    while(c--)
    {
        n2 = n2->next;
        if(n2==NULL) break;
    }
    n2->next = NULL;
    return n;
}

int main(void)
{
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf(" %c",&command);
        switch(command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        default:
            break;
        }
    }
    return 0;
}
