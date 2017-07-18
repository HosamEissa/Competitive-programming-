/*
Author: Hossam Eissa
Idea:try every 3 adjacent cells
*/
#include <bits/stdc++.h>
using namespace std;
int n,arr[21];
int dp[(1<<20)];
int solve(int msk)
{
    if(msk==(1<<n)-1)
        return 0;
    int &ans=dp[msk];
    if(~ans)return ans;
    ans=1e18;
    int sum=0;
    for(int i=0;i<n;i++){
        if(1<<(i)&msk)continue;
        sum+=arr[i];
    }
    for(int i=0;i<n;i++){
        if(msk&(1<<i))continue;
        int nmsk=msk;
        int sum2=0;
        for(int j=0;j<3;j++){
            int ni=(i+j)%n;
            if(msk&(1<<ni))continue;
            sum2+=arr[ni];
            nmsk|=(1<<ni);
        }
        ans=min(ans,solve(nmsk)+sum-sum2);
    }
    return ans;

}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<solve(0)<<endl;
}
