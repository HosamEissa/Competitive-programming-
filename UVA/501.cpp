/*
Author: Hossam Eissa

Idea:use Segment tree to get k smallest number in the tree

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
const int N = 3e4+ 50;
const int MOD = 20071027;
const double EPS=1e-8;
const double INF=2e15+5;
int n, m,k,d;
vector<int>v,v2;
int tree[4*N];
void update(int idx,int l,int r,int p){
            if(idx==l&&r==l){
                tree[p]++;
                return;
            }
            if(l>idx)return;
            if(r<idx)return;
            int mid=(l+r)>>1;
            update(idx,l,mid,p<<1);
            update(idx,mid+1,r,(p<<1)+1);
            tree[p]=tree[p<<1]+tree[(p<<1)+1];
}
int get(int k,int l,int r,int p){
        if(l==r)return v[l];
        if(tree[p<<1]>=k){
            int mid=(l+r)>>1;
            return get(k,l,mid,p<<1);
        }
        else {
            int mid=(l+r)>>1;
            return get(k-tree[p<<1],mid+1,r,(p<<1)+1);
        }
}
int main()
{
    //FO;
    int t=1;
    sf(t);
    while(t--){
        sf2(n,m);
        memset(tree,0,sizeof tree);
        v.clear();
        v2.clear();
        v.resize(n);
        for(int i=0;i<n;i++)sf(v[i]);
        v2=v;
        sort(v.begin(),v.end());
        map<int,int>mp;
        for(int i=0;i<n;i++)
        if(!mp.count(v[i])){
            mp[v[i]]=i;
        }
        int idx=0;
        int sz=0;
        while(m--){
            int a;
            sf(a);
            while(sz<a){
                update(mp[v2[sz]],0,n-1,1);
                sz++;
            }
            idx++;
            if(idx==sz+1)idx=0;
           pf(get(idx,0,n-1,1));
           nl;
        }
    if(t)nl;
    }

}
