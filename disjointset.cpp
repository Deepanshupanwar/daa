#include <iostream>
using namespace std;
int find(int *set,int x)
{
    if(set[x]<0)
      return x;
    else
      return find(set,set[x]);
}
void Union(int *set,int u,int v)
{
int u1=find(set,u), v1=find(set,v);
if(set[u1]==-1&&set[v1]==-1||set[u1]<set[v1])
{
    set[v1]=u1;
    set[u1]=set[u1]-1;
}
else if(set[u1]>set[v1])
{
    set[u1]=v1;
    set[v1]=set[v1]-1;
}
}
int main()
{
    int n;
    cout<<"enter the number of vertices"<<endl;
    cin>>n;
    int set[n];
    for(int i=0;i<n;i++)
    {
        set[i]=-1;
    }
    Union(set,1,3);
    Union(set,1,4);
    Union(set,0,1);
    if(set[find(set,4)]==set[find(set,3)])
       cout<<"yes";
    else
        cout<<"no";
}