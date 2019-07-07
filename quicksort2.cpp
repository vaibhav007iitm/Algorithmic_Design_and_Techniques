#include <bits/stdc++.h>
using namespace std;
long int m[2];
void Partition(unsigned int *Q,long int l,long int r){
  long int i,j=l,k=r;
  for(i=l+1;i<=k;i++){
    if(Q[l]>Q[i]) {j++;swap(Q[i],Q[j]);}
    else if(Q[l]<Q[i]) {swap(Q[i],Q[k]);k--;i--;}
  }
  swap(Q[l],Q[j]);
  m[0]=j;
  m[1]=k;
  return;
}
void Quicksort(unsigned int *P,long int l,long int r){
  if(l>r) return;
  long int m1,m2;
  Partition(P,l,r);
  m1=m[0];
  m2=m[1];
  //cout<<m1<<" "<<m2<<endl;
  Quicksort(P,l,m1-1);
  Quicksort(P,m2+1,r);
}
int main(){
  long int n,i;
  cin>>n;
  unsigned int A[n];
  for(i=0;i<n;i++) cin>>A[i];
  Quicksort(A,0,n-1);
  for(i=0;i<n;i++) cout<<A[i]<<" ";
}
