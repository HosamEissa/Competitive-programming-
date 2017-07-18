/*
Author: Hossam Eissa
Idea: take mask having all number from idx-k to idx+k to indicate if number is used or not
*/
#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define MOD 1000000007
int n,k;
int dp[201][(1<<13)];
int x=0;
int solve(int idx,int msk)
{
    if(idx==n)return 1;
    //ll &ans=dp[idx][msk];
    if(~dp[idx][msk])return dp[idx][msk];
    int ans=0;
    int st=0;
    if(n-idx<k)
        st=k-(n-idx);
   // cout<<idx<<" "<<msk<<" "<<st<<" "<<min(idx+k,2*k+1)<<endl;
    int en=min(idx+k,2*k+1);
    for(int i=st; i<en; i++)
    {
        int c=(1<<i);
        if(!(msk&c)){

           int nmsk=msk;
        nmsk|=c;
        nmsk<<=1;
        if(idx<=k)
            ans=(ans+solve(idx+1,nmsk)%MOD)%MOD;
        else if((nmsk&x))
        {
            nmsk&=~(x);
            ans=(ans+solve(idx+1,nmsk)%MOD)%MOD;

        }
        }
    }
    return dp[idx][msk]=ans;

}
int main()
{
   // FO;
    cin>>k;
    x=(1<<(2*k+1));
    for(int i=1; i<=200; i++)
    {
        n=i;
        memset(dp,-1,sizeof dp);
        cout<<solve(1,0)<<endl;
    }
}
