#include<bits/stdc++.h>
using namespace std;
void sortarr(long int *p,long int *q,int n){
  long int mini;
  int i,j,miniindex;
  for(i=0;i<n;i++){
    mini=p[i];
    miniindex=i;
    for(j=i;j<n;j++){
      if(mini>p[j]) {mini=p[j];miniindex=j;}

    }
    swap(p[i],p[miniindex]);
    swap(q[i],q[miniindex]);
  }
}
int main(){
int n,count=0,i,j,k=0;
cin>>n;
long int a[n],b[n],ans[n],bc;
for(i=0;i<n;i++) cin>>a[i]>>b[i];
sortarr(b,a,n);
//debug
//for(i=0;i<n;i++) cout<<b[i]<<" "<<a[i]<<endl;
for(i=0;i<n;i++){
  if(b[i]!=-1){
    count++;
    ans[k]=b[i];
    k++;
    bc=b[i];
    for(j=i;j<n;j++){
      if(bc>=a[j]){
        b[j]=-1;
      }
    }
  }
  }
  cout<<count<<endl;
  for(i=0;i<count;i++) cout<<ans[i]<<" ";
}
