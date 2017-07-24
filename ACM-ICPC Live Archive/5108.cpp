/*
Author: Hossam Eissa
Idea:calculate the area of the polygon and do prefix sum on area of each triangle
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 2000000000;
const double PI=acos(-1);
int main()
{
    int n,q;
    bool x=0;
    freopen("o.txt","w",stdout);
    while(scanf("%d%d",&n,&q)==2&&(n|q)){
        if(x)puts("");
        x=1;
        vector<ll>X(n+1),Y(n+1);
        vector<ll>Z(n+1);
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&X[i],&Y[i]);
        }
        X[n]=X[0];
        Y[n]=Y[0];
        for(int i=0;i<n;i++){
            Z[i+1]=Z[i]+X[i]*Y[i+1]-X[i+1]*Y[i];
        }
        while(q--){
            int a,b;
            scanf("%d%d",&a,&b);
            ll ans=abs(Z[b]-Z[a]+X[b]*Y[a]-X[a]*Y[b]);
            ans=min(ans,abs(Z[n])-ans);
            printf("%lld.%d\n",ans/2,ans%2?5:0);
        }
    }

}
