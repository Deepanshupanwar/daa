#include<iostream>
using namespace std;
int search(int *arr,int r,int f,int d)
{
 if(r<=f)
 {
   int mid=r+(f-r)/2;
   if(arr[mid]==d)
     return mid;
   if(arr[mid]>d)
     return search(arr,r,mid-1,d);
     
     return search(arr,mid+1,f,d);
 }
 return -1;
}
int main()
{
int n;
cout<<"enter the size"<<endl;
cin>>n;
int arr[n];
cout<<"enter sorted element"<<endl;
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
int k;
cout<<"enter the value"<<endl;
cin>>k;
for(int i=0;i<n;i++)
{
 int d=k-arr[i];
 int j=search(arr,i+1,n-1,d);
 if(j!=-1)
   cout<<"i = "<<i<<",j = "<<j<<endl;
}
return 0;
}
