/*
Author: Hossam Eissa
Idea:group nodes by level and get pth parent using LCA and binary search how many nodes started after him and ended before him
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
vector<vector<int>>G;
vector<vector<pair<int,int>>>grp;
int sparse[N][19],lvl[N],par[N],in[N],out[N],ti=1;
void dfs(int u){
    in[u]=ti++;
    grp[lvl[u]].push_back({in[u],u});
    for(auto v : G[u]){
        lvl[v]=lvl[u]+1;
        dfs(v);
    }
    out[u]=ti++;
}
void buildSparse(int n){
    memset(sparse,-1,sizeof sparse);
    for(int i=1;i<n;i++)
        sparse[i][0]=par[i];
    for(int i=1;i<18;i++){
        for(int j=0;j<n;j++){
                int tmp=sparse[j][i-1];
                if(tmp!=-1)
                    sparse[j][i]=sparse[tmp][i-1];
        }
    }
}
int getPth(int v,int p){
    for(int i=0;v!=-1&&i<18;i++){
        if(p&(1<<i)){
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
    return abs(lvl[u]+lvl[v]-2*lvl[p]);
}
int solve(int v,int p){
    int u=getPth(v,p);
    if(u<=0)return 0;
   return lower_bound(grp[lvl[v]].begin(),grp[lvl[v]].end(),make_pair(out[u],0))-lower_bound(grp[lvl[v]].begin(),grp[lvl[v]].end(),make_pair(in[u],0))-1;
    return 0;
}
int main()
{
    start;
    cin>>n;
    n++;
    G.resize(n);
    grp.resize(n);
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        par[i]=a;
        G[a].push_back(i);
    }
    dfs(0);
    buildSparse(n);
    cin>>m;
    while(m--)
    {
        int v,p;
        cin>>v>>p;
        cout<<solve(v,p)<<endl;
    }
}
