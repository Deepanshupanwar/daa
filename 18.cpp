#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
bool cycle(int start,vector<bool>& visited,vector<bool>& res)
{
    visited[start]=true;
    res[start]=true;
    for(int i=0;i<graph[start].size();i++)
    {
        if(graph[start][i]==1&&(!visited[i]))
        {
            if(cycle(i,visited,res))
             {
                return true;
             }
        }
        else if(graph[start][i]==1&&res[i])
           return true;
    }
    res[start]=false;
    return false;
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
    int x,y;
    cin>>x>>y;
    graph[x][y] = 1;
    }
    vector<bool> visited(n,false) ;
    for(int i=0;i<n;i++)
    {
     vector<bool> res(n,false) ;
     if(!visited[i])
     {
        if(cycle(i,visited,res))
        {
            cout<<"cycle detected"<<endl;
            return 0;
        }
     }
    }
    cout<<"no cycle detected";
    return 0;
}
