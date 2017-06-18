/*
Author: Hossam Eissa

Idea:

*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include <map>
#include<complex>
using namespace std;
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pf(a) printf("%d",a)
#define pf2(a,b) printf("%d %d",a,b)
#define pf3(a,b,c) printf("%d %d %d",a,b,c)
#define sfl(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pfl(a) printf("%lld",a)
#define pfl2(a,b) printf("%lld %lld",a,b)
#define pfl3(a,b,c) printf("%lld %lld %lld",a,b,c)
#define nl printf("\n")
#define ll  long long int
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define edge pair<ll, pair<int, int>>
#define CYA  exit(0);
#define pi acos(-1);
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
/*int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int N = 1e3+ 50;
const double EPS=1e-8;
const double INF=2e15+5;
ll n, m, k;
int dcmp(double a,double b)
{
    return fabs(a-b)<= EPS?0:a<b?-1:1;
}

bool isCollinear(point a, point b, point c)
{
    return fabs( cp(b-a, c-a) ) < EPS;
}

bool isPointOnRay(point a, point b, point c)  	// not tested?
{
    if(!isCollinear(a, b, c))
        return false;
    return dcmp(dp(b-a, c-a), 0) == 1;
}

bool isPointOnSegment(point a, point b, point c)
{
    return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}






double distToLine( point p0, point p1, point p2 )
{
    return fabs(cp(p1-p0, p2-p0)/length(p0-p1)); // area = 0.5*b*h
}




//distance from point p2 to segment p0-p1
double distToSegment( point p0, point p1, point p2 )
{
    double d1, d2;
    point v1 = p1-p0, v2 = p2-p0;
    if( (d1 = dp(v1, v2) ) <= 0)	return length(p2-p0);
    if( (d2 = dp(v1, v1) ) <= d1)	return length(p2-p1);
    double t = d1/d2;
    return length(p2 - (p0 + v1*t) );
}
ll arr[N],arr2[N];
ll gcd(ll a,ll b){
if(b==0)return a;
return gcd(b,a%b);
}
int main()
{
    while(cin>>n){
            if(n==-1)break;
            for(int i=0;i<n-1;i++){
                    cin>>arr[i]>>arr2[i];
            }
            ll a,b;
            a=b=1;
            for(int i=0;i<n-1;i++){
                a*=arr[i];
                b*=arr2[i];
                }
            ll g=gcd(a,b);
            cout<<a/g<<" "<<b/g<<endl;


    }


}
