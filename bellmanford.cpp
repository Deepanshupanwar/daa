#include <bits/stdc++.h>
using namespace std;
int bellman(int graph[][3],int n,int m,int s)
{
    int ans[n];
    memset(ans,10000000,sizeof(n));
    ans[s]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           int scr=graph[j][0];
           int dis=graph[j][1];
           int wt=graph[j][2];
           if(ans[dis]!=10000000&&ans[dis]>ans[scr]+wt)
            ans[dis]=ans[scr]+wt;
        }
    }
     for(int j=0;j<m;j++)
        {
           int scr=graph[j][0];
           int dis=graph[j][1];
           int wt=graph[j][2];
           if(ans[dis]>ans[scr]+wt)
            return 1;
        }
   for(int i=0;i<n;i++)
    {
        cout<<i<<"-"<<ans[i]<<endl;
    }
    return 0;
}
int main()
{
   int n;
   cout<<"enter number of vertices"<<endl;
   cin>>n;
   int m;
   cout<<"enter number of edges"<<endl;
   cin>>m;
   cout<<"enter connection edges"<<endl;
   int graph[m][3];
    for(int i=0;i<m;i++)
    {
    int x,y,w;
    cin>>x>>y>>w;
    graph[i][0] = x;
    graph[i][1] = y;
    graph[i][2] = w;
    }
    if(bellman(graph,n,m,0)==1)//sourse
    {
        cout<<"negative cycle present"<<endl;
    }
}