/*
Author: Hossam Eissa

Idea:

*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include <map>
#include<unordered_map>
#include<complex>
using namespace std;
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pf(a) printf("%d",a)
#define pf2(a,b) printf("%d %d",a,b)
#define pf3(a,b,c) printf("%d %d %d",a,b,c)
#define sfl(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pfl(a) printf("%lld",a)
#define pfl2(a,b) printf("%lld %lld",a,b)
#define pfl3(a,b,c) printf("%lld %lld %lld",a,b,c)
#define nl printf("\n")
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define edge pair<ll, pair<int, int>>
#define CYA  exit(0);
#define pi acos(-1);
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
/*int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int N = 3e2+ 50;
const double EPS=1e-8;
const double INF=2e15+5;
ll n, m, k;
int mat[N][N];
vector<vector<int> >v2;
bool vis[N];
int cost[N];
void bfs(int st)
{
    queue<int>q;
    q.push(st);
    cost[st]=0;
    vis[st]=1;
    while(!q.empty())
    {
    int node=q.front();
    q.pop();
    for(auto i : v2[node]){
        if(!vis[i]){
            vis[i]=1;
            cost[i]=cost[node]+1;
            q.push(i);
        }
    }


    }
}
int main()
{
    // FO;
    in;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<string,int>mp;
        mp["Ahmad"]=0;
        int cnt=1;
        memset(mat,0,sizeof mat);
        for(int i=0; i<n; i++)
        {
            string s1,s2,s3;
            cin>>s1>>s2>>s3;
            int c1=0,c2=0,c3=0;
            if(mp.count(s1))
                c1=mp[s1];
            else {
             //       cout<<"66666666"<<endl;
                c1=mp[s1]=cnt++;
            }
            if(mp.count(s2))c2=mp[s2];
            else {
                    c2=mp[s2]=cnt++;
            }
            if(mp.count(s3))c3=mp[s3];
            else {
                    c3=mp[s3]=cnt++;}

            mat[c1][c2]=1;
            mat[c1][c3]=1;
            mat[c2][c3]=1;
            mat[c2][c1]=1;
            mat[c3][c1]=1;
            mat[c3][c2]=1;
        }
        v2.clear();
        v2.resize(cnt+1);
      //  cout<<"a7a"<<endl;
        for(int i=0; i<=cnt; i++)
        {
            for(int j=0; j<=cnt; j++)
            {
                if(mat[i][j])
                    v2[i].push_back(j);
            }
        }
        memset(vis,0,sizeof vis);
        fill(cost,cost+N,1000000);
        bfs(0);
        vector<pair<int,string> >ans;
        for (auto i : mp){
            ans.push_back({cost[i.second],i.first});
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].second<<" ";
            if(ans[i].first==1000000)
                cout<<"undefined"<<endl;
            else cout<<ans[i].first<<endl;
        }



    }
}
