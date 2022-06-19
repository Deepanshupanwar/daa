#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
bool bfs(int n,int start)
{
    int colorarr[n];
    memset(colorarr,-1,sizeof(colorarr));
vector<bool> visited(n,false) ;
list<int> queue;
visited[start]=true;
colorarr[start]=1;
queue.push_back(start);
while(!queue.empty())
{
    int s=queue.front();
    queue.pop_front();
    if(graph[s][s]==1)
       return false;
    for(int i=0;i<graph[s].size();i++)
    {
        if(graph[s][i]==1&&visited[i]==false&&colorarr[i]==-1)
        {
            visited[i]=true;
            colorarr[i]=1-colorarr[s];
            queue.push_back(i);
        }
        else if(graph[s][i]==1&&visited[i]==false&&colorarr[i]==colorarr[s])
        {
          return false;
        }
    }
}
return true;
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
    graph[y][x] = 1;
    }
    if(bfs(n,0))
    {
        cout<<"yes";
    }
    else
     cout<<"no";
   
}