/*
Author: Hossam Eissa
Idea:mark for every index the time it appered at and use those value to make root =1
*/
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
int n,k;
int tree[(1<<17)];
void update(int idx,int val,int l,int r,int p)
{
    if(idx<l||idx>r)return;
    if(l==r&&r==idx)
    {
        tree[p]=val;
        return ;
    }
    int m=(l+r)>>1;
    update(idx,val,l,m,p<<1);
    update(idx,val,m+1,r,(p<<1)|1);
    tree[p]=max(tree[p<<1],tree[(p<<1)|1]);
}
int ans[(1<<15)+5];
void update2(int val,int l,int r,int p)
{
    if(l==r)
    {
        ans[l]=val;
        return ;
    }
    int m=(l+r)>>1;
    if(val==1)
    {
        if(tree[(p<<1)]==tree[p])
        {
            update2(0,l,m,p<<1);
            update2(1,m+1,r,(p<<1)|1);
        }
        else
        {
            update2(1,l,m,p<<1);
            update2(0,m+1,r,(p<<1)|1);

        }
    }
    else
    {
        update2(1,l,m,p<<1);
        update2(1,m+1,r,(p<<1)|1);

    }
}
void print(int l,int r,int p)
{
    if(l==r)
    {
        printf("%d %d\n",l,tree[p]);
        return ;
    }
    int m=(l+r)>>1;
    print(l,m,(p<<1));
    print(m+1,r,(p<<1)|1);
}
void Print(int l,int r,int p){
    printf("\n------------------------- \n");
    print(l,r,p);
    printf("\n--------------------\n");
}
int main()
{
    cin>>n;
    vector<int>v;
    for(int i=1; i<=(1<<n); i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
        update(a,i,1,(1<<n),1);
    }
   // Print(1,1<<n,1);
    update2(1,1,1<<n,1);
    for(int i=0;i<v.size()-1;i++){
        if(i)cout<<" ";
        cout<<ans[v[i]];
    }

    return 0;
}
