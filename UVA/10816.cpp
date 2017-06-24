/*
Author: Hossam Eissa
Idea: binary search the heat and get the cost using dikstra
*/
#include <bits/stdc++.h>
#include <map>
using namespace std;
#define ll long long
#define se second
#define fi first
#define mk(a, b) make_pair(a, b)
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvpi vector<vector<pii>>
#define pli pair<ll, int>
#define INF (int)2e9
#define MOD 100000000
#define MAX (int)2e5 + 5
#define FI freopen("i.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sf(a, b) scanf("%d %d", &a, &b)
#define edge pair<pair<int, int>, int>
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 }; // 4 Directio
// int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
// int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
// 8 direction

// int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
// int dy[] = { 1,2,2,1,-1,-2,-2,-1};
// Knight Direction

const int N=1e2+5;
const double EPS=1e-1;
int dcmp(double a,double b)
{
    return fabs(a-b)<= EPS?0:a<b?-1:1;
}

vector<vector<pair<int,pair<double,double> > > >v2;
int n,m,st,en,par[N];
double costs[N],total=0;;
bool ok(double t)
{

    priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> >  >pq;
    total=0;
    fill(costs,costs+N,1e9);
    memset(par,-1,sizeof par);
    costs[st]=0;
    pq.push({0,st});
    while(!pq.empty())
    {
        int node=pq.top().second;
        double c=pq.top().first;
        pq.pop();
        if(c>costs[node])continue;
        total+=c;
        if(node==en)break;
        costs[node]=c;
        for(auto i : v2[node])
        {
            int nn=i.first;
            double nc=c+i.second.second;
            double nt=i.second.first;
            if(t>=nt&&nc<costs[nn]){
            //cout<<node<<" "<<t<<" "<<nn<<" "<<nc<<" "<<nt<<" "<<costs[nn]<<endl;
                costs[nn]=nc;
                pq.push({nc,nn});
                par[nn]=node;
            }

        }
    }
    return costs[en]!=1e9;
}

int main()
{
    in;
  //  FO;
    cout<<fixed<<setprecision(1);
    while(cin>>n>>m)
    {
        cin>>st>>en;
        v2.clear();
        v2.resize(n+1);
        while(m--)
        {
            int a,b;
            double c,d;
            cin>>a>>b>>c>>d;
            v2[a].push_back({b,{c,d}});
            v2[b].push_back({a,{c,d}});
        }
        double l=20,r=50;
        while(abs(r-l)>1e-4)
        {
            double mid=(l+r)/2;
            if(ok(mid))
            {
                r=mid;
            }
            else l=mid;
        }
        ok(l+0.09);
        int x=en;
        vector<int>ans;
        /*for(int i=1;i<=n;i++){
            cout<<i<<" "<<par[i]<<" "<<costs[i]<<endl;
        }*/
        while(x!=-1){
            ans.push_back(x);
            x=par[x];
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<endl<<costs[en]<<" "<<l<<endl;

    }
}
