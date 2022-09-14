#include<stdio.h>
int go[2000100],limit[2000100];
int n,k,cnt;
int check(int n,int k)
{
    while(n!=0)
    {
        if(n%10==k) return 1;
        n/=10;
    }
    return 0;
}
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&limit[i]);
    }
    for(i=1; i<n; i++)
    {
        go[i] = i+1;
    }
    go[n] = 1;
    int now=1,num=1;
    int prev = n;
    cnt = n;
    while(1)
    {
        if(num%k==0 || check(num,k))
        {
            limit[now] -= 1;
        }
        if(limit[now]<0)
        {
            int temp=now;
            go[prev] = go[now];
            cnt--;
        }
        else
        {
            prev = now;
        }
        if(cnt==1) break;
        now = go[now];
        num++;
    }
    for(i=1; i<=n; i++)
    {
        if(limit[i]>=0)
        {
            printf("%d",i);
            break;
        }
    }
}
