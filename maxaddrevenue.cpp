#include<iostream>
using namespace std;
void sort(unsigned int *p,unsigned int n);
int main(){
  unsigned int n,P[1000],C[1000],amount,i;
  cin>>n;
  for(i=0;i<n;i++) cin>>P[i];
  for(i=0;i<n;i++) cin>>C[i];
  sort(P,n);
  sort(C,n);
  //debug
  //for(i=0;i<n;i++) cout<<P[i]<<" "<<C[i]<<"\n";
  amount=0;
  for(i=0;i<n;i++) amount=amount+(P[i]*C[i]);
  cout<<amount;
}
void sort(unsigned int *p,unsigned int n){
  int i,j,max=0,maxindex=0,temp;
  for(i=0;i<n;i++){
      max=0;
    for(j=i;j<n;j++){
      if(max<*(p+j)){
        max=*(p+j);
        maxindex=j;
      }
    }
    //cout<<*(p+maxindex)<<"%\n";
    temp=*(p+i);
    *(p+i)=max;
    *(p+maxindex)=temp;
  }
}
