/*
Author: Hossam Eissa
Idea: try all the subsequences and match using failure array  
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
string s1,s2,s3;
vector<int>v;
vector<int> kmparr(string s)
{
    vector<int>ret(s.size());
    int j=0;
    for(int i=1;i<s.size();i++){
        while(j&&s[i]!=s[j])j=ret[j-1];
        if(s[i]==s[j])j++;
        ret[i]=j;
    }
    return ret;

}
int dp[101][101][101];
int solve(int i,int j,int k){
    //cout<<i<<" "<<j<<" "<<k<<endl;
    if(k==s3.size())return -1e8;
    if(i==s1.size()||j==s2.size())return dp[i][j][k]=0;
    int &ans=dp[i][j][k];
    if(~ans)return ans;
   // int ans=0;
    ans=max(solve(i+1,j,k),solve(i,j+1,k));
    if(s1[i]==s2[j]){
        if(s1[i]==s3[k]){
            ans=max(ans,solve(i+1,j+1,k+1)+1);
        }
        else {
                while(k&&s1[i]!=s3[k])
                    k=v[k-1];
            ans=max(ans,solve(i+1,j+1,k+(s1[i]==s3[k]))+1);
        }
    }

return ans;
}
void print(int i,int j,int k){

    if(k==s3.size())return ;
    if(i==s1.size()||j==s2.size())return ;
    if(dp[i+1][j][k]==dp[i][j][k]){
            print(i+1,j,k);
            return ;
    }
    else if(dp[i][j+1][k]==dp[i][j][k]) {
            print(i,j+1,k);
        return;
    }
    if(s1[i]==s2[j]){
            cout<<s1[i];
        if(s1[i]==s3[k]){
            print(i+1,j+1,k+1);
        }
        else {while(k&&s1[i]!=s3[k])
                    k=v[k-1];
            print(i+1,j+1,k+(s1[i]==s3[k]));
        }
    }
}
int main()
{
    cin>>s1>>s2>>s3;
    memset(dp,-1,sizeof dp);
    v=kmparr(s3);
    int ans=solve(0,0,0);

    if(ans<=0)cout<<0;
    else{
           // cout<<ans<<endl;
        print(0,0,0);
    }


}

