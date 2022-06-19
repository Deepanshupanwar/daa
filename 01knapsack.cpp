#include<bits/stdc++.h>
using namespace std;
int main()
{
    int W=10;
    int n=4;
    int v[]={10,40,30,50};
    int w[]={5,4,6,3};
    int mat[n+1][W+1];
    for(int i=0;i<W+1;i++)
    {
        mat[0][i]=0;
    }
     for(int i=0;i<n+1;i++)
    {
        mat[i][0]=0;
    }
    for(int item=1;item<=n;item++)
    {
        for(int capacity=1;capacity<=W;capacity++)
        {
            int maxvalwithoutcurr =mat[item-1][capacity];
            int maxwithcurr=0;
            int weightofcurr=w[item-1];
            if(capacity>=weightofcurr)
            {
                maxwithcurr=v[item-1];
                int remaingcapcity=capacity-weightofcurr;
                maxwithcurr +=mat[item-1][remaingcapcity];
            }
            if(maxwithcurr>=maxvalwithoutcurr)
               mat[item][capacity]=maxwithcurr;
            else
               mat[item][capacity]=maxvalwithoutcurr;
        }
    }
cout<<mat[n][W];
}