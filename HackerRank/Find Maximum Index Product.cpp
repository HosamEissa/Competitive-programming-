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
    }

    SegTree(vector<T>v)
    {
        N=v.size();
        tree.resize(4*N);
        lazy.resize(4*N);
        val=v;
        build();
    }
    T merge(int p,int p2)
    {
        return max(p,p2);
    }
    void probagate(int l, int r, int p)
    {
        if(!lazy[p])return ;
        tree[p] += lazy[p];
        if (l != r)
        {
            lazy[le] += lazy[p];
            lazy[ri] += lazy[p];
        }
        lazy[p] = 0;
    }
    void build(int l=0, int r=-1, int p=1)
    {
        if(r==-1)
            r=N-1;
        if (l == r)
        {
            tree[p] = val[l];
            lazy[p] = 0;
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, le);
        build(m + 1, r, ri);
        tree[p] = merge(tree[le], tree[ri]);
        lazy[p] = 0;
        return;
    }
    ll get(int ql, int qr, int l=0, int r=-1, int p=1)
    {
        if(r==-1)
            r=N-1;
        probagate(l, r, p);
        if (ql > r || qr < l)
            return 0;
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
            tree[p]=val;
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
    ll get2(int ql, int qr,int val, int l=0, int r=-1, int p=1)
    {
        if(r==-1)
            r=N-1;
        probagate(l, r, p);
        if (ql > r || qr < l)
            return 1e9+1;
        int m = (l + r) >> 1;
       // cout<<ql<<" "<<qr<<" "<<val<<" "<<l<<" "<<r<<" "<<p<<" "<<tree[p]<<endl;
        if (ql <= l && r <= qr)
        {
            if(tree[p]<=val)
                return 1e9+1;
            if(l==r)
                return l;
            if(tree[le]>val)
                return get2(ql,qr,val,l,m,le);
            else
                return get2(ql,qr,val,m+1,r,ri);
        }
        return min(get2(ql, qr,val, l, m,le),get2(ql, qr,val, m + 1, r, ri));
    }
    ll get3(int ql, int qr,int val, int l=0, int r=-1, int p=1)
    {
        if(r==-1)
            r=N-1;
        probagate(l, r, p);
        if (ql > r || qr < l)
            return 0;
        int m = (l + r) >> 1;
        if (ql <= l && r <= qr)
        {
            if(tree[p]<=val)
                return 0;
            if(l==r)
                return l;
            if(tree[ri]>val)
                return get3(ql,qr,val,m+1,r,ri);
            else
                return get3(ql,qr,val,l,m,le);
        }
        return merge(get3(ql, qr,val, l, m,le),get3(ql, qr,val, m + 1, r, ri));
    }
};
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>v(n+2);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&v[i]);
    }
    v[0]=v[n+1]=1e9+2;
    SegTree<int> ST(v);
    ll c=0;
    for(int i=1; i<=n; i++)
    {
        int j=ST.get2(i,n+1,v[i]);
        int j2=ST.get3(0,i,v[i]);
        if(j>n)
            j=0;
        c=max(c,(ll)j*j2);
    }
    printf("%lld\n",c);
}
