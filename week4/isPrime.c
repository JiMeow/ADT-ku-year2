#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i=2;
    int ans=0;
    if(n==1)
    {
        printf("0");
    }
    else if(n==2)
    {
        printf("1");
    }
    else
    {
        while(i*i<n)
        {
            if(n%i==0)
            {
                printf("0");
                ans=1;
                break;
            }
            i++;
        }
        if(!ans) printf("1");
    }
}
