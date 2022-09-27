#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[100010][100];
char re[100010][100];

int cmp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int main()
{
    int n, m, i, j;
    scanf("%d", &n);
    scanf("%d", &m);
    for (i = 0; i < n; i++)
    {
        scanf("%s", re[i]);
        strcpy(a[i], re[i]);
        qsort(a[i], strlen(a[i]), sizeof(char), cmp);
    }
    for (i = 0; i < m; i++)
    {
        char temp[100];
        scanf("%s", temp);
        qsort(temp, strlen(temp), sizeof(char), cmp);
        for (j = 0; j < n; j++)
        {
            if (!strcmp(temp, a[j]))
            {
                printf("%s ", re[j]);
            }
        }
        printf("\n");
    }
}