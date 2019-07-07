#include<iostream>
#include<cmath>
#include<chrono>
using namespace std;
using namespace std::chrono;
int BinarySearch(unsigned int q1,unsigned short *p,unsigned short int n){
  unsigned low=0,high=n,mid=floor(n/2);
  while(low<=high){
    mid=floor((high+low)/2);
    if(q1==p[mid])
      {return mid;}
    else if(q1<p[mid])
    {
      high=mid-1;
    }
    else
    {
      low=mid+1;
    }
  }
  return -1;
}
int main(){;
  unsigned short int n,m,i;
  cin>>n;
  unsigned short int A[n];
  for(i=0;i<n;i++)
    cin>>A[i];
  cin>>m;
auto start=high_resolution_clock::now();
  unsigned int Q[m];
  int ans[m];
  for(i=0;i<m;i++)
    cin>>Q[i];

  for(i=0;i<m;i++){
    ans[i]=BinarySearch(Q[i],A,n);
  }
  for(i=0;i<m;i++)
  cout<<ans[i]<<" ";
	auto stop=high_resolution_clock::now();
	auto duration=(stop-start);//duration_cast<seconds>(stop-start);
	cout<<duration.count()<<endl;
}
