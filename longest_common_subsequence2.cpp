#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned short int n,m,l,i,j,k;
  cin>>n;
  long int A[n];
  for(i=0;i<n;i++) cin>>A[i];
  cin>>m;
  long int B[m];
  for(j=0;j<m;j++) cin>>B[j];
  cin>>l;
  long int C[l];
  for(k=0;k<m;k++) cin>>C[k];
  unsigned short int D[++n][++m][++l];
  for(j=0;j<m;j++)
    for(k=0;k<l;k++)
      for(i=0;i<n;i++){
        if(i==0 || j==0 || k==0) D[i][j][k]=0;
        else if(A[i-1]==B[j-1] && B[j-1]==C[k-1]) D[i][j][k]=D[i-1][j-1][k-1]+1;
          else D[i][j][k]=max(max(D[i][j][k-1],D[i][j-1][k]),D[i-1][j][k]);
      }
  cout<<D[n-1][m-1][l-1]<<endl;
}
