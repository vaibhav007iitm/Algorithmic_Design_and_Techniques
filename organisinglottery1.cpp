#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned int *A=(unsigned int *) calloc(200000001,sizeof(unsigned int));
  long int a,b,j;
  unsigned int s,p,i;
  cin>>s>>p;
  for(i=1;i<=s;i++){
    cin>>a>>b;
    for(j=a;j<=b;j++) A[j+100000000]+=1;
  }
  unsigned int P[p];
  long int pnt;
  for(i=0;i<p;i++){
    cin>>pnt;
    P[i]=A[pnt+100000000];
  }
  for(i=0;i<p;i++) cout<<P[i]<<" ";

}
