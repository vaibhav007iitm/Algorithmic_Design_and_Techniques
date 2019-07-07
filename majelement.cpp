#include<iostream>
#include<chrono>
//#define TIM  high_resolution_clock
using namespace std;
using namespace std::chrono;
int main(){
	unsigned int n,i,j;
	cin>>n;
	unsigned int A[n];
	for(i=0;i<n;i++) cin>>A[i];
	auto start=high_resolution_clock::now();
	unsigned int count=1;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(count>(n/2)) {cout<<1;break;}
			if(A[i]==A[j]) count++;
		}
		if(count>(n/2)){cout<<1;break;}
	}
	if(count<=(n/2)){cout<<0;}
	auto stop=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stop-start);
	cout<<'\n'<<duration.count()<<endl;
}
