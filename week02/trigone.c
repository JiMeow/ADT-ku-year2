#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double sinn(int n,double x)
{
    double ans=-1;
    if(n%2==1)
        ans =1;
    n = 2*n-1;
    int i;
    for(i=0; i<n; i++)
    {
        ans*=x;
        ans/=n-i;
    }
    return ans;
}
int main()
{
    double x;
    double sum=0;
    scanf("%lf",&x);
    int i;
    x/=180/M_PI;
    for(i=0; i<10; i++)
    {
        sum += sinn(i+1,x);
    }
    double cos = sqrt(1-sum*sum);
    printf("%.14lf %.14lf %.14lf",sum,cos,sum/cos);
    return 0;
}
