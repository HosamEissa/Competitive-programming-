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
#include<unordered_map>
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
#define ll  long long
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
const int N = 1e5+ 50;
const double EPS=1e-8;
const double INF=2e15+5;
const double PI=acos(-1);
ll n, m, k;
bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parllel || identical

    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;

    if (t1>1+EPS||t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;  //e.g ab is ray, cd is segment ... change to whatever
    return true;
}
int main()
{
    double t=2.0/3.0;
    // FO;
    sf(n);
    while(n--)
    {
        double x,y;
        scanf("%lf %lf",&x,&y);
        point a(x,y);
        scanf("%lf %lf",&x,&y);
        point b(x,y);
        scanf("%lf %lf",&x,&y);
        point c(x,y);
        point f(b+t*(a-b));
        point e(a+t*(c-a));
        point d(c+t*(b-c));
        point R,Q,P;
        intersectSegments(a,d,c,f,R);
        intersectSegments(b,e,c,f,Q);
        intersectSegments(b,e,a,d,P);
        double x1=length(vec(R,Q));
        double x2=length(vec(R,P));
        double x3=length(vec(P,Q));
        double mid=(x1+x2+x3)/2;
        double area=sqrt(mid*(mid-x1)*(mid-x2)*(mid-x3));
        printf("%lld\n",(ll)round(area));
    }

}
