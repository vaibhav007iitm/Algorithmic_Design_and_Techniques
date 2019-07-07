#include<bits/stdc++.h>
using namespace std;
struct minmax{
  long int min,max;
};
typedef struct minmax MINMAX;
int main(){
  string input;
  cin>>input;
  unsigned int n=input.length(),i,j,k,s;
  n=(n+1)/2;
  MINMAX m[n][n];
  unsigned int D[n];
  char OP[n-1];
  for(i=0;i<n;i++) D[i]=input[2*i]-48;
  for(i=0;i<n-1;i++) OP[i]=input[(2*i)+1];
  // for(i=0;i<n;i++) cout<<D[i];
  // for(i=0;i<n-1;i++) cout<<OP[i];
  MINMAX temp;
  for(i=0;i<n;i++) m[i][i]={D[i],D[i]};
  //cout<<m[n-1][n-1].min<<m[n-1][n-1].max<<endl;
  for(s=1;s<=n-1;s++)
    for(i=0;i<n-s;i++)
      {
        j=i+s;
        m[i][j]={4294967296,-4294967296};
        for(k=i;k<j;k++){
          switch(OP[k]){
            case '+':temp={m[i][k].min+m[k+1][j].min,m[i][k].max+m[k+1][j].max};break;
            case '-':temp={m[i][k].min-m[k+1][j].max,m[i][k].max-m[k+1][j].min};break;
            case '*':temp={min({m[i][k].min*m[k+1][j].min,m[i][k].min*m[k+1][j].max,m[i][k].max*m[k+1][j].min}),max(m[i][k].max*m[k+1][j].max,m[i][k].min*m[k+1][j].min)};break;
             // case '*':temp={min({m[i][k].min*m[i][k].min,m[i][k].min*m[i][k].max,m[i][k].max*m[i][k].min,m[i][k].max*m[i][k].max}),max({m[i][k].min*m[i][k].min,m[i][k].min*m[i][k].max,m[i][k].max*m[i][k].min,m[i][k].max*m[i][k].max})};break;
             // case '-':temp={min({m[i][k].min-m[i][k].min,m[i][k].min-m[i][k].max,m[i][k].max-m[i][k].min,m[i][k].max-m[i][k].max}),max({m[i][k].min-m[i][k].min,m[i][k].min-m[i][k].max,m[i][k].max-m[i][k].min,m[i][k].max-m[i][k].max})};break;
             // case '+':temp={min({m[i][k].min+m[i][k].min,m[i][k].min+m[i][k].max,m[i][k].max+m[i][k].min,m[i][k].max+m[i][k].max}),max({m[i][k].min+m[i][k].min,m[i][k].min+m[i][k].max,m[i][k].max+m[i][k].min,m[i][k].max+m[i][k].max})};break;
          }
          m[i][j]={min(temp.min,m[i][j].min),max(temp.max,m[i][j].max)};
        }
      }
  cout<<m[0][n-1].max<<endl;
}
