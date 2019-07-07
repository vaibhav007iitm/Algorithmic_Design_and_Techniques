#include<bits/stdc++.h>
using namespace std;
void Merge(long int P[][2],long int l,long int m,long int r){
  //debug
  //cout<<m<<" ";
  long int T[r-l+1][2];
  long int i=l,j=m+1,k=0;
  while(i<=m && j<=r){
    if(P[i][0]<P[j][0]){T[k][0]=P[i][0];T[k][1]=P[i][1];k++;i++;}
    else if(P[i][0]==P[j][0]){
      if(P[i][1]<=P[j][1]){T[k][0]=P[i][0];T[k][1]=P[i][1];k++;i++;}
      else {T[k][0]=P[j][0];T[k][1]=P[j][1];k++;j++;}
    }
    else {T[k][0]=P[j][0];T[k][1]=P[j][1];k++;j++;}
  }
  if(i>m){while(j<=r) {T[k][0]=P[j][0];T[k][1]=P[j][1];k++;j++;}}
  else if(j>r) while(i<=m) {T[k][0]=P[j][0];T[k][1]=P[j][1];k++;i++;}
  for(i=l;i<=r;i++) {P[i][0]=T[i-l][0];P[i][1]=T[i-l][1];}
  return;

}
void MergeSort(long int P[][2],long int l,long int r){
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
  long int s,p,i;
  cin>>s>>p;
  long int n=(2*s)+p;
  long int A[n][2];
  for(i=0;i<(2*s);i++){cin>>A[i][0];if((i%2)==0) A[i][1]=0;if((i%2)!=0) A[i][1]=2;}
  for(i=0;i<p;i++){cin>>A[(2*s)+i][0];A[(2*s)+i][1]=1;}
  MergeSort(A,0,n-1);
  unsigned int seg=0,P[p],j=0;
  for(i=0;i<n;i++){
    switch(A[i][1]){
      case 0:seg++;break;
      case 1:P[j]=seg;j++;break;
      case 2:seg--;break;}
  }
  for(i=0;i<p;i++) cout<<P[i]<<" ";
}
