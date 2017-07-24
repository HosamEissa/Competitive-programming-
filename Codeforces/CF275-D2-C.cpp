/*
Author: Hossam Eissa
Idea:sort all points in terms for angles with X axis and then calculate between the every two points have n-2 points in middel
*/
#include <bits/stdc++.h>
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
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int INF = 2000000000;
const double PI=acos(-1);
int n,d;
const int N=1e5+5;
const double EPS=1e-9;
int dcmp(double a,double b)
{
    return fabs(a-b)<= EPS?0:a<b?-1:1;
}
double fixAngle(double A)
{
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}
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
bool cmp(point p1,point p2){
    return angle(p2)-angle(p1)>EPS;
}
int main()
{
    // freopen("walk.in","r",stdin);
    in;
    int n;
    cin>>n;
    vector<point>v;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(point(x,y));
    }
    sort(v.begin(),v.end(),cmp);
    double ans=0;
    for(int i=0;i<n;i++){
            point p1=v[i];
            point p2=point(0,0);
            point p3=v[(i+n-1)%n];
       // ans+=getAng(p1,p2,p3)*180/PI;
       ans=max(ans,getAng(p3,p2,p1)*180/PI);
    }
    ans=360-ans;
    if(dcmp(ans,360)>=0)ans-=360;
    cout<<fixed<<setprecision(9)<<ans<<endl;
}
