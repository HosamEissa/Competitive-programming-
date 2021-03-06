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
ll n, m, k,total=0,answer=0;
bool arr[N];
ll sub[N],sum[N],sum2[N];
vector<vector<pair<int,int> > >v2;
void dfs(int node,int par){
    for(auto i : v2[node]){
        int nn=i.first;
        ll cost=i.second;
        if(nn==par)continue;
        dfs(nn,node);
        sub[node]+=sub[nn];
        sum[node]+=sum[nn]+cost*sub[nn];
    }
    sub[node]+=arr[node];

}
void dfs2(int node,int par){
  for(auto i : v2[node]){
        int nn=i.first;
        ll cost=i.second;
        if(nn==par)continue;
        sum2[nn]=sum[nn]+sum2[node]-sum[nn]-cost*sub[nn]+cost*(total-sub[nn]);
        dfs2(nn,node);
    }
    if(!arr[node])answer+=sum2[node];
}
int main()
{
   // FO;
    cin>>n;
    v2.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        total+=arr[i];
    }
    for(int i=0;i<n-1;i++)
    {

        int a,b,c;
        cin>>a>>b>>c;
        v2[a].push_back({b,c});
        v2[b].push_back({a,c});
    }
    dfs(1,-1);
    sum2[1]=sum[1];
    dfs2(1,-1);

    cout<<answer<<endl;
}
