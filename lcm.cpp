#include<iostream>
using namespace std;
unsigned long gcd(unsigned long a,unsigned long b);
int main(){
unsigned long a,b;
cin>>a>>b;
if (a==0 || b==0) cout<<0;
else
cout<<(a*b/gcd(a,b));
}
unsigned long gcd(unsigned long a,unsigned long b){
	if(b==0) return(a);
	a=a%b;
	return gcd(b,a);
}
