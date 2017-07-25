/*
Author: Hossam Eissa
Idea:do a line swep if it touchs a horzintal line add or erase it from the answer else count how many lines intersecet with the verticall line
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 4e5+5;
const double PIs=acos(-1);
ll n,m,k;
struct seg
{
    int x1,x2,y1,y2;
    seg(int X,int Y,int X1,int Y1)
    {
        x1=X;
        y1=Y;
        x2=X1;
        y2=Y1;
    }
};
struct BIT
{
    int C[N];
    int n;

    void init(int n)
    {

        this->n = n = (1 << (int) ceil(log2(n)));

        memset(C, 0,sizeof C);
    }

    void add(int idx, int valC)
    {
        //++idx;
        while (idx < N)
        {

            C[idx] += valC;
            idx += (idx & (-idx));
        }
    }
    int get(int idx)
    {
        ll valC = 0;
        int x = idx;
        //  ++idx;
        while (idx)
        {

            valC += C[idx];
            idx -= (idx & (-idx));
        }
        return valC;
    }

    int find(ll val)
    {
        int st = 0;
        for (int mid = (n >> 1); mid; mid >>= 1)
        {
            int idx = st + mid - 1;
            ll cur = C[idx];
            if (val > cur)
            {
                st += mid;
                val -= cur;
            }
        }
        return st;
    }

} bit;
int ans[N];
vector<seg>input;
void solve(vector<pair<int,seg>>&vert,vector<pair<int,seg>>&hor)
{
    bit.init(1e5+5);
    vector<pair<int,pair<int,int>>>vx;
    for(int i=0; i<vert.size(); i++)
    {
        vx.push_back({vert[i].second.x1,{0,vert[i].first}});
    }
    for(int i=0; i<hor.size(); i++)
    {
        vx.push_back({hor[i].second.x1,{-1,i}});
        vx.push_back({hor[i].second.x2,{1,i}});
    }
    sort(vx.begin(),vx.end());
    for(int i=0; i<vx.size(); i++)
    {
        int idx=vx[i].second.second;
        if(vx[i].second.first==0)
        {
            ans[idx]=bit.get(input[idx].y2)-bit.get(input[idx].y1-1);
        }
        else if(vx[i].second.first==-1)
        {
            bit.add(hor[idx].second.y1,1);
        }
        else
        {
            bit.add(hor[idx].second.y1,-1);
        }
    }
}
void solve2(vector<pair<int,seg>>&vert,vector<pair<int,seg>>&hor)
{
    bit.init(1e5+5);
    vector<pair<int,pair<int,int>>>vx;
    for(int i=0; i<hor.size(); i++)
    {
        vx.push_back({hor[i].second.y1,{0,hor[i].first}});
    }
    for(int i=0; i<vert.size(); i++)
    {
        vx.push_back({vert[i].second.y1,{-1,i}});
        vx.push_back({vert[i].second.y2,{1,i}});
    }
    sort(vx.begin(),vx.end());
    for(int i=0; i<vx.size(); i++)
    {
        int idx=vx[i].second.second;

        if(vx[i].second.first==0)
        {
            ans[idx]=bit.get(input[idx].x2)-bit.get(input[idx].x1-1);
        }
        else if(vx[i].second.first==-1)
        {
            bit.add(vert[idx].second.x1,1);
        }
        else
        {
            bit.add(vert[idx].second.x1,-1);
        }
    }
}
int main()
{
    cin>>n;
    vector<pair<int,seg>>hor,vert;
    map<pair<int,int>,int>mp;
    for(int i=0; i<n; i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)
        {
                if(y1>y2)swap(y1,y2);
                vert.push_back({i,seg(x1,y1,x2,y2)});
                input.push_back(seg(x1,y1,x2,y2));
        }
        else
        {
                if(x1>x2)swap(x1,x2);
                hor.push_back({i,seg(x1,y1,x2,y2)});
                input.push_back(seg(x1,y1,x2,y2));
        }
        mp[ {x1,y1}]++;
        mp[ {x2,y2}]++;
    }
    solve(vert,hor);
    solve2(vert,hor);
    ll sum=0;
    for(int i=0; i<n; i++){
        ans[i]-=mp[{input[i].x1,input[i].y1}]-1;
        ans[i]-=mp[{input[i].x2,input[i].y2}]-1;
        sum+=ans[i];
    }
    cout<<sum/2<<endl;
    for(int i=0; i<n; i++)
    {
        if(i)cout<<" ";
        cout<<ans[i];
    }
}
