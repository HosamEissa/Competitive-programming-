/*
Author: Hossam Eissa
Idea:dikstra from the start then get the minmum of the k nodes=c and put it's cost to x+c if better
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N =1e5+5;
int n,m,k,x,s;
vector<vector<pair<int,int>>>v2;
ll cost[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&n,&k,&x,&m,&s);
        fill(cost,cost+N,1e18);
        v2.clear();
        v2.resize(n+1);
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            v2[a].push_back({b,c});
            v2[b].push_back({a,c});
        }
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> >pq;
        cost[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
                int node=pq.top().second;
                ll c=pq.top().first;
                pq.pop();
                if(cost[node]<c)continue;
                for(auto i : v2[node]){
                    int nn=i.first;
                    ll nc=c+i.second;
                    if(nc<cost[nn]){
                        cost[nn]=nc;
                        pq.push({nc,nn});
                    }
                }
        }
        ll c=1e18;
        for(int i=1;i<=k;i++)
            c=min(c,cost[i]);
        for(int i=1;i<=k;i++){
            if(c+x<cost[i]){
                cost[i]=c+x;
                pq.push({cost[i],i});
            }
        }

        while(!pq.empty()){
                int node=pq.top().second;
                ll c=pq.top().first;
                pq.pop();
                if(cost[node]<c)continue;
                for(auto i : v2[node]){
                    int nn=i.first;
                    ll nc=c+i.second;
                    if(nc<cost[nn]){
                        cost[nn]=nc;
                        pq.push({nc,nn});
                    }
                }
        }

        printf("%lld",cost[1]);
        for(int i=2;i<=n;i++){
            printf(" %lld",cost[i]);
        }
        printf("\n");
    }
}
