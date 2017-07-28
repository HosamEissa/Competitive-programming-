/*
Author: Hossam Eissa
Idea:try this with all permutations of 3 numbers ((dist(s,f)+dist(t,f)-dist(s,t))/2+1)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const double PI=acos(-1);
int n,m,k;
vector<vector<int>>G;
int sparse[N][19],lvl[N],par[N];
void dfs(int u){
    for(auto v : G[u]){
        lvl[v]=lvl[u]+1;
        dfs(v);
    }
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
int solve(int s,int f,int t)
{
    int val=getdist(s,f);
    int val2=getdist(t,f);
    int val3=getdist(s,t);
   // cout<<s<<" "<<f<<" "<<t<<" "<<val<<" "<<val2<<" "<<val3<<endl;
    return ((val+val2)-val3)/2+1;
}
int main()
{
    cin>>n>>m;
    G.resize(n);
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        a--;
        par[i]=a;
        G[a].push_back(i);
    }
    dfs(0);
    buildSparse(n);

    while(m--)
    {
        vector<int>v(3);
        for(int i=0; i<3; i++)
            cin>>v[i],v[i]--;
        sort(v.begin(),v.end());
        int ans=0;
        do
        {
            ans=max(ans,solve(v[0],v[1],v[2]));
        }
        while(next_permutation(v.begin(),v.end()));
        cout<<ans<<endl;
    }
}
