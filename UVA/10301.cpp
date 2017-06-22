/*
Author: Hossam Eissa
Idea:connect two nodes if they are connected in disjoint set
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
const int N = 1e3+ 50;
const double EPS=1e-9;
const double INF=2e15+5;
const double PI=acos(-1);
ll n, m, k;
int arr[N],sz[N];
int dcmp(double a,double b)
{
    return fabs(a-b)<= EPS?0:a<b?-1:1;
}
bool solve(point c1,double r1,point c2,double r2)
{

    double dist=(c1.X-c2.X)*(c1.X-c2.X)+(c1.Y-c2.Y)*(c1.Y-c2.Y);
    if((r1-r2)*(r1-r2)<=dist&&
       dist<(r1+r2)*(r1+r2))
    {
        //cout<<"done2 "<<r1<<" "<<length(c2-c1)<<" "<<r1+r2<<" "<<length(c2-c1)<<endl;
        return 1;
    }

    // cout<<"done4"<<endl;
    return 0;
}
int f(int i){
    return i==arr[i]?i:f(arr[i]);
}
void connect(int a,int b){
    a=f(a);
    b=f(b);
    if(a==b)return;
    if(sz[a]<sz[b]){
        arr[a]=b,sz[b]+=sz[a];
    }
    else {
        arr[b]=a,sz[a]+=sz[b];
    }
}
int main()
{
    int t=0;
   // FO;
    while(scanf("%lld",&n)==1)
    {
        if(n==-1)break;
        memset(arr,0,sizeof arr);
        memset(sz,0,sizeof arr);
        for(int i=0;i<n;i++)arr[i]=i,sz[i]=1;

        vector<point>v;
        vector<double>vx;
        for(int i=0; i<n; i++)
        {
            double x,y,r;
                cin>>x>>y>>r;
            v.push_back(point(x,y));
            //    cout<<x<<" "<<y<<" "<<r<<endl;
            vx.push_back(r);
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)continue;
                if(solve(v[i],vx[i],v[j],vx[j])){
                    connect(i,j);
                }
            }
        }
        ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,sz[i]);
        }
        //cout<<ans<<endl;
        if(ans==1)                 printf("The largest component contains %d ring.\n",ans);

        else
                printf("The largest component contains %d rings.\n",ans);

    }

}
