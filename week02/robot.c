#include<stdio.h>
#include<math.h>
#include<stdlib.h>
      char s[1000010];
main()
{
    int x=0,y=0;
    int di=0;
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int i;
    for(i=0; i<n; i++)
    {
        if(s[i]=='F')
        {
            di%=360;
	    if(di<0) di+=360;
            if(di==0)
            {
                x++;
            }
            if(di==90)
            {
                y++;
            }
            if(di==180)
            {
                x--;
            }
            if(di==270)
            {
		    y--;
            }
        }
        if(s[i]=='L')
        {
            di-=90;
        }
        if(s[i]=='R')
        {
            di+=90;
        }
    }
    printf("%.4f",sqrt(x*x+y*y));
}
