#include<iostream>
using namespace std;
struct MINMAX{
	long int m,M;
};
int main(){
	long int a,b;
	cin>>a>>b;
	struct MINMAX minmax;
	minmax={a,b};
	cout<<minmax.m<<endl;
}
