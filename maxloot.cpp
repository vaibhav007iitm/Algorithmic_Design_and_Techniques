#include<iostream>
#include<iomanip>
using namespace std;
int main(){
  unsigned int n,W;
  cin>>n>>W;
  unsigned int w[n],p[n],i,j,max,maxindex,temp;
  float pu[n],amount,temp2;

  for(i=0;i<n;i++){
    cin>>p[i]>>w[i];
    pu[i]=p[i]/float(w[i]);
  }
  max=0;maxindex=0;
  for(i=0;i<n;i++){
      max=0;
      for(j=i;j<n;j++){
        if(max<pu[j])  max=pu[j]; maxindex=j;
      }
      temp2=pu[i];
      pu[i]=pu[maxindex];
      pu[maxindex]=temp2;
      temp=p[i];
      p[i]=p[maxindex];
      p[maxindex]=temp;
      temp=w[i];
      w[i]=w[maxindex];
      w[maxindex]=temp;
  }
  //debug
  for(i=0;i<n;i++) cout<<p[i]<<" "<<w[i]<<" "<<pu[i]<<"\n";
  amount=0;
  for(i=0;i<n;i++){
    if(W==0) break;
    amount=amount+(pu[i]*min(w[i],W));
    W=W-min(w[i],W);
  }
  cout<<fixed<<setprecision(4)<<amount;
}
