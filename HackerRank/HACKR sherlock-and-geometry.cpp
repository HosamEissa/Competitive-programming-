/*
Author: Hossam Eissa
Idea: find if every line intersecet with the circle in point inside the segment
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
const double EPS=1e-10;
const double INF=2e15+5;
const double PI=acos(-1);
ll n, m, k;

int dcmp(double a,double b)
{
    return fabs(a-b)<= EPS?0:a<b?-1:1;
}
double fixAngle(double A)
{
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}
bool isCollinear(point a, point b, point c)
{
    return fabs( cp(b-a, c-a) ) < EPS;
}
// If line intersect cirlce at point p, and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
bool isPointOnRay(point p0, point p1, point p2) {
    if(length(p2-p0) < EPS) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}
bool isPointOnSegment(point a, point b, point c)
{
    return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}

vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dp(p1-p0, p1-p0), b = 2*dp(p1-p0, p0-C),
           c = dp(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;

    vector<point> v;
    if( dcmp(f, 0) >= 0) {
	    if( dcmp(f, 0) == 0)	f = 0;
	    double t1 =(-b + sqrt(f))/(2*a);
	    double t2 =(-b - sqrt(f))/(2*a);
	    v.push_back( p0 + t1*(p1-p0) );
	    if( dcmp(f, 0) != 0)	v.push_back( p0 + t2*(p1-p0) );
    }
    return v;
}
bool check(vector<point>v,point p1,point p2){
    for(int i=0;i<v.size();i++){
        if(isPointOnSegment(p1,p2,v[i]))
            return 1;
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
            bool ans=0;
        int x,y,r;
        cin>>x>>y>>r;
        point p(x,y);
        cin>>x>>y;
        point p1(x,y);
        cin>>x>>y;
        point p2(x,y);
        cin>>x>>y;
        point p3(x,y);
        vector<point>v=(intersectLineCircle(p1,p2,p,r));
        if(check(v,p1,p2))ans=1;
        v=(intersectLineCircle(p2,p3,p,r));
        if(check(v,p2,p3))ans=1;
        v=(intersectLineCircle(p3,p1,p,r));
        if(check(v,p3,p1))ans=1;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}


