/*
Author: Hossam Eissa
Idea:sort person for size and then every person have 2 options only since all items have diffrent size
so dp the answer
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m;
const int N=1e5+5;
vector<pair<ll,ll> >items;
vector<pair<pair<ll,ll>,int> >person;;
ll dp[N][2][2];
map<int,int>mp;
map<int,int>mp2;
ll solve(int idx=0,bool p1=0,bool p2=0)
{

    if(idx==m)
        return dp[idx][p1][p2]=0;
    ll& ans=dp[idx][p1][p2];
    if(~ans)return ans;
    ans=0;
    if(idx==0)
    {
        ans=max(ans,solve(idx+1,p1,p2));
        if(mp.count(person[idx].first.first))
        {
            int x=mp[person[idx].first.first];
            if(x<=person[idx].first.second)
                ans=max(ans,solve(idx+1,1,0)+x);
        }
        if(mp.count(person[idx].first.first+1))
        {
            int x=mp[person[idx].first.first+1];
            if(x<=person[idx].first.second)
                ans=max(ans,solve(idx+1,0,1)+x);
        }
    }
    else
    {
        int np1=p1,np2=p2;
        if(person[idx].first.first-person[idx-1].first.first>1)
        {
            np1=np2=0;
        }
        else if(person[idx].first.first-person[idx-1].first.first==1)
        {
            np1=np2;
            np2=0;
        }
        ans=max(ans,solve(idx+1,np1,np2));
        if(!np1&&mp.count(person[idx].first.first))
        {
            int x=mp[person[idx].first.first];
            if(x<=person[idx].first.second)
                ans=max(ans,solve(idx+1,1,np2)+x);
        }
        if(!np2&&mp.count(person[idx].first.first+1))
        {
            int x=mp[person[idx].first.first+1];
            if(x<=person[idx].first.second)
                ans=max(ans,solve(idx+1,np1,1)+x);
        }
    }
    return ans;
}
vector<pair<int,int> >answer;
void print(int idx=0,int p1=0,int p2=0)
{

    if(idx==m)
    {
        return ;
    }
    if(idx==0)
    {
        if(dp[idx+1][p1][p2]==dp[idx][p1][p2])
        {
            print(idx+1,p1,p2);
            return ;
        }
        if(mp.count(person[idx].first.first))
        {
            int x=mp[person[idx].first.first];
            if(x<=person[idx].first.second&&dp[idx+1][1][0]+x==dp[idx][p1][p2])
            {
                answer.push_back({person[idx].second,mp2[person[idx].first.first]});
                print(idx+1,1,0);
                return ;
            }
        }
        if(mp.count(person[idx].first.first+1))
        {
            int x=mp[person[idx].first.first+1];
            if(x<=person[idx].first.second&&dp[idx+1][0][1]+x==dp[idx][p1][p2])
            {
                answer.push_back({person[idx].second,mp2[person[idx].first.first+1]});
                print(idx+1,0,1);
                return ;
            }
        }
    }
    else
    {
        int np1=p1,np2=p2;
        if(person[idx].first.first-person[idx-1].first.first>1)
        {
            np1=np2=0;
        }
        else if(person[idx].first.first-person[idx-1].first.first==1)
        {
            np1=np2;
            np2=0;
        }
        if(dp[idx+1][np1][np2]==dp[idx][p1][p2])
        {
            print(idx+1,np1,np2);
            return ;
        }
        if(!np1&&mp.count(person[idx].first.first))
        {
            int x=mp[person[idx].first.first];
            if(x<=person[idx].first.second&&dp[idx+1][1][np2]+x==dp[idx][p1][p2])
            {
                answer.push_back({person[idx].second,mp2[person[idx].first.first]});
                print(idx+1,1,np2);
                return ;
            }
        }
        if(!np2&&mp.count(person[idx].first.first+1))
        {
            int x=mp[person[idx].first.first+1];
            if(x<=person[idx].first.second&&dp[idx+1][np1][1]+x==dp[idx][p1][p2])
            {
                answer.push_back({person[idx].second,mp2[person[idx].first.first+1]});
                print(idx+1,np1,1);
                return ;
            }
        }
    }


}
int main()
{
    in;
    cin>>n;
    memset(dp,-1,sizeof dp);
    items.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>items[i].second>>items[i].first;
        mp[items[i].first]=items[i].second;
        mp2[items[i].first]=i+1;

    }
    cin>>m;
    person.resize(m);
    for(int i=0; i<m; i++)
    {
        cin>>person[i].first.second>>person[i].first.first;
        person[i].first.second*=-1;
        person[i].second=i+1;

    }
    sort(person.begin(),person.end());
    for(int i=0; i<m; i++)
    {
        person[i].first.second*=-1;
    }
    cout<<solve()<<endl;
    print();

    cout<<answer.size()<<endl;
    for(int i=0; i<answer.size(); i++)
    {
        cout<<answer[i].first<<" "<<answer[i].second<<endl;
    }

    return 0;
}
