/*
Author: Hossam Eissa
Idea:follow the ray till you get the distance and find the point the ray outs from then get the displacement
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi=acos(-1);
int n,d;
int main()
{
    int t;
    scanf("%d",&t);
        cout<<fixed<<setprecision(3);
    while(t--){
        double l,w,theta;
        cin>>l>>w>>theta;
        theta*=pi/180.0;
        double tmpl=l;
        double a=w/tan(theta);
        double b=w/sin(theta);
        int cnt=0;
        double dist=0;
        while(l>=a){
            cnt++;
            dist+=b;
            l-=a;
        }
        double cc=0;
        double w1=l*tan(theta);
        cc=sqrt(l*l+w1*w1);
        dist+=cc;
        if(cnt%2){
            w1=w-w1;
        }
        cout<<dist/sqrt((tmpl*tmpl)+(w1*w1))<<endl;
    }
}
