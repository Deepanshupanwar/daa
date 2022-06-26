#include<bits/stdc++.h>
using namespace std;
void lps(char *s2,int *lp,int n)
{
    int len =0;
    lp[0]=0;
    int i=1;
    while(i<n)
    {
        if(s2[i]==s2[len])
        {
            len++;
            lp[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lp[len-1];
            }
            else
            {
                lp[i]=0;
                i++;
            }
        }
    }
}
void kmp(char *s1,char *s2)
{
    int m=strlen(s1);
    int n=strlen(s2);
    int lp[n];
    lps(s2,lp,n);
    int i=0,j=0;
    while(i<m)
    {
        if(s1[i]==s2[j])
        {
            i++;
            j++;
        }
        if(j==n)
        {
            cout<<i-j<<endl;
            j=lp[j-1];
        }
        else if(i<m&&s1[i]!=s2[j])
        {
            if(j!=0)
              j=lp[j-1];
            else
              i++;
        }
    }
}
int main()
{
    char  s1[]="aacdbbcdbe";
    char s2[]="cdbe";
    kmp(s1,s2);
}