/*
Author: Hossam Eissa
Idea: state idx,number%m,==a,==b
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD  1000000007
const int N=2e3+5;
int n,m,d;
string s1,s2;
vector<int>a,b;
int dp[N][N][2][2];
int add(int a,int b)
{
    a=(a*10)%m;
    a=(a+b)%m;
    return a;
}
int x1,x2;
int solve(int idx=0,int num=0,bool B=1,bool B2=1)
{
    if(idx==n){
         return num==0;
    }
    int &ans=dp[idx][num][B][B2];
    if(~ans)return ans;
     ans=0;
    int mn=0,mx=9;
    if(B)mn=a[idx];
    if(B2)mx=b[idx];
    if(idx%2){
            if(mn<=d&&d<=mx)
                ans=solve(idx+1,add(num,d),B&d==mn,B2&d==mx);
    }
    else {
            for(int i=mn;i<=mx;i++){
                    if(i==d)continue;
                ans+=solve(idx+1,add(num,i),B&i==mn,B2&i==mx)%MOD;
                ans%=MOD;
            }

    }

    //cout<<"en "<<idx<<" "<<num<<" "<<B<<" "<<B2<<" "<<val <<" "<<ans<<endl;
    return ans=ans%MOD;
}
bool check(int i){
    stringstream ss;
    string s;
    ss<<i;
    ss>>s;
    for(int i=0;i<s.size();i++){
        if(i%2&&s[i]-'0'!=d)
            return 0;
    }
    return 1;
}
int main()
{
    cin>>m>>d;
    cin>>s1>>s2;
    n=s1.size();
    for(int i=0; i<n; i++)a.push_back(s1[i]-'0'),b.push_back(s2[i]-'0');
    //for(int i=0; i<n; i++)x1=x1*10+a[i],x2=x2*10+b[i];
    memset(dp,-1,sizeof dp);
  /*  cout<<x1<<" "<<x2<<endl;
    for(int i=x1;i<=x2;i++){
        if(check(i)&&i%m==0){
            cout<<i<<" "<<endl;
        }
    }*/
    cout<<solve();
}
