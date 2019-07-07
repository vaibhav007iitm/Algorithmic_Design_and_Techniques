#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned int W,n,i,w,Value;
  cin>>W>>n;
  unsigned int value[W+1][n+1],weights[n];
  for(i=0;i<n;i++) cin>>weights[i];
  for(i=0;i<=n;i++)
    for(w=0;w<=W;w++){
      if(i==0 || w==0) value[w][i]=0;
      else {
        value[w][i]=value[w][i-1];
        if(weights[i-1]<=w){
          Value=value[w-weights[i-1]][i-1]+weights[i-1];
          if(Value>value[w][i]) value[w][i]=Value;
        }
      }
    }
  cout<<value[W][n]<<endl;


}
