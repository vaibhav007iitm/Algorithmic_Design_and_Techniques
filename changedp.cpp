#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned int money,coin[3]={1,3,4};
  cin>>money;
  unsigned int MinNoCoins[money+1],NoofCoins,m,j;
  MinNoCoins[0]=0;
  for(m=1;m<=money;m++){
    MinNoCoins[m]=m+1;
    for(j=0;j<3;j++){
      if(m>=coin[j]){
        NoofCoins=MinNoCoins[m-coin[j]]+1;
        if(NoofCoins<MinNoCoins[m]) MinNoCoins[m]=NoofCoins;
      }
    }
  }
  cout<<MinNoCoins[money];
}
