/*
Author: Hossam Eissa
Idea:do exactly as he said in the problem
*/
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
class RangeGame
{
public:
    vector<int>ans;
    vector<vector<pair<int,int>>> getallnumbers(vector<string>&p)
    {
        vector<vector<pair<int,int> > >np(p.size());
        for(int i=0; i<p.size(); i++)
        {
            stringstream ss;
            ss<<p[i];
            string tmp;
            while(ss>>tmp)
            {
                bool range=0;
                for(int j=0; !range&&j<tmp.size(); j++)
                {
                    if(tmp[j]=='-')
                    {
                        range=1;
                        tmp[j]=' ';

                    }
                }
                stringstream ss2;
                ss2<<tmp;
                int a,b;
                if(range)
                {
                    ss2>>a;
                    ss2>>b;
                    np[i].push_back({a,b});
                }
                else
                {
                    ss2>>a;
                    np[i].push_back({a,a});

                }

            }
        }
        return np;

    }
    void solve( vector<vector<pair<int,int> > >&v, vector<vector<pair<int,int> > >&hints,int idx)
    {
        map<int,int>mp;
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].size(); j++)
            {
                mp[v[i][j].first];
                mp[v[i][j].second];
            }
        }
        int mx=0,num=0;
        for(auto &x : mp)
        {
            int val=x.first;
            for(int i=0; i<v.size(); i++)
            {
                for(int j=0; j<v[i].size(); j++)
                {
                    if(v[i][j].first<=val&&val<=v[i][j].second)
                        x.second++;
                }
            }
            if(mx<x.second)
            {
                mx=x.second;
                num=val;
            }
            cout<<idx<<" "<<val<<" "<<x.second<<endl;
        }
        ans.push_back(num);
        if(idx==0)return ;
        vector<pair<int,int>>currhint=hints.back();
        hints.pop_back();
        vector<bool>vis(v.size());
        for(auto x:currhint){
                int val1=x.first;
                int val2=x.second;
             for(int i=0; i<v.size(); i++)
            {
                for(int j=0; j<v[i].size(); j++)
                {
                    if(v[i][j].first<=val1&&val1<=v[i][j].second)
                        vis[i]=1;
                    if(v[i][j].first<=val2&&val2<=v[i][j].second)
                        vis[i]=1;
                    if(val1<=v[i][j].first&&v[i][j].first<=val2)
                        vis[i]=1;
                    if(val1<=v[i][j].second&&v[i][j].second<=val2)
                        vis[i]=1;

                }
            }
            cout<<idx<<" "<<val1<<" "<<val2<<endl;
        }
         vector<vector<pair<int,int> > >newv;
        for(int i=0;i<v.size();i++){
            if(!vis[i]){
                    newv.push_back(v[i]);
            }
        }
        solve(newv,hints,idx-1);
    }
    vector <int> bestDoors(vector <string> possible, vector <string> hints)
    {
        vector<vector<pair<int,int>  >  >v=getallnumbers(possible);
        vector<vector<pair<int,int>  >  >v2=getallnumbers(hints);
        reverse(v2.begin(),v2.end());
        solve(v,v2,v2.size());
        return ans;
    }
};
int main()
{
    RangeGame r;
        vector<int>ans=r.bestDoors({"346591240","858005279","1321831520","1453846384","1972718383","530431653-1848872872"},{"1400000000-2000000000","400000000-600000000"});
        for(auto i :ans){
            cout<<i<<endl;
        }
    return 0;
}
