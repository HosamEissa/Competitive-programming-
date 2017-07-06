/*
Author: Hossam Eissa
Idea: if chars are the same try deleting one or leave it else keep matching
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
int n;
vector<int>v;
string s1,s2;
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
int dp[10005][1005];
int solve(int idx,int idx2){
        if(idx2==s2.size())return 10000000;
        if(idx==n){
            return 0;
        }
            int &res=dp[idx][idx2];
        if(res!=-1)return res;
        if(s1[idx]==s2[idx2]){
         return res= min(solve(idx+1,idx2)+1,solve(idx+1,idx2+1));

        }
        else {
            while(idx2&&s1[idx]!=s2[idx2])idx2=v[idx2-1];
        return  res= solve(idx+1,idx2+(s1[idx]==s2[idx2]));
        }
}
int main()
{
    in;
   // FO;
    while(cin>>s1>>s2)
    {
        n=s1.size();
        memset(dp,-1,sizeof dp);
        v=kmparr(s2);
        cout<<solve(0,0)<<endl;
    }


}
