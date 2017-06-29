/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<string,pair<int,pair<int,int> > > xx;
#define gold second.first
#define silver second.second.first
#define bronze second.second.second
 bool comp(const xx a,const xx b )
    {
        if(a.gold>b.gold)return 1;
        else if(a.gold<b.gold)return 0;
        else if(a.gold==b.gold)
        {
            if(a.silver>b.silver)return 1;
            else if(a.silver<b.silver)return 0;
            else if(a.silver==b.silver)
            {

                if(a.bronze>b.bronze)return 1;
                else if(a.bronze<b.bronze)return 0;
                else if(a.bronze==b.bronze)
                {
                    return a.first<b.first;
                }
            }
        }
        return 0;
    }
class MedalTable
{
    string getnumber(int a)
    {
        stringstream ss;
        ss<<a;
        string ans;
        ss>>ans;
        return ans;
    }
public:
    vector <string> generate(vector <string> results)
    {

        map<string,pair<int,pair<int,int> > >mp;
        for(auto it=results.begin();it!=results.end();it++)
        {
            stringstream ss;
            ss<<*(it);
            string s1,s2,s3;
            ss>>s1>>s2>>s3;
           // error(s1,s2,s3);
            mp[s1].first++;
            mp[s2].second.first++;
            mp[s3].second.second++;
        }
        vector<xx>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),comp);
        vector<string>answer;
        for(int i=0;i<v.size();i++)
        {
            //error(i,v[i].first,v[i].gold,v[i].silver,v[i].bronze);
            string tmp;
            tmp+=v[i].first;
            tmp+=' ';
            tmp+=getnumber(v[i].gold);
            tmp+=' ';
            tmp+=getnumber(v[i].silver);
            tmp+=' ';
            tmp+=getnumber(v[i].bronze);
            answer.push_back(tmp);
        }
        return answer;
    }
};
