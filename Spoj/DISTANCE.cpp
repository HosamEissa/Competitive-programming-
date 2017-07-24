/*
Author: Hossam Eissa
Idea:convert from Manhattan distance to king distance and get mx-mn
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi=acos(-1);
int n,d;
ll v[100005][7];
ll king[100005][33];
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<d; j++){
            scanf("%lld",&v[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<(1<<(d-1)); j++)
        {
            ll val=v[i][0];
            for(int k=0;k<d-1;k++){
                    if(j&(1<<k)){
                        val-=v[i][k+1];
                    }
                    else {
                        val+=v[i][k+1];
                    }
            }
            king[i][j]=val;
        }
    }
    ll ans=0;
    for(int i=0;i<(1<<(d-1));i++){
        ll mx=-1e18;
        ll mn=1e18;
        for(int j=0;j<n;j++){
        mx=max(mx,king[j][i]);
        mn=min(mn,king[j][i]);
        }
        ans=max(ans,mx-mn);
    }
    printf("%lld\n",ans);
}
