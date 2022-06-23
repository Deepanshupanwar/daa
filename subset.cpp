#include <bits/stdc++.h>
using namespace std;
void subset(string s,int i,string curr)
{
if(i==s.length())
{
    cout<<curr<<endl;
    return ;
}
subset(s,i+1,curr+s[i]);
subset(s,i+1,curr);
}
int main()
{
    string s="abc";
    string curr;
    subset(s,0,curr);
}
