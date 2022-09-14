#include <stdio.h>
#include <stdlib.h>

void findStats(int nums[], int n, double* avg,int* maxi, int* mini)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(*mini>nums[i]) *mini=nums[i];
        if(*maxi<nums[i]) *maxi=nums[i];
        *avg += nums[i];
    }
    *avg/=n;
}

int main(void)
{
    int n, i, maxi=-999999, mini=999999;
    double avg=0;
    int *nums;

    scanf("%d", &n);
    nums = (int *)malloc(sizeof (int) * n);
    for (i=0; i<n; i++)
        scanf("%d", nums+i);
    findStats(nums,n,&avg,&maxi,&mini);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}
