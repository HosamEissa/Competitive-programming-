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
    vector<set<int>>G;
    vector<vector<int> >sparse,CenTree;
    int N,lgN,cnt,center;
    ll tot=0;
    vector<ll>lvl,par,sum,ans,kids,childstoparent;
    TreeCentroid(int n,int lgn)
    {
        N=n;
        lgN=lgn;
        G.resize(N);
        CenTree.resize(N);
    }
    void add_edge(int u,int v)
    {
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
       // cout<<cen<<" "<<p<<endl;
        if(p==-1)
            p=cen,center=cen;
        par[cen]=p;
//        cout<<cen<<" "<<par[cen]<<endl;
        for(auto v:G[cen])
        {
            G[v].erase(cen);
            decompose(v,cen);
            CenTree[cen].push_back(v);
        }
    }
    void buildCenTree()
    {
        sum.resize(N);
        ans.resize(N,0);
        kids.resize(N,0);
        childstoparent.resize(N,0);
        par.resize(N);
        buildSparse();
        decompose(0,-1);
    }
    void update(int u)
    {
        int x=u;
        while(1)
        {
            kids[x]++;
            childstoparent[x]+=getdist(u,par[x]);
            ans[x]+=getdist(u,x);
            if(x==par[x])
                break;
            x=par[x];
        }
        /*cout<<"node "<<u<<endl;
        for(int i=0; i<N; i++)
        {
            cout<<i<<" "<<kids[i]<<" "<<childstoparent[i]<<" "<<ans[i]<<endl;
        }*/
    }
    ll query(int u)
    {
        int x=u;
        ll sum=tot+ans[x];
     //   cout<<"nodes "<<u<< " "<<sum<<endl;
        while(1)
        {
            if(x==center)
                break;
          //  cout<<(kids[par[x]]-kids[x])*getdist(par[x],u)<<" "<<ans[par[x]]-ans[x]<<endl;
            sum+=(kids[par[x]]-kids[x])*getdist(par[x],u)+ans[par[x]]-childstoparent[x];
          //  cout<<u<<" "<<x<<" "<<kids[x]<<" "<<childstoparent[x]<<" "<<sum<<endl;
            if(x==par[x])
                break;
            x=par[x];
        }
        tot=sum;
        return sum;
    }
};
vector<int>v;
vector<int>l;
vector<int>r;
int idx=1;
vector<int>index2;
int getnew()
{
    return idx++;
}
int add(int val,int idx)
{
    if(v[idx]==-1)
    {
        //cout<<val<<" "<<idx<<endl;
        v[idx]=val;
        return idx;
    }
    else if(val>v[idx])
    {
        if(r[idx]==-1)
        {
            r[idx]=getnew();
        }
        return add(val,r[idx]);
    }
    else
    {
        if(l[idx]==-1)
        {
            l[idx]=getnew();
        }
        return  add(val,l[idx]);
    }
}
vector<pair<int,int> >vp;
void dfs0(int u)
{
    if(l[u]!=-1)
    {
        vp.push_back({u,l[u]});
        dfs0(l[u]);
    }
    if(r[u]!=-1)
    {
        vp.push_back({u,r[u]});
        dfs0(r[u]);
    }
}
vector<int>in;
int main()
{
    int n,q;
    scanf("%d",&n);
    v.resize(n,-1);
    l.resize(n,-1);
    r.resize(n,-1);
    in.resize(n);
    index2.resize(n+1);
    set<int>st;
    set<int>::iterator L,R;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        st.insert(a);
      //  if(i==0)
            index2[a]=in[i]=add(a,0);
      /*  else {
                L=st.lower_bound(a);
                R=st.upper_bound(a);
                int idx=-1;
                if(L!=st.begin()){
           //             cout<<"op1"<<endl;
                    L--;
                    if(r[index2[*L]]==-1)
                        idx=index2[*L];

                }
                if(R!=st.end()){
           //             cout<<"op2"<<endl;
                    if(l[index2[*R]]==-1)
                        idx=index2[*R];
                }
          //      cout<<a<<" "<<idx<<endl;
                index2[a]=in[i]=add(a,idx);
        }*/
    }
    dfs0(0);
    TreeCentroid TC(n,19);
    for(int i=0; i<vp.size(); i++)
    {
        TC.add_edge(vp[i].first,vp[i].second);
     //   cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }
   // cout<<endl;
    TC.buildCenTree();
    for(int i=0; i<n; i++)
    {
      //  cout<<v[in[i]]<<endl;
        printf("%lld\n",TC.query(in[i]));
        TC.update(in[i]);

    }

}
