#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int mcm(int *arr,int i,int j)
{
    if(i==j)
      return 0;
    if(dp[i][j]!=-1)
       return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        dp[i][j]=min(dp[i][j],mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j];
}
int main()
{
    int arr[]={40,20,30,10,30};
    memset(dp,-1,sizeof(dp));
    cout<<mcm(arr,1,4);
}