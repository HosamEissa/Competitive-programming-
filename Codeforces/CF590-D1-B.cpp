/*
Author: Hossam Eissa
Idea: binary search get wind vector W and displacement vector D if sqrt((D-W)*(D-W))/mid<vmx return 1 else 0
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi=acos(-1);
int x1,x2,y1,y2,vmx,t,vx,vy,wx,wy;
bool ok(double mid){
    double t1,t2;
    if(mid>=t){
        t1=t,t2=mid-t;
    }
    else t1=mid,t2=0;
    double windx=vx*t1+wx*t2;
    double windy=vy*t1+wy*t2;
    double dx=x2-x1;
    double dy=y2-y1;
    double xx=dx-windx;
    double yy=dy-windy;
    double vec=sqrt(xx*xx+yy*yy);
    if(vec/mid<vmx){
        return 1;
    }
    return 0;


}
int main()
{
    cin>>x1>>y1>>x2>>y2;
    cin>>vmx>>t;
    cin>>vx>>vy>>wx>>wy;
    double l=0,r=4e9;
    for(int i=0;i<200;i++){
        double mid=(l+r)/2;
        if(ok(mid)){
            r=mid;
        }
        else l=mid;
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
}
