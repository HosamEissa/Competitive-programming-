/*
Author: Hossam Eissa
Idea:try to take and leave every number 
*/
#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[1001];
int dp[1001][1001];
bool solve(int idx,int sum){
    if(sum==0)return 1;
    if(idx==1000)return 0;
    if(~dp[idx][sum])return dp[idx][sum];
    bool ans=solve(idx+1,sum);
    for(int i = 1;!ans&&i<=arr[idx];i++){
        ans|=solve(idx+1,(sum+(i*idx))%m);
    }
    return dp[idx][sum]=ans;
}
int main()
{
   // FO;
   cin>>n>>m;
   for(int i=0;i<n;i++){
    int a;
    cin>>a;
    arr[a%m]++;
   }
   bool ans=0;
    memset(dp,-1,sizeof dp);
    for(int i=0;!ans&&i<m;i++){
       if(arr[i]){
       //     cout<<arr[i]<<endl;
        arr[i]--;
        ans|=solve(i,i);
        arr[i]++;
    }
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
