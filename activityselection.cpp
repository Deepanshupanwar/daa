#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
if(a.second==b.second)
  return a.first<b.first;
return a.second<b.second;
}
int main()
{
    int start[6]={1,3,0,5,8,5};
    int end[6]={2,4,6,7,9,9};
    vector<pair<int,int>> v(6);
    for(int i=0;i<=5;i++)
    {
        v[i]={start[i],end[i]};
    }
    sort(v.begin(),v.end(),cmp);
    int i=0;
    int j=1;
    int c=1;
    while(j<6)
    {
        if(v[i].second<v[j].first)
        {
            i=j;
            j++;
            c++;
        }
        else
        {
            j++;
        }
    }
    cout<<c;
}