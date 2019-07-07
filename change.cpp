#include <iostream>
using namespace std;
int main(){
  unsigned short n,one,five,ten;
  cin>>n;
  ten=n/10;
  n=n%10;
  five=n/5;
  n=n%5;
  one=n;
  cout<<one+five+ten<<"\n";
}
