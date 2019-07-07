#include <bits/stdc++.h>
using namespace std;
long int Partition(unsigned int *Q,long int l,long int r){
  long int i,j=l;
  for(i=l+1;i<=r;i++){
    if(Q[l]>Q[i]) {j++;swap(Q[i],Q[j]);}
  }
  swap(Q[l],Q[j]);
  return j;
}
void Quicksort(unsigned int *P,long int l,long int r){
  if(l>r) return;
  long int m;
  m=Partition(P,l,r);
//  cout<<m<<endl;
  Quicksort(P,l,m-1);
  Quicksort(P,m+1,r);
}
int main(){
  long int n,i;
  cin>>n;
  unsigned int A[n];
  for(i=0;i<n;i++) cin>>A[i];
  Quicksort(A,0,n-1);
  for(i=0;i<n;i++) cout<<A[i]<<" ";
}
