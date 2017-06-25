/*
Author:
Hossam Eissa
Idea: standard SCC problem
*/
#include <bits/stdc++.h>
#include <cstdio>
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
int dfs_num[N],dfs_low[N];
int dfscnt;
bool vis[N];
vector<int>st;
vector<int>v2[N];
int scccnt;
void scc(int u)
{
    dfs_num[u]=dfs_low[u]=dfscnt++;
    st.push_back(u);
    vis[u]=1;
    for(auto i: v2[u])
    {
        if(dfs_num[i]==-1)
            scc(i);
        if(vis[i])
            dfs_low[u]=min(dfs_low[u],dfs_low[i]);
    }
    if(dfs_low[u]==dfs_num[u])
    {
        scccnt++;
        while(1)
        {
            int v=st.back();
            st.pop_back();
            vis[v]=0;
            if(v==u)break;
        }
    }
}
int main()
{
  //  in;
    char s[55];
    while(scanf("%d %d",&n,&m)==2)
    {
        scccnt=0;
        dfscnt=0;
        st.clear();
        if(n==0&&m==0)break;
        map<string,int>mp;
        getchar();
        for(int i=0; i<n; i++)
        {
            gets(s);
            v2[i].clear();
            //cout<<s<<endl;
            mp[s]=i;
        }
        for(int j=0; j<m; j++)
        {
            gets(s);
            int a=mp[s];
            gets(s);
            int b=mp[s];
            v2[a].push_back(b);
           // cout<<a<<" "<<b<<endl;
        }
        memset(dfs_num,-1,sizeof dfs_num);
        memset(dfs_low,0,sizeof dfs_low);
        for(int i=0; i<n; i++)
        {
            if(dfs_num[i]==-1)
            {
                scc(i);
            }
        }
        printf("%d\n",scccnt);
    }
}
