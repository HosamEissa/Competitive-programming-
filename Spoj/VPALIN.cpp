/*
Author: Hossam Eissa
Idea: every paln can concatenate with paln and stay paln if they can be made of the same string
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
vector<int> kmparr(string s)
{
    int j=0;
    vector<int>ret(s.size());
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
    int n;
  cin>>n;

        map<string,int>mp;
        for(int i=0;i<n;i++){
            string s;
            int a;
            cin>>a;
            cin>>s;
            vector<int>v=kmparr(s);
            int val=s.size()-v[s.size()-1];
            string s2;
            if(s.size()%val==0)s2=s.substr(0,val);
            else s2=s;
           // cout<<s2<<endl;
            mp[s2]++;
        }
        long long ans=0;
        for(auto i : mp){
            ans+=i.second*i.second;
        }
        cout<<ans<<endl;



}
