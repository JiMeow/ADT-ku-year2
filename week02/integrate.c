#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,B,A;
    int n;
    double ans;
    scanf("%lf %lf %lf %lf %d",&a,&b,&A,&B,&n);
    double sum=0;
    int i;
    double side=(b-a)/n;
    for(i=0; i<n; i++)
    {
        double sidea=a+side*i;
        double sideb=a+side*(i+1);
        ans = A*(sin(M_PI*sidea/B)+sin(M_PI*sideb/B))/2.0*side;
	sum += ans;
    }
        printf("%.5lf",sum);
}
