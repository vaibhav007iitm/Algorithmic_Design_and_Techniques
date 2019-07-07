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
long double minDistance(pnt *Px,pnt *Py,long int l,long int r){
  if(r-l+1==3) return min({Distance(Px[l],Px[l+1]),Distance(Px[l],Px[l+2]),Distance(Px[l+1],Px[l+2])});
  else if(r-l+1<3) return Distance(Px[l],Px[r]);
  long int m=l+floor((r-l)/2),i,n=r-l+1,ly=0,ry=0;
  pnt midpoint=Px[m],Pyl[m+1-l],Pyr[r-m];
  for(i=0;i<n;i++){if(Py[i].y<=midpoint.x) Pyl[ly++]=Py[i]; else Pyr[ry++]=Py[i];}
  //debug
  //cout<<m<<"debug"<<endl;
  long double d1=minDistance(Px,Pyl,l,m);
  long double d2=minDistance(Px,Pyr,m+1,r);
  long double d=min(d1,d2);
  long int ln=ceil(m-d);
  long int rn=floor(m+d);
  if(ln<l) ln=l;
  if(rn>r) rn=r;
  long int nn=rn-ln+1;
  ln=ln-l;
  rn=rn-l;
  pnt Q[nn];
  long int j;
  for(i=0;i<nn;i++){Q[i]=Py[ln+i];}
  //MergeSort(Q,0,nn);
  long double dist=d;
  for(i=0;i<nn;i++)
    for(j=i+1;j<=(i+6) && j<nn;j++)
      dist=min(dist,Distance(Q[i],Q[j]));
  d=min(d,dist);
  return d;}
int main(){
  long int i,n;
  cin>>n;
  pnt Px[n],Py[n];
  for(i=0;i<n;i++){
    cin>>Px[i].x>>Px[i].y;
  }
  for(i=0;i<n;i++){
    Py[i].y=Px[i].x;Py[i].x=Px[i].y;
  }
  MergeSort(Px,0,n-1);
  MergeSort(Py,0,n-1);
  //for(i=0;i<n;i++){cout<<P[i].x<<" "<<P[i].y<<endl;}
  long double d=minDistance(Px,Py,0,n-1);
  cout<<fixed<<setprecision(6)<<d<<endl;

}
