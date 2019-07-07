#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a;
  cin>>b;
  unsigned int len_a=a.length(),len_b=b.length();
  unsigned int D[++len_a][++len_b];
  unsigned int i,j,insertion,deletion,mismatch,match,m=len_a,n=len_b;
  for(i=0;i<m;i++) D[i][0]=i;
  for(j=0;j<n;j++) D[0][j]=j;
  for(j=1;j<n;j++)
    for(i=1;i<m;i++){
      insertion=D[i][j-1]+1;
      deletion=D[i-1][j]+1;
      mismatch=D[i-1][j-1]+1;
      match=D[i-1][j-1];
      if(a[i-1]==b[j-1]) D[i][j]=min({insertion,deletion,match});
      else D[i][j]=min({insertion,deletion,mismatch});
    }
  cout<<D[m-1][n-1]<<endl;
}
