#include <bits/stdc++.h>
using namespace std;
void subset(string s,int l,int r)
{
if(l==r)
{
    cout<<s<<endl;
    return ;
}
for (int  i=l; i <=r; i++)
{
swap(s[i],s[l]);
subset(s,l+1,r);
swap(s[l],s[i]);
}

}
int main()
{
    string s="abc";
    subset(s,0,s.length()-1);
}