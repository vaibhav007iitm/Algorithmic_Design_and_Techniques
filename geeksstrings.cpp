#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;int l1,l2,f;
	cin>>s1>>s2;
	l1=s1.length();
	l2=s2.length();
	//Initialization examples
	string test(5,'i');
	cout<<test;
	string test(s1,0,2);
	cout<<test;
	string test(s1.at(0),s1.at(1));
	cout<<test;
	string test("Initialization");
	f=test.find('i');
	cout<<f;
}
