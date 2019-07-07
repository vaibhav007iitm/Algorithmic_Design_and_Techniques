#include<iostream>
using namespace std;
int main(){
	unsigned long n,m;
	cin>>n>>m;
	unsigned long a,b,c;
	a=0;
	b=1%m;
	for(int i=2;i<=n;i++){
		c=(a+b)%m;
		a=b;
		b=c;
}
cout<< c;
}
