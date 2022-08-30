#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int name;
    struct node * next;
} node_t;

node_t* append(node_t* startNode,int n)
{
    int i;
    scanf("%d",&i);
    startNode = (node_t*) malloc(sizeof(node_t));
    startNode->data = i;
    startNode->name = 1;
    startNode->next = NULL;
    node_t* temp = startNode;
    for(i=1; i<n; i++)
    {
        int val;
        scanf("%d",&val);
        node_t* newnode = (node_t*) malloc(sizeof(node_t));
        newnode -> data = val;
        newnode -> next = NULL;
        newnode -> name = i+1;
        temp->next = newnode;
        temp = newnode;
    }
    return startNode;
}

int check(int n,int k)
{
    while(n>0)
    {
        if(n%10 == k) return 1;
        n/=10;
    }
    return 0;
}

node_t* removed(node_t* head,node_t* n)
{
    node_t* temp = head, *go;
    while(temp->next != n) temp = temp->next;
    go = temp->next;
    temp->next = temp->next->next;
    free(go);
    head = temp;
    return head;
}

int main()
{
    int n,k;
    node_t* head=NULL,*temp;
    scanf("%d%d",&n,&k);
    int i;
    head = append(head,n);
    temp = head;
    while(temp->next!=NULL) temp = temp->next;
    temp->next = head;
    temp = head;
    int num=1,cnt = n;
    while(cnt>1)
    {
        if(num%k==0 || check(num,k))
        {
            temp->data -= 1;
        }
        if(temp->data < 0)
        {
            head = removed(head,temp);
            cnt-=1;
        }
        num += 1;
        temp = temp->next;
    }
    printf("%d",head->name);
}
