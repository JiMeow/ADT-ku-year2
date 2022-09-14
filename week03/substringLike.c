#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char x[100100],y[100100];
int main()
{
    int sa,sb,e;
    scanf("%d %d %d",&sa,&sb,&e);
    scanf("%s %s",x,y);
    int i,j;
    for(i=0; i<=sa-sb; i++)
    {
        int error = 0;
        for(j=0; j<sb; j++)
        {
            if(x[i+j]!=y[j])
            {
                error++;
            }
        }
        if(error<=e)
        {
            printf("[");
            for(j=0; j<sb; j++)
            {
                if(x[i+j]!=y[j])
                {
                    printf("?");
                }
                else
                {
                    printf("%c",x[i+j]);
                }
            }
            printf("]");
            i+=sb-1;
        }
        else
        {
            printf("%c",x[i]);
        }
    }
    for(; i<sa; i++)
        printf("%c",x[i]);
    return 0;
}
