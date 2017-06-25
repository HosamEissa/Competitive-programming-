/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
#include<stack>
#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include <map>
#include<unordered_map>
#include<complex>
using namespace std;
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
#define FI freopen("interesting.in", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define edge pair<ll, pair<int, int>>
#define CYA  exit(0);
/*int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1}; //8 direction*/
/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int N = 1e3 + 5;
const double EPS = 1e-10;
const ll INF = 1e18;
const double PI = acos(-1);
ll n, m, k;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a<b ? -1 : 1;
}
bool vis[N];
set<int>v2[N];
int dfs(int u){
        int ans=1;
        for(auto i:v2[u]){
            if(vis[i])continue;
            vis[i]=1;
            ans+=dfs(i);
        }
        return ans;
}
int main()
{
    while(scanf("%d %d",&n,&m)==2){
        if(n==0)break;
        memset(vis,0,sizeof vis);
        scanf("%d",&k);
        for(int i=1;i<=n;i++){
            v2[i].clear();
        }
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            v2[a].insert(b);
            v2[b].insert(a);
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                if(vis[j])continue;
                if(v2[j].size()<k){
                    vis[j]=1;
                    for(auto i:v2[j]){
                        v2[i].erase(j);
                    }
                    v2[j].clear();
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;


                ans=max(ans, dfs(i));
            }
        }
        printf("%d\n",ans);

    }
}
