#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
typedef pair<int ,int> ipair;
int mst(int n,vector<bool>& vis)
{
priority_queue<ipair,vector<ipair>,greater<ipair>>q;
q.push(make_pair(0,0));
int ans=0;
while(!q.empty())
{
     int u=q.top().second;
     int w=q.top().first;
     q.pop();
     if(vis[u])
     {
        continue;
     }
    ans=ans+w;
    vis[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v,wt;
         if(graph[u][i]>=1)
         {
          v=i;
          wt=graph[u][i];
         if(vis[v]==false)
         {
            q.push(make_pair(wt,v));
         }
         }
    }
}
return ans;
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
    vector<bool> vis(n,false);
    cout<<mst(n,vis)<<endl;
}
