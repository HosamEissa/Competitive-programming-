/*
Author: Hossam Eissa

Idea:MST

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
const int N = 1e2+ 50;
const int MOD = 1e9+ 7;
const double EPS=1e-8;
const double INF=2e15+5;
int n, m,k,d;
int arr[N],sz[N];
int f(int a)
{
    return arr[a]=(a==arr[a]?a:f(arr[a]));
}
void connect(int a,int b)
{
    a=f(a);
    b=f(b);
    if(a==b)return;
    if(sz[a]<sz[b])
    {
        arr[a]=b;
        sz[b]+=sz[a];
    }
    else
    {
        arr[b]=a;
        sz[a]+=sz[b];
    }
}
void sss()
{
    for(int i=0; i<N; i++)arr[i]=i,sz[i]=1;
}
int main()
{
    int t=1;
    sf(t);
    while(t--)
    {
        sf2(n,m);
        vector<pair<int,pair<int,int> >  >v;
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            sf3(a,b,c);
            v.push_back({c,{a,b}});
        }
        sort(v.begin(),v.end());
        int ans1=0;
        vector<int>answer;
        sss();
        for(int i=0; i<m; i++)
        {
            int a=v[i].second.first;
            int b=v[i].second.second;
            a=f(a);
            b=f(b);
            if(a!=b)
            {
                connect(a,b);
                answer.push_back(i);
                ans1+=v[i].first;
            }
        }
        pf(ans1);
        int ans2=1e9;
        for(int i=0; i<answer.size(); i++)
        {
            int tmp=0;
            sss();
            int groups=n;
            for(int j=0; j<m; j++)
            {
                if(answer[i]==j)continue;
            int a=v[j].second.first;
            int b=v[j].second.second;
            a=f(a);
            b=f(b);
            if(a!=b)
            {
                connect(a,b);
                groups--;
                tmp+=v[j].first;
            }
            }
            //cout<<i<<" "<<tmp<<" "<<groups<<endl;
            if(groups==1)
            ans2=min(ans2,tmp);
        }
        printf(" %d\n",ans2);

    }
}
