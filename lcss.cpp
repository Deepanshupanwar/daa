#include<bits/stdc++.h>
using namespace std;
int dp[6][5];
int subs(int n,int m,string s1,string s2)
{
if(n==0||m==0)
  return 0;
  if(dp[n][m]!=-1)
    return dp[n][m];
if(s1[n]==s2[m])
{
    return dp[n][m]=1+subs(n-1,m-1,s1,s2);
}
else
{
    int i=subs(n-1,m,s1,s2);
    int j=subs(n,m-1,s1,s2);
    if(i>j)
     return dp[n][m]=i;
    return dp[n][m]=j;
}
}
int main()
{
    int n=5;
    int m=4;
    string s1="abcab";
    string s2="aecb";
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
          dp[i][j]=-1;
    }
    cout<<subs(n,m,s1,s2);
}