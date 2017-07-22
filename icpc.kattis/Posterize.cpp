/*
Author: Hossam Eissa
Idea:pre calculate the color represent the colors form a to b and then dp then answer using idx and k
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
int n,m;
const int N=256+5;
vector<pair<ll,ll> >v;
ll F[N][N];
ll dp[N][N];
ll solve(int idx,int k){
       if(idx==n)
            return 0;
        if(k==0)return 2e18;
       ll &ans=dp[idx][k];
       if(~ans)return ans;
       ans=2e18;
       for(int i=idx;i<n;i++){
        ans=min(ans,solve(i+1,k-1)+F[idx][i]);
       }
       return ans;

}
int main()
{
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            ll sum1=0;
            ll sum2=0;
            for(int k=i;k<=j;k++){
                sum1+=v[k].first*v[k].second;
                sum2+=v[k].second;
            }
            ll mid=(sum1)/sum2;
            ll mid2=mid+1;
            ll val=0;
            ll val2=0;
            for(int k=i;k<=j;k++){
                val+=(v[k].first-mid)*(v[k].first-mid)*v[k].second;
                val2+=(v[k].first-mid2)*(v[k].first-mid2)*v[k].second;

            }
            F[i][j]=min(val,val2);
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(0,m);

    return 0;
}
