#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int> ipair;
vector< pair<int ,ipair>> edges;
int find(int *parent,int x)
{
    if(parent[x]<0)
      return x;
    return find(parent,parent[x]);
}
void Union(int *parent,int u,int v)
{
    int u1=find(parent,u), v1=find(parent,v);
if(parent[u1]==-1&&parent[v1]==-1||parent[u1]<parent[v1])
{
    parent[v1]=u1;
    parent[u1]=parent[u1]-1;
}
else if(parent[u1]>parent[v1])
{
    parent[u1]=v1;
    parent[v1]=parent[v1]-1;
}
}
int kruskal(int *parent)
{
    int msw=0;
    vector<pair<int,ipair>>::iterator i;
for(i=edges.end()-1;i!=edges.begin();i--)
{
  int u=i->second.first;
  int v=i->second.second;
  int u1=find(parent,u);
  int v1=find(parent,v);
  if(u1!=v1)
  {
  msw+=i->first;
  Union(parent,u1,v1);
  }
}
return msw;
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
    for(int i=0;i<m;i++)
    {
    int x,y,wt;
    cin>>x>>y>>wt;
    edges.push_back({wt,{x,y}});
    }
    sort(edges.begin(),edges.end());
     int parent[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=-1;
    }
    cout<<kruskal(parent)<<endl;
}