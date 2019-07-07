#include<iostream>
using namespace std;
unsigned long period(unsigned long m);
int main(){
	unsigned long m,n,p,q,rm,rn;
	cin>>m>>n;
	p=period(10);
	rm=m%p;
	rn=n%p;
	//r=(n-m)%p;
	q=(n-m+1)/p;
	unsigned long F[p],sumpi,sumr;
	F[0]=0;
	F[1]=1;
	int i;
	for(i=2;i<p;i++){
		F[i]=(F[i-1]+F[i-2])%10;
	}
	sumpi=0;
	sumr=0;
	for(i=0;i<p;i++){sumpi+=F[i];}
	if(rm<=rn){
	for(i=rm;i<=rn;i++) sumr+=F[i];}
	//cout<<((q*sumpi)+sumr)%10;}
	else
	{
		for(i=0;i<=rn;i++) sumr+=F[i];
		for(i=rm;i<p;i++) sumr+=F[i];
	}
	std::cout << ((sumpi*q)+sumr)%10 << '\n';
}
unsigned long period(unsigned long m){
	unsigned long m2=m*m,a=0,b=1,c;
	for(int i=3;i<=m2;i++){
		c=(a+b)%m;
		a=b;
		b=c;
		if(a==0 && b==1) return i-2;
}
}
