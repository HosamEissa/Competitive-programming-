/*
Author: Hossam Eissa
Idea:dp on each floor if the ball break go i-1 and b-1 if it didn't break continue with f-i and b
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[1001][51];
int solve(int f,int b){
    if(!f)return 0;
    if(b==1)return f;
    if(dp[f][b]!=-1)return dp[f][b];
    int ans=1e9;
    for(int i=1;i<=f;i++){
        ans=min(ans,max(solve(f-i,b),solve(i-1,b-1))+1);
    }
    return dp[f][b]=ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof dp);
        int tt,f,b;
        scanf("%d%d%d",&tt,&b,&f);
        printf("%d %d\n",tt,solve(f,b));
    }


}
