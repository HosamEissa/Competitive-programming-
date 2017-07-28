/*
Author: Hossam Eissa
Idea:do a prefix sum from root and then get distance between two nodes by going from 1 to LCA and the other to LCA
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
vector<vector<pair<int,int>>>G;
int sparse[N][19],lvl[N],par[N], sum[N];
void dfs(int u)
{
    for(auto i : G[u])
    {
        if(i.first!=par[u])
        {
            par[i.first]=u;
            lvl[i.first]=lvl[u]+1;
            sum[i.first]=sum[u]+i.second;
            dfs(i.first);
        }
    }
}
void buildSparse(int n)
{
    memset(sparse,-1,sizeof sparse);
    for(int i=1; i<n; i++)
        sparse[i][0]=par[i];
    for(int i=1; i<18; i++)
    {
        for(int j=0; j<n; j++)
        {
            int tmp=sparse[j][i-1];
            if(tmp!=-1)
                sparse[j][i]=sparse[tmp][i-1];
        }
    }
}
int getPth(int v,int p)
{
    for(int i=0; v!=-1&&i<18; i++)
    {
        if(p&(1<<i))
        {
            v=sparse[v][i];
        }
    }
    return v;
}
int getLCA(int u,int v)
{
    if(lvl[u]>lvl[v])
        swap(u,v);
    int p=lvl[v]-lvl[u];
    v=getPth(v,p);
    if(v==u)return u;
    for(int i=17; i>=0; i--)
    {
        if(sparse[u][i]!=sparse[v][i])
        {
            u=sparse[u][i];
            v=sparse[v][i];
        }
    }
    return sparse[u][0];
}
int getdist(int u,int v)
{
    int p=getLCA(u,v);
    return abs(sum[u]+sum[v]-2*sum[p]);
}
int main()
{
    start;
    cin>>n;
    G.resize(n);
    memset(par,-1,sizeof par);
    for(int i=1; i<n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    dfs(0);
    buildSparse(n);
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        cout<<getdist(u,v)<<endl;
    }
}
