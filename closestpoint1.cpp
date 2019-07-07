#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
struct Point {
  long int x;
  long int y;

};
typedef struct Point pnt;
long double Distance(pnt a,pnt b){
  return (long double)sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}
void Merge(pnt *P,long int l,long int m,long int r){
  pnt T[r-l+1];
  long int i=l,j=m+1,k=0;
  while(i<=m && j<=r){
    if(P[i].x<=P[j].x){T[k]=P[i];k++;i++;}
    else {T[k]=P[j];k++;j++;}
  }
  if(i>m){while(j<=r) {T[k]=P[j];k++;j++;}}
  else if(j>r) while(i<=m) {T[k]=P[i];k++;i++;}
  for(i=l;i<=r;i++) P[i]=T[i-l];
  return;

}
void MergeSort(pnt *P,long int l,long int r){
  if (l>=r) return;
  long int m;
    m=l+((r-l)/2);
    //cout<<m<<" ";
    MergeSort(P,l,m);
    MergeSort(P,m+1,r);
    Merge(P,l,m,r);
    return;
}
long double minDistance(pnt *P,long int l,long int r){
  if(r-l+1==3) return min({Distance(P[l],P[l+1]),Distance(P[l],P[l+2]),Distance(P[l+1],P[l+2])});
  else if(r-l+1<3) return Distance(P[l],P[r]);
  long int m=l+floor((r-l)/2);
  //debug
  //cout<<m<<"debug"<<endl;
  long double d1=minDistance(P,l,m);
  long double d2=minDistance(P,m+1,r);
  long double d=min(d1,d2);
  long int ln=ceil(m-d);
  long int rn=floor(m+d);
  if(ln<l) ln=l;
  if(rn>r) rn=r;
  long int nn=rn-ln+1;
  pnt Q[nn];
  long int i,j;
  for(i=0;i<nn;i++){Q[i].x=P[ln+i].y;Q[i].y=P[ln+i].x;}
  MergeSort(Q,0,nn);
  long double dist=d;
  for(i=0;i<nn;i++)
    for(j=i+1;j<=(i+6) && j<nn;j++)
      dist=min(dist,Distance(Q[i],Q[j]));
  d=min(d,dist);
  return d;
}
int main(){
  long int i,n;
  cin>>n;
  pnt P[n];
  for(i=0;i<n;i++){
    cin>>P[i].x>>P[i].y;
  }
  MergeSort(P,0,n-1);
  //for(i=0;i<n;i++){cout<<P[i].x<<" "<<P[i].y<<endl;}
  long double d=minDistance(P,0,n-1);
  cout<<fixed<<setprecision(6)<<d<<endl;

}
