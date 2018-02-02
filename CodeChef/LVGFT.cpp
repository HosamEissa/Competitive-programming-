/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int MOD=1e9+7;
void merge2(pair<int,int>&p,pair<int,int>p2)
{
    if(p2.first<p2.second)
        swap(p2.first,p2.second);
    if(p2.first>p.first)
        swap(p.second,p.first),swap(p.first,p2.first);
    if(p2.first>p.second&&p2.first!=p.first)
        swap(p.second,p2.first);
    if(p2.second>p.second&&p2.second!=p.first)
        swap(p2.second,p.second);

}
template<class T>
struct SegTree
{
    int N;
#define le p<<1
#define ri ((p<<1)|1)

    vector<T> tree, lazy,val;
    SegTree(int n)
    {
        N=n;
        tree.resize(4*N);
        lazy.resize(4*N);
        val.resize(n);
        build();
    }

    SegTree(vector<T>v)
    {
        N=v.size();
        tree.resize(4*N);
        lazy.resize(4*N);
        val=v;
        build();
    }
    T merge(pair<int,int> p,pair<int,int> p2)
    {
        if(p2.first<p2.second)
            swap(p2.first,p2.second);
        if(p2.first>p.first)
            swap(p.second,p.first),swap(p.first,p2.first);
        if(p2.first>p.second&&p2.first!=p.first)
            swap(p.second,p2.first);
        if(p2.second>p.second&&p2.second!=p.first)
            swap(p2.second,p.second);
        return p;

    }
    void probagate(int l, int r, int p)
    {
        if(lazy[p].first<0)return ;
        tree[p] =merge(tree[p],lazy[p]);
        if (l != r)
        {
            lazy[le] = merge(lazy[le],lazy[p]);
            lazy[ri] =  merge(lazy[ri],lazy[p]);
        }
        lazy[p] = {-2,-2};
    }
    void build(int l=0, int r=-1, int p=1)
    {
        if(r==-1)
            r=N-1;
        if (l == r)
        {
            tree[p]=lazy[p] = {-2,-2};
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, le);
        build(m + 1, r, ri);
        tree[p] = merge(tree[le], tree[ri]);
        lazy[p] = {-2,-2};
        return;
    }
    T get(int ql, int qr, int l=0, int r=-1, int p=1)
    {
        if(r==-1)
            r=N-1;
        probagate(l, r, p);
        if (ql > r || qr < l)
            return {-2,-2};
        if (ql <= l && r <= qr)
            return tree[p];
        int m = (l + r) >> 1;
        return merge(get(ql, qr, l, m,le),get(ql, qr, m + 1, r, ri));
    }
    void update(T val,int idx,int l=0,int r=-1,int p=1)
    {
        if(r==-1)
            r=N-1;
        if (idx > r || idx< l)
            return;
        if (idx==l&&idx==r)
        {
            tree[p]=merge(tree[p],val);
            return;
        }
        int m = (l + r) >> 1;
        update(val, idx, l, m,le);
        update(val, idx, m + 1, r, ri);
        tree[p] = merge(tree[le],tree[ri]);


    }
    void updateR(T val, int ql, int qr, int l=0, int r=-1, int p=1)
    {
        if(r==-1)
            r=N-1;
        probagate(l, r, p);
        if (ql > r || qr < l)
            return;
        if (ql <= l && r <= qr)
        {
            lazy[p] = val;
            probagate(l, r, p);
            return;
        }
        int m = (l + r) >> 1;
        updateR(val, ql, qr, l, m,le);
        updateR(val, ql, qr, m + 1, r, ri);
        tree[p] = merge(tree[le],tree[ri]);
    }
    void print(int l=0, int r=-1, int p=1)
    {
        if(r==-1)
            r=N-1;
        probagate(l,r,p);
        if (l == r)
        {
            cout<<l<<" "<<tree[p].first<<" "<<tree[p].second<<endl;
            return;
        }
        int m = (l + r) >> 1;
        print(l, m, le);
        print(m + 1, r, ri);
        tree[p] = merge(tree[le], tree[ri]);
        return;
    }
    void P()
    {
        cout<<endl<<endl;
        print();
        cout<<endl<<endl;
    }
};
vector<vector<int> >adj;
pair<int,int> mxin[N],mxout[N];
pair<int,int>cur;
int in[N],out[N],cnt=0;
void dfs(int u,int par)
{
    in[u]=cnt++;
    merge2(mxout[u],cur);
    merge2(cur, {u,-2});
    for(auto v:adj[u])
    {
        if(v!=par)
        {
            dfs(v,u);
            merge2(mxin[u],mxin[v]);
        }
    }
    merge2(mxin[u], {u,-2});
    out[u]=cnt-1;

}
int main()
{
    ios::sync_with_stdio();
    // cout<<p1.first<<" "<<p1.second<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        int n,q;
        cin>>n>>q;
        for(int i=0; i<=n; i++)
            mxin[i]=mxout[i]= {-2,-2};

        adj.clear();
        adj.resize(n);
        for(int i=1; i<n; i++)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // cout<<"done"<<endl;
        cur= {-2,-2};
        dfs(0,0);
        //   cout<<"777 "<<cur.first<<" "<<cur.second<<endl;
        for(int i=0; i<n; i++)
            reverse(adj[i].begin(),adj[i].end());
        cur= {-2,-2};
        cnt=0;
        dfs(0,0);
        SegTree<pair<int,int> > ST(n);
        // for(int i=0;i<n;i++)
        //     cout<<in[i]<<" "<<out[i]<<endl;
        //for(int i=0;i<n;i++)
        //     cout<<mxin[i].first<<" "<<mxin[i].second<<" "<<mxout[i].first<<" "<<mxout[i].second<<endl;
        vector<bool>v(n);
        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            b--;
            if(a==1)
            {
                if(v[b])continue;
                v[b]=1;
                if(in[b]>0)ST.updateR(mxin[b],0,in[b]-1);
                if(out[b]<n-1)ST.updateR(mxin[b],out[b]+1,n-1);
                ST.updateR({n-1,n-2},in[b],in[b]);
                for(auto v : adj[b]){
                    if(in[b]<in[v])
                        ST.updateR(mxout[v],in[v],out[v]);
                }
            }
            else
            {
                printf("%d\n",ST.get(in[b],in[b]).second+1);
            }
            //   ST.P();
        }
    }
}
