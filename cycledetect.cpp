#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
int visited[10][10];
int find(int *set,int x)
{
    if(set[x]<0)
      return x;
    else
      return find(set,set[x]);
}
int Union(int *set,int u,int v)
{
int u1=find(set,u), v1=find(set,v);
if(u1==v1)
{
    return 1;
}
if(set[u1]==-1&&set[v1]==-1)
{
    set[v1]=u1;
}
}
void dfs(int start,int *set)
{
    for(int i=0;i<graph[start].size();i++)
    {
        if(graph[start][i]==1&&visited[start][i]==0)
        {
            if(Union(set,start,i)==1)
            {
                cout<<"cycle detected"<<endl;
                exit;
            }
            visited[start][i]=1;
             visited[i][start]=1;
            dfs(i,set);
        }
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
   int set[n];
    for(int i=0;i<n;i++)
    {
        set[i]=-1;
    }
   graph = vector<vector<int> >(n, vector<int>(n, 0));
   cout<<"enter connection edges"<<endl;
    for(int i=0;i<m;i++)
    {
    int x,y;
    cin>>x>>y;
    graph[x][y] = 1;
    graph[y][x] = 1;
    }
    memset(visited,0,sizeof(visited));
    dfs(0,set);

}