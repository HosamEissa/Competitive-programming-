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
const int N = 2e2+ 50;
const int MOD = 1e9+ 7;
const double EPS=1e-8;
const double INF=2e15+5;
ll n, m,k,d;
int mat[11][11];
int val[11][11];
bool ok(int i,int j){
    if(i>=1&&i<=n&&j>=1&&j<=m)return 1;
    return 0;
}
bool check(int i,int j,int k){
    for(int h=0;h<4;h++){
        int x=i+dx[h];
        int y=j+dy[h];
        if(ok(x,y)){
            if(mat[k][val[x][y]])return 0;
        }
    }
    return 1;
}
ll solve(int pos){
    if(pos==k+1){
        return 1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(val[i][j])continue;
            if(check(i,j,pos)){
               // cout<<pos<<" "<<i<<" "<<j<<endl;
                val[i][j]=pos;
                ans+=solve(pos+1);
                val[i][j]=0;
            }
        }
    }
    return ans;
}
int main()
{
    // FO;
    in;
    int t=1;
    cin>>t;
    while(t--){
            memset(mat,0,sizeof mat);
            memset(val,0,sizeof val);
        cin>>n>>m>>k;
        cin>>d;
        for(int i=0;i<d;i++){
            int a,b;
            cin>>a>>b;

            mat[a][b]=mat[b][a]=1;
        }
        ll ans=solve(1);
        if(ans>0&&ans<9e6)cout<<ans<<endl;
        else cout<<"impossible"<<endl;
    }
}
