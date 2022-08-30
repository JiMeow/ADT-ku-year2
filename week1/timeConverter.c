#include<stdio.h>
int main()
{
    long long a;
    scanf("%lld",&a);
    printf("%lld %lld %lld %lld",a/3600/24,a%(3600*24)/3600,a%3600/60,a%60);
    return 0;
}
