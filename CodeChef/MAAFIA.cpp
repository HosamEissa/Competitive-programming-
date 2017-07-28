/*
Author: Hossam Eissa
Idea:binary search the maximum length and use dfs to check if nodes have intersection or not
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define start ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const double PI=acos(-1);
int n,m,k;
vector<ll>v;
vector<vector<int>>G;
bool drones[N];
int vis[N],id=0,ans;
void dfs(int u,int l,int par=-1){
    if(vis[u]==id)
    {
        ans=0;
        return;
    }
    vis[u]=id;
    if(l==0)return;
    for(auto v : G[u]){
        if(v==par)continue;
        dfs(v,l-1,u);
    }
}
bool ok(int mid){
    if(mid>n)return 0;
    ans=1;
    id++;
    for(int i=0;i<n;i++)
        if(drones[i])
            dfs(i,mid);
    return ans;
}
int main()
{
    cin>>n>>m>>k;
    G.resize(n);
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0; i<k; i++)
    {
        int a;
        cin>>a;
        drones[a-1]=1;
    }
    int l=0,r=n,ans=0;
    while(l<r){
        int m=(l+r)/2;
        if(ok(m)){
            l=m+1;
            ans=m;
        }
        else {
            r=m-1;
        }
    }
    while(ok(ans))ans++;
    ans--;
    ok(ans);
    int cnt=0;
    for(int i=0;i<n;i++)
        cnt+=(vis[i]==id);
    cout<<cnt<<endl;
}
