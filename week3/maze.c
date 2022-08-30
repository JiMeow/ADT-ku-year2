#include<stdio.h>
#include<stdlib.h>

char arr[200][200];
int visit[200][200];
int ans[10010];
int sx,sy,gx,gy;
int n;

void traverseMaze(int nowx,int nowy,int nans)
{
    int i,j;
    ans[nans] = nowx*n+nowy;
    visit[nowx][nowy] = 1;
    if(arr[nowx][nowy] == 'G')
    {
        for(i=1; i<nans; i++)
        {
            int tempx = ans[i]/n;
            int tempy = ans[i]%n;
            arr[tempx][tempy] = '.';
        }
    }
    for(i=-1; i<=1; i++)
    {
        for(j=-1; j<=1; j++)
        {
            if(abs(i+j)==1 && nowx+i<n && nowx+i>=0 && nowy+j<n && nowy+j>=0)
            {
                if(arr[nowx+i][nowy+j]!='#' && visit[nowx+i][nowy+j]==0)
                {
                    traverseMaze(nowx+i,nowy+j,nans+1);
                }
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    char trash[10];
    fgets(trash, n+2, stdin);
    int i,j;
    for(i=0; i<n; i++)
    {
        fgets(arr[i], n+2, stdin);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(arr[i][j]=='S')
            {
                sx=i;
                sy=j;
            }
            if(arr[i][j]=='G')
            {
                gx=i;
                gy=j;
            }
        }
    }
    traverseMaze(sx,sy,0);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}
