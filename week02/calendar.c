#include<stdio.h>
int main()
{
    int y,m;
    printf("Enter year: ");
    scanf("%d",&y);
    printf("Enter month: ");
    scanf("%d",&m);
    int i;
    for(i=0; i<20; i++) printf("=");
    printf("\n");
    char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int dayinmonth[13] = {31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
    printf("%s %d\n",month[m-1],y);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int plusday=0;
    for(i=1990; i<y; i++)
    {
        if(i%400==0)
            plusday += 366;
        else if(i%100==0)
            plusday += 365;
        else if(i%4==0)
            plusday += 366;
        else
            plusday += 365;
    }
    if(i%400==0)
        dayinmonth[1] += 1;
    else if(i%100==0)
        dayinmonth[1] += 0;
    else if(i%4==0)
        dayinmonth[1] += 1;
    for(i=0; i<m-1; i++)
    {
        plusday += dayinmonth[i];
    }
    plusday%=7;
    if(plusday != 6)
    {
        for(i=0; i<=plusday; i++) printf("    ");
    }
    for(i=0; i<dayinmonth[m-1]; i++)
    {
        if(plusday!=6)
        {
            printf("%3d ",i+1);
            int temp = 6-plusday;
            if((i+1)%7==temp) printf("\n");
        }
        else
        {
            printf("%3d ",i+1);
            if(i!=0 && i%7==0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");
}
