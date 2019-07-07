#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned int n;
  int i;
  cin>>n;
  unsigned int NoofOperations[n+1],NoofOperations1,NoofOperations2,NoofOperations3,m;
  NoofOperations[0]=0;
  NoofOperations[1]=0;
  NoofOperations[2]=1;
  NoofOperations[3]=1;
  for(m=4;m<=n;m++){
    //cout<<"executed"<<endl;
    if(m%3==0) NoofOperations1=NoofOperations[m/3]+1; else NoofOperations1=n+1;
    if(m%2==0) NoofOperations2=NoofOperations[m/2]+1; else NoofOperations2=n+1;
    NoofOperations3=NoofOperations[m-1]+1;
    NoofOperations[m]=min({NoofOperations1,NoofOperations2,NoofOperations3});
  }
  unsigned int ans=NoofOperations[n],Min;
  unsigned int seq[ans+1];
  seq[ans]=n;
  for(i=ans-1;i>=0;i--){
    m=seq[i+1];
//    cout<<m<<endl;
    if(m%3==0) NoofOperations1=NoofOperations[m/3]; else NoofOperations1=n=n+1;
    if(m%2==0) NoofOperations2=NoofOperations[m/2]; else NoofOperations2=n+1;
    if(NoofOperations1>NoofOperations2) {seq[i]=m/2;Min=NoofOperations2;} else {seq[i]=m/3;Min=NoofOperations1;}
    NoofOperations3=NoofOperations[m-1];
    if(Min>NoofOperations3) seq[i]=m-1;
  }
  cout<<ans<<endl;
  for(i=0;i<=ans;i++) cout<<seq[i]<<" ";
  cout<<endl;

}
