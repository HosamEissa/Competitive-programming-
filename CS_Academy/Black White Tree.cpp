/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define start ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 1e5+5;
const double PI=acos(-1);
struct TreeCentroid
{

    const int INF = 2000000000;
    vector<set<int> >G;
    vector<vector<int> >sparse;
    int N,lgN,cnt,center;
    ll tot=0;
    vector<ll>lvl,par,sum,ans[2],kids[2],childstoparent[2];
    TreeCentroid(int n,int lgn)
    {
        N=n;
        lgN=lgn;
        G.resize(N);
    }
    void add_edge(int u,int v)
    {
     //   cout<<"u = "<<u<<" "<<v<<endl;
        G[u].insert(v);
        G[v].insert(u);
    }
    void dfsLCA(int u)
    {
        for(auto v : G[u])
        {
            if(v==sparse[0][u])continue;
            sparse[0][v]=u;
            lvl[v]=lvl[u]+1;
            dfsLCA(v);
        }
    }

    void buildSparse()
    {
        sparse.clear();
        lvl.clear();
        sparse.resize(lgN,vector<int>(N));

        lvl.resize(N);
        dfsLCA(0);
        for(int i=1; i<lgN; i++)
        {
            for(int j=0; j<N; j++)
            {
                int tmp=sparse[i-1][j];
                if(tmp!=-1)
                    sparse[i][j]=sparse[i-1][tmp];
            }
        }
    }
    int getPth(int v,int p)
    {
        for(int i=0; v!=-1&&i<lgN; i++)
        {
            if(p&(1<<i))
            {
                v=sparse[i][v];
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
        for(int i=lgN-1; i>=0; i--)
        {
            if(sparse[i][u]!=sparse[i][v])
            {
                u=sparse[i][u];
                v=sparse[i][v];
            }
        }
        return sparse[0][u];
    }
    int getdist(int u,int v)
    {
        int p=getLCA(u,v);
        return lvl[u]+lvl[v]-2*lvl[p];
    }
    void dfs1(int u,int p)
    {
        sum[u]=1;
        cnt++;
        for(auto v : G[u])
        {
            if(v!=p)
            {
                dfs1(v,u);
                sum[u]+=sum[v];
            }
        }
        //    cout<<"sum = "<<u<< " "<<sum[u]<<endl;
    }
    int dfs2(int u,int p)
    {

        //  cout<<u<<" 2 "<<p<<endl;
        for(auto v : G[u])
        {
            if(v!=p&&sum[v]>cnt/2)
                return dfs2(v,u);
        }
        return u;
    }
    void decompose(int root,int p)
    {
        cnt=0;
        dfs1(root,root);
        int cen=dfs2(root,root);
//        cout<<cen<<" "<<p<<endl;
        if(p==-1)
            p=cen,center=cen;
        par[cen]=p;
     //  cout<<cen<<" "<<par[cen]<<endl;
        for(auto v:G[cen])
        {
            G[v].erase(cen);
      //      cout<<"new "<<v<<" "<<cen<<endl;
            decompose(v,cen);
        }
    }
    void buildCenTree()
    {
        sum.resize(N);
        ans[0].resize(N,0);
        ans[1].resize(N,0);
        kids[0].resize(N,0);
        kids[1].resize(N,0);
        childstoparent[0].resize(N,0);
        childstoparent[1].resize(N,0);
        par.resize(N);
        buildSparse();
        decompose(0,-1);
    }
    void update(int u,int color)
    {
        int x=u;
        while(1)
        {
            kids[color][x]++;
            childstoparent[color][x]+=getdist(u,par[x]);
            ans[color][x]+=getdist(u,x);
            if(x==par[x])
                break;
            x=par[x];
        }
    }
    void update2(int u,int color)
    {
        int x=u;
        while(1)
        {
            kids[color][x]--;
            childstoparent[color][x]-=getdist(u,par[x]);
            ans[color][x]-=getdist(u,x);
            if(x==par[x])
                break;
            x=par[x];
        }
    }
    ll query(int u,int color)
    {
        int x=u;
        ll sum=ans[color][x];
     //   cout<<"nodes "<<u<< " "<<sum<<endl;
        while(1)
        {
            if(x==center)
                break;
          //  cout<<(kids[par[x]]-kids[x])*getdist(par[x],u)<<" "<<ans[par[x]]-ans[x]<<endl;
            sum+=(kids[color][par[x]]-kids[color][x])*getdist(par[x],u)+ans[color][par[x]]-childstoparent[color][x];
          //  cout<<u<<" "<<x<<" "<<kids[x]<<" "<<childstoparent[x]<<" "<<sum<<endl;
            if(x==par[x])
                break;
            x=par[x];
        }
        return sum;
    }
};
vector<int>in;
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    TreeCentroid TC(n,19);
    in.resize(n);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&in[i]);
    }
    for(int i=0; i<n-1; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        TC.add_edge(a,b);

    }
    TC.buildCenTree();
   // cout<<"done"<<endl;
    for(int i=0; i<n; i++)
    {
        TC.update(i,in[i]);
    }
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        b--;
        if(a==1)
        {
            TC.update2(b,in[b]);
            in[b]=!in[b];
            TC.update(b,in[b]);
        }
        else {
                printf("%lld\n",TC.query(b,in[b]));

        }
    }


 }
