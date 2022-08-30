#include<stdio.h>
int pow2[18];

int findIndex(int n)
{
    int i;
    int ans=-1;
    for(i=17; i>=0; i--)
    {
        if(n>=pow2[i])
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int isInArr(int n)
{
    int i;
    int ans=0;
    for(i=17; i>=0; i--)
    {
        if(n==pow2[i])
        {
            ans = i+1;
            break;
        }
    }
    return ans;
}

int solve(int n,int m)
{
    if(n==0 || m==0) return 0;

    if(n>m)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    int i;
    if(!isInArr(n))
    {
        int index = findIndex(n);
        return solve(n-pow2[index],m)+solve(pow2[index],m);
    }
    else if(!isInArr(m))
    {
        int index = findIndex(m);
        return solve(n,m-pow2[index])+solve(n,pow2[index]);
    }
    else
    {
        if(n==m)return 1;
        else
            return m/n;
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    pow2[0]=1;
    int i;
    for(i=1; i<18; i++)
    {
        pow2[i]=pow2[i-1]*2;
    }
    printf("%d",solve(n,m));

}
//O(log(max(n,m)))
