#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned int n,i;
  cin>>n;
  unsigned int A[n];
  for(i=0;i<n;i++) cin>>A[i];
  unsigned int count=1,majindex=0;
  for(i=1;i<n;i++){
    if(A[majindex]==A[i]) count++;
    else count--;
    if(count==0){
      majindex=i;count=1;
    }
  }
  count=0;
  for(i=0;i<n;i++){
    if(A[majindex]==A[i])
      count++;
  }
  if(count>(n/2)) cout<<1;
  else cout<<0;
}
