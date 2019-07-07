#include<bits/stdc++.h>
using namespace std;
void Merge(unsigned int *P,long int l,long int m,long int r){
  //debug
  //cout<<m<<" ";
  unsigned int T[r-l+1];
  long int i=l,j=m+1,k=0;
  while(i<=m && j<=r){
    if(P[i]<=P[j]){T[k]=P[i];k++;i++;}
    else {T[k]=P[j];k++;j++;}
  }
  if(i>m){while(j<=r) {T[k]=P[j];k++;j++;}}
  else if(j>r) while(i<=m) {T[k]=P[i];k++;i++;}
  for(i=l;i<=r;i++) P[i]=T[i-l];
  return;

}
void MergeSort(unsigned int *P,long int l,long int r){
  if (l>=r) return;
  long int m;
    m=l+((r-l)/2);
    //cout<<m<<" ";
    MergeSort(P,l,m);
    MergeSort(P,m+1,r);
    Merge(P,l,m,r);
    return;
}
int main(){
  long int n,i;
  cin>>n;
  unsigned int A[n];
  for(i=0;i<n;i++) cin>>A[i];
  MergeSort(A,0,n-1);
  for(i=0;i<n;i++) cout<<A[i]<<" ";
  cout<<endl;
}
