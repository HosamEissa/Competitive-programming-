/*
Author: Hossam Eissa
Idea:store numbers as binary in segment tree
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
int tree[21][TN];
bool lazy[21][TN]={0};
void probagate(int l,int r,int p,int idx)
{
    if(lazy[idx][p]==0)return ;
    tree[idx][p]=(r-l+1)-tree[idx][p];
   // printf("a7aaa l=%d r=%d p=%d idx=%d  val=%d\n",l,r,p,idx,tree[idx][p]);
    if(l!=r)
    {
        lazy[idx][p<<1]^=1;
        lazy[idx][(p<<1)|1]^=1;
    }
    lazy[idx][p]=0;
}
void update(bool val,int ql,int qr,int idx,int l=0,int r=n-1,int p=1)
{
    probagate(l,r,p,idx);
    if(ql>r||qr<l)return;
    if(ql<=l&&r<=qr)
    {
        lazy[idx][p]^=val;
        probagate(l,r,p,idx);
        return ;
    }
    int m=(l+r)>>1;
    update(val,ql,qr,idx,l,m,(p<<1));
    update(val,ql,qr,idx,m+1,r,(p<<1)|1);
    tree[idx][p]=tree[idx][(p<<1)]+tree[idx][(p<<1)|1];
}
int get(int ql,int qr,int idx,int l=0,int r=n-1,int p=1)
{
    probagate(l,r,p,idx);
    if(ql>r||qr<l)return 0;
    if(ql<=l&&r<=qr)
    {
        return tree[idx][p];
    }
    int m=(l+r)>>1;
    return get(ql,qr,idx,l,m,(p<<1))+get(ql,qr,idx,m+1,r,(p<<1)|1);
}
void print(int idx,int l=0,int r=n-1,int p=1){
    probagate(l,r,p,idx);
    if(l==r)
    {
        printf("idx=%d l=%d p=%d tree=%d\n",idx,l,p,tree[idx][p]);
        return ;
    }
    int m=(l+r)>>1;
    print(idx,l,m,(p<<1));
    print(idx,m+1,r,(p<<1)|1);
}
void Print(){
    for(int j=0;j<=20;j++){
    printf("\n----------------------------------------- idx = %d\n",j);
        print(j);
     printf("\n-----------------------------------------\n");
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
       // scanf("%d",&a);
        a=1000000;
        for(int j=0;j<=20;j++){
            if(a&(1LL<<j)){
                update(1,i,i,j);
            }
        }
    }

    //Print();

    scanf("%d",&m);
    while(m--){
            int a,b,c,d;
        scanf("%d%d%d",&c,&a,&b);
        a--;
        b--;
        if(c==1){
                ll ans=0;
                for(int i=0;i<=20;i++){
                        printf("idx = %d cnt = %d\n",i,get(a,b,i));
                    ans+=(1LL<<i)*(ll)get(a,b,i);
                }
                printf("ans = %lld\n",ans);
        }
        else {
            scanf("%d",&d);
                for(int i=0;i<=20;i++){
                    if(d&(1<<i)){
                        update(1,a,b,i);
              //       Print(i);
                    }
                }

        }
    }

}
