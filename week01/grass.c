#include<stdio.h>
int main()
{
    int a,b;
    printf("length(m.):" );
    scanf("%d",&a);
    printf("width(m.):" );
    scanf("%d",&b);
    printf("Use %.5f seconds.",(float)(a*b)*1.64042*3.28084);
    return 0;
}
