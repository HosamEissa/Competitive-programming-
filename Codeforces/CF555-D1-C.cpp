/*
Author: Hossam Eissa
Idea:make 2 segmenttrees 1 for lines in X and 1 for lines in Y
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const int TN = 1<<21;
const double PI=acos(-1);
int n,m,k;
int tree[TN][3],lazy[TN][3];
void add(int &x,int y){
    x=max(x,y);
}
void probagate(int l,int r,int p,int idx)
{
    if(lazy[p][idx]==0)
        return ;
    add(tree[p][idx],lazy[p][idx]);
    if(l!=r)
    {
        add(lazy[p<<1][idx],lazy[p][idx]);
        add(lazy[(p<<1)|1][idx],lazy[p][idx]);
    }
    lazy[p][idx]=0;
}
void update(int &val,int &ql,int &qr,int idx,int l,int r,int p)
{
    probagate(l,r,p,idx);
    if(qr<l||ql>r)
        return ;
    if(ql<=l&&r<=qr)
    {
        add(lazy[p][idx],val);
        probagate(l,r,p,idx);
     //      cout<<val<<" "<<ql<<" "<<qr<<" "<<idx<<" "<<l<<" "<<r<<" "<<p<<" "<<tree[p][idx]<<endl;
        return ;
    }
    int m=(l+r)>>1;
    update(val,ql,qr,idx,l,m,(p<<1));
    update(val,ql,qr,idx,m+1,r,(p<<1)|1);
    tree[p][idx]=max(tree[(p<<1)][idx],tree[(p<<1)|1][idx]);
}
int get(int &ql,int &qr,int idx,int l,int r,int p)
{
    probagate(l,r,p,idx);
    if(ql>r||qr<l)return 0;
    if(ql<=l&&r<=qr)
    {
        //cout<<ql<<" "<<qr<<" "<<idx<<" "<<l<<" "<<r<<" "<<p<<" "<<tree[p][idx]<<endl;
        return tree[p][idx];
    }
    int m=(l+r)>>1;
    return max(get(ql,qr,idx,l,m,(p<<1)),get(ql,qr,idx,m+1,r,(p<<1)|1));
}
void print(int idx,int l,int r,int p)
{
    probagate(l,r,p,idx);
    if(l==r)
    {
        printf("%d %d\n",l,tree[p][idx]);
        return ;
    }
    int m=(l+r)>>1;
    print(idx,l,m,(p<<1));
    print(idx,m+1,r,(p<<1)|1);
}
void Print(int idx,int l,int r,int p){
    printf("\n-------------------------idx = %d \n",idx);
    print(idx,l,r,p);
    printf("\n--------------------\n");
}
int arrX[TN];
vector<pair<pair<int,int>,int>>input;
int main()
{
    in;
    cin>>n>>m;
    map<int,int>xs;
    for(int i=0; i<m; i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        int c1;
        if(c=='U')c1=1;
        else c1=2;
        input.push_back({{a,b},c1});
        xs[a];
        xs[b];
    }
    int cnt=1;
    for(auto &i:xs)
    {
        arrX[cnt]=i.first;
        i.second=cnt++;
    }
    cnt--;
    for(auto i : xs)
    {
  //    cout<<i.first<<" "<<i.second<<endl;
    }
  //  cout<<endl;
    //Print(1,1,cnt,1);
    //  Print(2,1,cnt-1,1);
    for(int i=0; i<m; i++)
    {
        int x=input[i].first.first;
        int y=input[i].first.second;
        int c=input[i].second;
        int tmpx=xs[x];
        int tmpy=xs[y];
      //  cout<<x<<" "<<tmpx<<" "<<y<<" "<<tmpy<<endl;
        if(c==1)
        {
            int c=get(tmpx,tmpx,1,1,cnt,1);
        //    cout<<tmpx<<" "<<tmpy<<" "<<cnt<<" "<<c<<" "<<arrX[c]<<endl;
            update(tmpx,c,tmpy,2,1,cnt,1);
            update(tmpy,tmpx,tmpx,1,1,cnt,1);
            c=arrX[c];
            cout<<y-c<<endl;
           // Print(1,1,cnt,1);
           // Print(2,1,cnt,1);
        }
        else
        {
            int c=get(tmpy,tmpy,2,1,cnt,1);
        //    cout<<tmpx<<" "<<tmpy<<" "<<cnt<<" "<<c<<" "<<arrX[c]<<endl;
            update(tmpy,c,tmpx,1,1,cnt,1);
            update(tmpx,tmpy,tmpy,2,1,cnt,1);

            c=arrX[c];
            cout<<x-c<<endl;
           // Print(1,1,cnt,1);

        }
      //  break;
      //Print(1,1,cnt,1);
        //Print(2,1,cnt,1);
    }



}
