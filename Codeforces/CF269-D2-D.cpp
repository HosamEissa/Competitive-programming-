/*
Author: Hossam Eissa
Idea: map the two array into differnce arrays the apply string matching
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
#define vi vector<int>
vector<int> kmparr(vi v1,vi v2)
{
    vector<int>ret(v1.size()+v2.size()+1);
    int j=0;
    vi s=v2;
    s.push_back(-2e9);
    s.insert(s.end(),v1.begin(),v1.end());
    for(int i=1;i<s.size();i++){
        while(j&&s[i]!=s[j])j=ret[j-1];
        if(s[i]==s[j])j++;
        ret[i]=j;
    }
    return ret;
}
int main()
{
    in;
   // FO;
   int n,m;

    vector<int>v1,v2;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i)v1.push_back(v[i]-v[i-1]);
    }

    for(int i=0;i<m;i++){
        cin>>v[i];
        if(i)v2.push_back(v[i]-v[i-1]);
    }
    int ans=0;

    vi x=kmparr(v1,v2);
    for(int i=0;i<x.size();i++){
        if(x[i]==v2.size())ans++;
    }
    cout<<ans<<endl;
}
