#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned int n,m,i,j;
  cin>>n;
  long int A[n];
  for(i=0;i<n;i++) cin>>A[i];
  cin>>m;
  long int B[m];
  for(i=0;i<m;i++) cin>>B[i];
  // for(i=0;i<n;i++) cout<<A[i]<<" ";
  // cout<<endl;
  // for(j=0;j<m;j++) cout<<B[j]<<" ";
  // cout<<endl;
  unsigned int D[++n][++m];
  unsigned int insertion,deletion,mismatch,match;
  for(i=0;i<n;i++) D[i][0]=0;
  for(j=0;j<m;j++) D[0][j]=0;
  for(j=1;j<m;j++)
    for(i=1;i<n;i++){
      insertion=D[i][j-1];
      deletion=D[i-1][j];
      mismatch=D[i-1][j-1];
      match=D[i-1][j-1]+1;
      if(A[i-1]==B[j-1]) D[i][j]=match;
      else D[i][j]=max({insertion,deletion});
    }
  cout<<D[n-1][m-1]<<endl;
  // for(i=0;i<n;i++)
  //   {
  //     for(j=0;j<m;j++) cout<<D[i][j]<<" ";
  //     cout<<endl;
  //   }

}
