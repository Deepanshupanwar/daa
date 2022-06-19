#include<bits/stdc++.h>
using namespace std;
int coin(int n,int arr[],int k,int dp[])
{
    if(n==0)
      return 0;
      int ans=999999;
    for(int i=0;i<k;i++)
    {
        int subans=0;
        if(n-arr[i]>=0){
            if(dp[n-arr[i]]!=-1)//for dp
               subans=dp[n-arr[i]];//for dp
            else
            subans=coin(n-arr[i],arr,k,dp);
        if(subans!=999999&&subans+1<ans)
        ans=subans+1;
        }
    }
    dp[n]=ans;//for dp
    return ans;
}
int main()
{
    int n=18;
    int arr[]={7,5,1};
    int k=3;
    int dp[n+1];//for dynamic programming
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    cout<<coin(n,arr,k,dp)<<endl;
}