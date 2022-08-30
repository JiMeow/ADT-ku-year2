#include<stdio.h>
int main()
{
    int a,b;
    char c;
    scanf("%d%c%c%d",&a,&c,&c,&b);
    if(c=='+')
    {
        printf("%d",a+b);
    }
    else if(c=='-')
    {
        printf("%d",a-b);
    }
    else if(c=='*')
    {
        printf("%d",a*b);
    }
    else if(c=='/')
    {
        printf("%.2f",(float)a/(float)b);
    }
    else if(c=='%')
    {
        printf("%d",a%b);
    }
    else
    {
        printf("Unknown Operator");
    }
    return 0;
}
