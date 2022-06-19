#include<bits/stdc++.h>
using namespace std;
struct items
{
    int value ,weight;
};
bool cmp(struct items a,struct items b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
int main()
{
    int W=50;
    int n=3;
    items arr[n];
    for(int i=0;i<n;i++)
    { 
        int v,wt;
        cin>>v>>wt;
        arr[i].value=v;
        arr[i].weight=wt;

    }
    sort(arr,arr+n,cmp);
    double fvalue=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=W)
        {
            fvalue +=arr[i].value;
            W -=arr[i].weight;
        }
        else
        {
            fvalue +=arr[i].value*((double)W/arr[i].weight);
            break;
        }
    }
    cout<<fvalue;
}
