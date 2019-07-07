#include<bits/stdc++.h>
using namespace std;
int isBetter(string a,string b){
  unsigned int x,y;
  string a1,b1;
  a1=a;
  b1=b;
  a1.append(b);
  b1.append(a);
  x=stoi(a1);
  y=stoi(b1);
  //debug
  //cout<<x<<" "<<y<<endl;
  if(x>y) return 1;
  else return 0;

}
int main(){
  unsigned short int n,i,j,maxindex;
  cin>>n;
  string a[n],max;
  unsigned short int l[n];
  for(i=0;i<n;i++){cin>>a[i];}
  //for(i=0;i<n;i++)cout<<a[i];
  //cout<<a[i].at(1);
  //for(i=0;i<n;i++) l[i]=a[i].length();
  //cout<<isBetter("9","93")<<endl;
  for(i=0;i<n;i++){
    max=a[i];
    maxindex=i;
    for(j=i;j<n;j++){
      if(isBetter(a[j],max)==1) {/*cout<<isBetter(a[j],max)<<" "*/max=a[j];maxindex=j;}
    //  if(a[j].at(0)>max.at(0)){ max=a[j];maxindex=j;}
    //  else if(a[j].at(0)==max.at(0)){if(l[j]==1) max=a[j]; else if()}
    }
    swap(a[i],a[maxindex]);
  }
  for(i=0;i<n;i++)cout<<a[i];
}
