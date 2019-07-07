#include<bits/stdc++.h>
using namespace std;
int main(){
  long int i=1,n,count=0;
  cin>>n;
  long int a[n];
  while(n>0){
    a[i-1]=i;
    n-=i;
    count++;
    i++;
  }
  if(n<0) {count--;a[count-1]=a[count-1]-n;}
  cout<<count<<endl;
  for(i=0;i<count;i++) cout<<a[i]<<" ";
}
