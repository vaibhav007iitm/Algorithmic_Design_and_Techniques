#include<iostream>
using namespace std;
unsigned long fibonacci(unsigned long N);
int main(){
	unsigned long n,f;
	cin>>n;
	//cout<<sizeof(unsigned long long)<<endl;
	cout<<fibonacci(n)<<endl;
}
unsigned long fibonacci(unsigned long N){
	if(N<=1) return N;
	else return (fibonacci(N-1)+fibonacci(N-2));
}
