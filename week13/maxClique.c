#include <stdio.h>
int arr[100][100];
int visit[100];
int n, m;
int ans = 1;

int checkGraph()
{
    int i, j, size = 0;
    for (i = 0; i < n; i++)
    {
        size += visit[i];
        if (visit[i] == 1)
        {
            for (j = i + 1; j < n; j++)
            {
                if (visit[j] == 1)
                {
                    if (arr[i][j] == 0)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return size;
}

void permu(int index)
{
    if (index == n)
    {
        int complete = checkGraph();
        if (ans < complete)
        {
            ans = complete;
        }
        return;
    }
    visit[index] = 1;
    permu(index + 1);
    visit[index] = 0;
    permu(index + 1);
}

int main()
{
    scanf("%d%d", &n, &m);
    int i;
    for (i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    int max = 0;
    permu(0);
    printf("%d", ans);
}