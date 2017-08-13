/*
Author: Hossam Eissa
Idea:if you have interval inside the other you don't need to check the outer one remove unneeded intervals and dp on the left

*/
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
class WolfInZooDivTwo
{
public:

    vector<pair<int,int> >v;
    int n;
    const int MOD=1e9+7;
    ll dp[301][301];
    bool vis[301];
    struct node
    {
        int a,b;
        node(int x,int l)
        {
            a=x;
            b=l;
        }
        bool operator < (const node & x)const
        {
            if(a==x.a)
                return b>x.b;
            return a<x.a;
        }
    };
    ll solve(int idx,int last)
    {
      //  cout<<idx<<" "<<last<<endl;
        if(idx==n)
        {
            return last==v.size();
        }
        ll &ans=dp[idx][last];
        if(ans!=-1)return ans;
        ans=0;
        if(last==v.size())
        {
            ans=(solve(idx+1,last)*2)%MOD;
        }
        else if(idx<v[last].first)
        {
            ans=(solve(idx+1,last)*2)%MOD;
        }
        else if(idx>v[last].second)
        {
            ans=0;
        }
        else
        {
            ans=(solve(idx+1,last))%MOD;
            while(last<v.size()&&idx>=v[last].first)
                last++;
            ans+=(solve(idx+1,last))%MOD;
        }
        ans=(ans%MOD);
        return ans;
    }
    int count(int N, vector <string> L, vector <string> R)
    {
        n=N;
        memset(dp,-1,sizeof dp);
        vector<node>input;
        string l,r;
        for(int i=0; i<L.size(); i++)
            l+=L[i];
        for(int i=0;i<R.size();i++)
                r+=R[i];

        set<pair<int,int>>st;
        stringstream ss,ss2;
        ss<<l;
        ss2<<r;
        int le,rr;
        while(ss>>le){
            ss2>>rr;
           st.insert({le,rr});
        }
        for(auto i : st)
            v.push_back(i);
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                //if(vis[i]||vis[j])continue;
                if(v[i].first<=v[j].first&&v[j].second<=v[i].second)
                    vis[i]=1;
               // if(vis[i]||vis[j])continue;
                if(v[j].first<=v[i].first&&v[i].second<=v[j].second)
                    vis[j]=1;
            }
        }
        vector<pair<int,int>>v2;
        for(int i=0;i<v.size();i++)
        {
            if(!vis[i])
                v2.push_back(v[i]);
        }
        v=v2;
        sort(v.begin(),v.end());
            cout<<v.size()<<endl;
            for(auto i : v)
                cout<<i.first<<" "<<i.second<<endl;
        return solve(0,0);
    }

};
int main(){
    WolfInZooDivTwo w;
    cout<<w.count(12, {"6 6 10 6 10 9 5 10 5 4 0 3"}, {"10 10 10 6 10 10 5 10 9 11 10 10"})<<endl;
return 0;
}
