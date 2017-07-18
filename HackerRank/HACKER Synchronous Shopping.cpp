/*
Author: Hossam Eissa

Idea: put all the fishes in cities as a mask and do a dikstra from 1 to N then check 
if 2 solutions having all the K fishes and compare them to the answer

*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include <map>
#include<unordered_map>
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
#define ll long long
#define se second
#define fi first
#define mk(a, b) make_pair(a, b)
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvpi vector<vector<pii>>
#define pli pair<ll, int>
#define INF 2e9+5
#define MAX (int)1e6 + 5
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
const int N = 1e3 + 50;
ll n, m, k;
ll vis[N][N];
int Cities[N];
vector<vector<pair<int,int> > >v2;
void dikstra()
{
    priority_queue<pair<ll,pair<int,int> > ,vector<pair<ll,pair<int,int> > >,greater<pair<ll,pair<int,int> > > >pq;
    pq.push({0,{1,Cities[1]}});
    vis[1][Cities[1]]=0;
    while(!pq.empty())
    {
       // cout<<pq.size()<<endl;
        ll cost=pq.top().first;
        int mask=pq.top().second.second;
        int node=pq.top().second.first;
        pq.pop();
        for(int i=0;i<v2[node].size();i++){
            int nn=v2[node][i].first;
            ll ncost=v2[node][i].second+cost;
            int nmask=mask|Cities[nn];
            if(vis[nn][nmask]>ncost){
                vis[nn][nmask]=ncost;
                pq.push({ncost,{nn,nmask}});
            }
        }
    }

}
int main()
{
    in;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            vis[i][j]=INF;
    cin>>n>>m>>k;
    v2.resize(n+1);
    for(int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        while(t--)
        {
            int a;
            cin>>a;
            a--;
            Cities[i]|=(1<<a);
        }
    }
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v2[a].push_back({b,c});
        v2[b].push_back({a,c});
    }
   // cout<<"-----------------------"<<endl;
    dikstra();
    ll ans=INF;
   // cout<<(1<<k)-1<<endl;
    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<(1<<k);j++){
            if((i|j)==((1<<k)-1)){
                ll cost=max(vis[n][i],vis[n][j]);
                if(ans>cost){
             //           cout<<i<<" "<<j<<" "<<vis[n-1][i]<<" "<<vis[n-1][j]<<" "<<(i|j)<<endl;
                    ans=cost;
                }
            }
        }
  //      cout<<i<<" "<<vis[n][i]<<endl;
    }
    cout<<ans<<endl;

}
