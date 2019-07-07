#include<iostream>
using namespace std;
unsigned long period(unsigned long m);
int main(){
	unsigned long n,m,pe;
	cin>>n>>m;
	//cout<<period(m);
	pe=n%period(m);
	unsigned long F[pe];
	F[0]=0;
	F[1]=1;
	for(int i=2;i<=pe;i++){
		F[i]=(F[i-1]+F[i-2])%m;
	}
	cout<<(F[pe]%m);
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
