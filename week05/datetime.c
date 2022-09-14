#include<stdio.h>

int months[20] = {31,28,31,30,31,30,31,31,30,31,30,31};
char name[20][5] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
char days[20][5] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
typedef struct datetime
{
    int date;
    int month;
    int year;
    int dayOfWeek;
    int hour;
    int minute;
    int second;
} datetime_t;

int isLeap(int year)
{
    if(year%400==0) return 1;
    if(year%100==0) return 0;
    if(year%4==0) return 1;
    return 0;
}

datetime_t createDate(int t)
{
    int day = t/3600/24;
    int hour = t/3600%24;
    int minute = t/60%60;
    int second = t%60;
    int dayOfWeek = (4 + day%7)%7;
    int i;
    for(i=1970;; i++)
    {
        if(isLeap(i))
        {
            if(day>=366) day-=366;
            else break;
        }
        else
        {
            if(day>=365) day -=365;
            else break;
        }
    }
    int year = i;
    if(isLeap(i)) months[1]++;
    for(i=0; i<12; i++)
    {
        if(day<months[i]) break;
        day -= months[i];
    }
    int month = i;
    datetime_t d ;
    d.date = day;
    d.month = month;
    d.year = year;
    d.dayOfWeek = dayOfWeek;
    d.hour = hour;
    d.minute = minute;
    d.second = second;
    return d;
}

void printDate(datetime_t d)
{
    printf("%s %d %s %d %02d:%02d:%02d",days[d.dayOfWeek],d.date+1,name[d.month],d.year,d.hour,d.minute,d.second);
}

int main(void)
{
    datetime_t inputDate;
    int timestamp;

    scanf("%d", &timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
}
