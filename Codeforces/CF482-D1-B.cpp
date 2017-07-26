/*
Author: Hossam Eissa
Idea:or all the querrys and the check them
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const int TN = 1<<18;
const double PI=acos(-1);
int n,m,k;
ll tree[TN],lazy[TN]= {0};
void probagate(int l,int r,int p)
{
    tree[p]|=lazy[p];
    if(l!=r)
    {
        lazy[p<<1]|=lazy[p];
        lazy[(p<<1)|1]|=lazy[p];
    }
    lazy[p]=0;
}
void update(int val,int ql,int qr,int l=0,int r=n-1,int p=1)
{
    probagate(l,r,p);
    if(ql>r||qr<l)return;
    if(ql<=l&&r<=qr)
    {
        lazy[p]|=val;
        probagate(l,r,p);
        return ;
    }
    int m=(l+r)>>1;
    update(val,ql,qr,l,m,(p<<1));
    update(val,ql,qr,m+1,r,(p<<1)|1);
        tree[p]=tree[(p<<1)]&tree[(p<<1)|1];
}
int get(int ql,int qr,int l=0,int r=n-1,int p=1)
{
   // cout<<ql<<" "<<qr<<" "<<l<<" "<<r<<" "<<p<<endl;
    probagate(l,r,p);
    if(ql>r||qr<l)return ~(0);
    if(ql<=l&&r<=qr)
    {
        return tree[p];
    }
    int m=(l+r)>>1;
    return get(ql,qr,l,m,(p<<1))&get(ql,qr,m+1,r,(p<<1)|1);
}
void print(int l=0,int r=n-1,int p=1)
{
    probagate(l,r,p);
    if(l==r)
    {
        printf("%d ",tree[p]);
        return ;
    }
    int m=(l+r)>>1;
    print(l,m,(p<<1));
    print(m+1,r,(p<<1)|1);
}
int main()
{
    scanf("%d%d",&n,&m);
     vector<pair<pair<int,int>,int>>v;
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--;
        b--;
        v.push_back({{a,b},c});
        update(c,a,b);
    }
    //cout<< get(0,0)<<endl;
    //Print();

    for(int i=0; i<m; i++)
    {
        int a=v[i].first.first;
        int b=v[i].first.second;
        int c=v[i].second;
        if(get(a,b)!=c)
        {
            return puts("NO");
        }
    }
    puts("YES");
    print();

}
