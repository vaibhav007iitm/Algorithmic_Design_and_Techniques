#include<bits/stdc++.h>
using namespace std;
unsigned int *p;
unsigned int majele(unsigned int s,unsigned int e){
  if(s==e) return p[s];
  unsigned int mid;
  mid=((e-s)/2)+s;
  unsigned int l,r;
  l=majele(s,mid);
  r=majele(mid+1,e);
  if(l==r) return l;
  unsigned int count_l=0,count_r=0,len,i;
  len=e-s+1;
  for(i=0;i<len;i++) if(p[i]==l) count_l++;
  if(count_l>(len/2)) return l;
  for(i=0;i<len;i++) if(p[i]==r) count_r++;
  if(count_r>(len/2)) return r;
  return 0;
}
int main(){
  unsigned int n,i;
  bool ans;
  cin>>n;
  unsigned int A[n];
  for(i=0;i<n;i++) cin>>A[i];
  p=A;
  ans=(bool)majele(0,n-1);
  cout<<ans<<endl;


}
