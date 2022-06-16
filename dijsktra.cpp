#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
typedef pair<int ,int> ipair;
void mst(int n,int s)
{
    int ans[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=1000000;
    }
priority_queue<ipair,vector<ipair>,greater<ipair>>q;
q.push(make_pair(0,s));
ans[s]=0;
while(!q.empty())
{
     int u=q.top().second;
     q.pop();
    for(int i=0;i<graph[u].size();i++)
    {
        int v,wt;
         if(graph[u][i]>=1)
        {
          v=i;
          wt=graph[u][i];
         if(ans[v]>ans[u]+wt)
         {
             ans[v]=ans[u]+wt;
            q.push(make_pair(ans[v],v));
         }
         }
    }
}
  for(int i=0;i<n;i++)
    {
        cout<<s<<"-"<<i<<"-"<<ans[i]<<endl;
    }
}
int main()
{
   int n;
   cout<<"enter number of vertices"<<endl;
   cin>>n;
   int m;
   cout<<"enter number of edges"<<endl;
   cin>>m;
   graph = vector<vector<int> >(n, vector<int>(n, 0));
   cout<<"enter connection edges"<<endl;
    for(int i=0;i<m;i++)
    {
    int x,y,w;
    cin>>x>>y>>w;
    graph[x][y] = w;
    graph[y][x] = w;
    }
    mst(n,3);
}