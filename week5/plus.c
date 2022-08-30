#include<stdio.h>
#include<string.h>

int min(int a,int b)
{
    if(a>b) return b;
    return a;
}

int max(int a,int b)
{
    return a + b - min(a,b);
}
char arr1[1000000],arr2[1000000],s[1010000];
int main()
{
    scanf("%s",&arr1);
    scanf("%s",&arr2);
    int i;
    int a=strlen(arr1),b=strlen(arr2);
    for(i=1; i<=min(a,b); i++)
    {
        s[i-1] = arr1[a-i]-'0' + arr2[b-i]-'0';
    }
    if(a>b)
    {
        for(; i<=a; i++)
            s[i-1] += arr1[a-i]-'0';
    }
    if(b>a)
    {
        for(; i<=b; i++)
            s[i-1] += arr2[b-i]-'0';
    }
    for(i=0; i<max(a,b); i++)
    {
        if(s[i]>=10)
        {
            s[i] -= 10;
            s[i+1] += 1;
        }
    }
    if(s[max(a,b)] == 1)
    {
        printf("1");
    }
    for(i=0; i<max(a,b); i++)
    {
        printf("%d",s[max(a,b)-i-1]);
    }
}
