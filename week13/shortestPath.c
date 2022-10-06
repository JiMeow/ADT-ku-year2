#include <stdio.h>
int arr[100][100];
int main()
{
    int i, j, k;
    for (i = 0; i < 100; i++)
        for (j = 0; j < 100; j++)
            arr[i][j] = 1e9;
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    for (i = 0; i < m; i++)
    {
        arr[i][i] = 0;
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        arr[a][b] = d;
        arr[b][a] = d;
    }
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
    for (i = 0; i < t; i++)
    {
        int s, e;
        scanf("%d%d", &s, &e);
        if (arr[s][e] >= 1e9)
        {
            printf("-1\n");
        }
        else
            printf("%d\n", arr[s][e]);
    }
}