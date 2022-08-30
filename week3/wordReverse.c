#include<stdio.h>
#include<string.h>
char s[100100];
char sub[30010][60];
int main()
{
    fgets(s,100100,stdin);
    int i;
    int word=0;
    for(i=0; i<strlen(s)-1; i++)
    {
        if(s[i]!=' ')
            sub[word][strlen(sub[word])] = s[i];
        else
            word++;
    }
    for(i=0; i<=word; i++)
    {
        printf("%s ",sub[word-i]);
    }
}
