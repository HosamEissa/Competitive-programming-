/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD  1000000007
const int N =1e5+5;
int n;
string s;
int dp[100001][3][3];
int solve(int idx,int b,int b2){
    if(idx==n)
        return b&b2;
    if(dp[idx][b][b2]!=-1)return dp[idx][b][b2];

    int ans=0;
    char x;
    if(b)x='A';
    else x=s[idx];
    for(;x<='Z';x++){
        int nb,nb2;
        if(b)nb=1;
        else if(x>s[idx])nb=1;
        else nb=0;
        if(x>s[idx])nb2=1;
        else if(x==s[idx])nb2=b2;
        else nb2=0;
        ans=(ans+solve(idx+1,nb,nb2))%MOD;
    }
    return dp[idx][b][b2]=ans%MOD;
}
int main()
{
    cin>>s;
    n=s.size();
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0,0)<<endl;
}
