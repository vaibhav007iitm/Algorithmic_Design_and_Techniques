#include<iostream>
using namespace std;
int main(){
unsigned long n;
cin>>n;
unsigned short F[n];
F[0]=0;
F[1]=1;
for(int i=2;i<=n;i++){
	F[i]=(F[i-1]+F[i-2])%10;
}
cout<<F[n];
}
