#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[100010];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // insertion sort
    for (i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}