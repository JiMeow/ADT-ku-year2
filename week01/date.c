#include<stdio.h>
int main()
{
    char x[10];
    scanf("%s",x);
    int day = (x[0]-48)*10+x[1]-48;
    int month = (x[3]-48)*10+x[4]-48;
    int year = (x[6]-48)*1000+(x[7]-48)*100+(x[8]-48)*10+x[9]-48;
    int md[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
    int ans = 0;
    int i;
    if(year%4==0)
        md[1] = 29;
    else
        md[1] = 28;
    for(i=0; i<month-1; i++) ans += md[i];
    ans += day;
    printf("%d",ans);
    return 0;
}
