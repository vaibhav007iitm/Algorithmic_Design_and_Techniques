#include<iostream>
using namespace std;
int main(){
	unsigned long n,m;
	cin>>n>>m;
	unsigned long F[n];
	F[0]=0;
	F[1]=1;
	for(int i=2;i<=n;i++){
		F[i]=F[i-2]+F[i-1];
}
cout<< F[n]%m;
}
