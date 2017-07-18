/*
Author: Hossam Eissa
Idea:try to use every bit and if you used all of them and mod is 0 return answer
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
ll n,m;
int arr[19];
ll dp[(1<<18)][100];
ll solve(int msk,int mod){
    //cout<<msk<<" "<<mod<<endl;
    if(msk==(1<<n)-1)return mod==0;
    if(~dp[msk][mod])return dp[msk][mod];
    ll ans=0;
    int bits=0;
    for(int i=0;i<n;i++){
        if(msk==0&&arr[i]==0)continue;
        if(!(msk&(1<<i))){
            if(bits&(1<<arr[i]))continue;
            bits|=(1<<arr[i]);
            int nmsk=msk|(1<<i);
            int nmod=(mod*10+arr[i])%m;
            ans+=solve(nmsk,nmod);
        }
    }
    return dp[msk][mod]=ans;

}
int main()
{

    cin>>n>>m;
    int i=0;
    while(n){
        arr[i]=n%10;
        i++;
        n/=10;
    }
    n=i;
    memset(dp,-1,sizeof dp);
    ll ans=solve(0,0);
    cout<<ans<<endl;
}
