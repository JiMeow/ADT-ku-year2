#include <stdio.h>
#include <stdlib.h>
int arrgo[100][100];
int visitgo[100];
int arrback[100][100];
int visitback[100];
int timecount[100];
int timebackcount[100];
int anslist[100];
int n, m, ans;
int timego, timeback, temptime;

void dfs(int node, int *t)
{
    visitgo[node] = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arrgo[node][i] == 1 && visitgo[i] == 0)
        {
            dfs(i, t);
        }
    }
    timecount[node] = *t;
    (*t)++;
}

void dfsback(int node, int *t, int *list)
{
    visitback[node] = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arrback[node][i] == 1 && visitback[i] == 0)
        {
            dfsback(i, t, list);
        }
    }
    timebackcount[node] = *t;
    list[*t - temptime] = node;
    (*t)++;
}

int main()
{
    int *list = malloc(sizeof(int) * 100);
    int i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        arrgo[a][b] = 1;
        arrback[b][a] = 1;
    }
    for (i = 0; i < n; i++)
    {
        if (visitgo[i] == 0)
            dfs(i, &timego);
    }
    int j;
    for (i = 0; i < n; i++)
    {
        int maxTime = 0;
        int idx = -1;
        for (j = 0; j < n; j++)
        {
            if (visitback[j] == 0 && maxTime < timecount[j])
            {
                maxTime = timecount[j];
                idx = j;
            }
        }
        if (idx == -1)
            break;
        temptime = timeback;
        dfsback(idx, &timeback, list);
        int size = timeback - temptime;
        if (ans < size)
        {
            ans = size;
            for (j = 0; j < size; j++)
            {
                anslist[j] = list[j];
            }
        }
    }
    // bubble sort anslist
    for (i = 0; i < ans; i++)
    {
        for (j = 0; j < ans - i - 1; j++)
        {
            if (anslist[j] > anslist[j + 1])
            {
                int temp = anslist[j];
                anslist[j] = anslist[j + 1];
                anslist[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < ans; i++)
    {
        printf("%d ", anslist[i]);
    }
}