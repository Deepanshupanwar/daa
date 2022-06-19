#include<bits/stdc++.h>
using namespace std;
struct job{
int id,deadline,value;
};
bool cmp(struct job a,struct job b)
{
    return (a.value>b.value);
}
int main()
{
    int days=6;
job arr[8];
for(int i=0;i<8;i++)
{
    int t,d,v;
    cin>>t>>d>>v;
    arr[i].id=t;
    arr[i].deadline=d;
    arr[i].value=v;
}
sort(arr,arr+8,cmp);
int d[7];
memset(d,-1,sizeof(d));
int val=0;
for(int i=0;i<8;i++)
{
        for(int j=arr[i].deadline;j>0;j--)
        {
           if(d[j]==-1)
            {
               d[j]=arr[i].id;
                val+=arr[i].value;
                break;
            }
        }
}
cout<<val;
}