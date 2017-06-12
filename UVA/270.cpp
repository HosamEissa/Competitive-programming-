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
int dcmp(double a,double b)
{
    return fabs(a-b)<= EPS?0:a<b?-1:1;
}
double fixAngle(double A)
{
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}

// return min angle: aOb / bOa
// dp(v1, v2) = |v1|*|v2|*cos(theta)
double angleO(point a, point O, point b)
{
    point v1(a - O), v2(b - O);
    return acos( fixAngle ( dp(v1, v2) / length(v1) / length(v2) ) );
}

double getAng(point &a, point &b, point &c) // find angle abc, anticlock bc to ba
{
    double ang = angle( vec(b, c)) - angle( vec(b, a));
    if(dcmp(ang, 0) < 0)
        ang+=2*PI;
    return ang;
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


bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parllel || identical

    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;

    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;  //e.g ab is ray, cd is segment ... change to whatever
    return true;
}


// Where is P2 relative to segment p0-p1?
// ccw = +1 => angle > 0 or collinear after p1
// cw = -1 => angle < 0 or collinear after p0
// Undefined = 0 => Collinar in range [a, b]. Be careful here
int ccw(point a, point b, point c)
{
    point v1(b - a), v2(c - a);
    double t = cp(v1, v2);

    if (t > +EPS)
        return +1;
    if (t < -EPS)
        return -1;
    if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
        return -1;
    if (norm(v1) < norm(v2) - EPS)
        return +1;
    return 0;
}
bool intersect(point p1, point p2, point p3, point p4)
{
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}
int main()
{
   // FO;
    int t;
    sf(t);
    getchar();
    getchar();
    while(t--){
        vector<point>vp;
        string s;
        while(getline(cin,s)){
            if(s.size()==0)break;
            stringstream ss;
            ss<<s;
            int a,b;
            ss>>a;
            ss>>b;
            vp.push_back(point(a,b));

        }
        if(vp.size()<=2)cout<<vp.size()<<endl;
        else {
        int ans=0;
        for(int i=0;i<vp.size();i++){
            for(int j=i+1;j<vp.size();j++)
                {
                    int sum=0;
                    for(int k=j+1;k<vp.size();k++){
               //             cout<<isPointOnRay(vp[i],vp[j],vp[k])<<endl;;
                        sum+=isCollinear(vp[i],vp[j],vp[k]);
                    }
                    ans=max(ans,sum);
                }
        }
        pf(ans+2);
        nl;
        }
        if(t)nl;
    }
}

