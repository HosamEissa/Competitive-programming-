/*
Author: Hossam Eissa
Idea:dikstra from the start in you direction if u touch it put it in the pq and keep doing that till you finish
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N =1e5+5;
int n;
ll t;
int X[N],Y[N],D[N];
map<int,set<pair<int,int>>>xs;
map<int,set<pair<int,int>>>ys;
ll cost[N];
void dikstra(){
    fill(cost,cost+n,t);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,0});
    cost[0]=0;
    while(!pq.empty()){
        ll c=pq.top().first;
        int idx=pq.top().second;
        pq.pop();
        int x=X[idx];
        int y=Y[idx];
        int dir=D[idx];
        if(c>cost[idx])continue;
        if(dir==0){
                for(auto it=ys[x].upper_bound({y,idx});it!=ys[x].end();it++){
                    int nidx=it->second;
                    int ny=Y[nidx];
                    int nx=X[nidx];
                    int ndir=D[nidx];
                    ll nc=c+abs(y-ny);
                    if(nc<cost[nidx]){
                        cost[nidx]=nc;
                        pq.push({nc,nidx});
                    }
                    if(dir==ndir)break;
                }
        }
        else if(dir==1){

                for(auto it=ys[x].lower_bound({y,0});;it--){
                    int nidx=it->second;
                    int ny=Y[nidx];
                    int nx=X[nidx];
                    int ndir=D[nidx];
                    ll nc=c+abs(y-ny);
                    if(nc<cost[nidx]){
                        cost[nidx]=nc;
                        pq.push({nc,nidx});
                    }
                    if(dir==ndir&&idx!=nidx)break;
                    if(it==ys[x].begin())break;
                }

        }
        else if(dir==2){

                for(auto it=xs[y].upper_bound({x,idx});it!=xs[y].end();it++){
                    int nidx=it->second;
                    int ny=Y[nidx];
                    int nx=X[nidx];
                    int ndir=D[nidx];
                    ll nc=c+abs(x-nx);
                    if(nc<cost[nidx]){
                        cost[nidx]=nc;
                        pq.push({nc,nidx});
                    }
                    if(dir==ndir)break;
                }
        }
        else {

                for(auto it=xs[y].lower_bound({x,0});;it--){
                    int nidx=it->second;
                    int ny=Y[nidx];
                    int nx=X[nidx];
                    int ndir=D[nidx];
                    ll nc=c+abs(x-nx);
                    if(nc<cost[nidx]){
                        cost[nidx]=nc;
                        pq.push({nc,nidx});
                    }
                    if(dir==ndir&&idx!=nidx)break;
                    if(it==xs[y].begin())break;

                }
        }
    }
}
int main()
{
    scanf("%d%lld",&n,&t);
    for(int i=0;i<n;i++){
        int x,y,dir;
        char c;
        scanf("%d%d %c",&x,&y,&c);
        if(c=='U')dir=0;
        if(c=='D')dir=1;
        if(c=='R')dir=2;
        if(c=='L')dir=3;
        D[i]=dir;
        Y[i]=y;
        X[i]=x;
        xs[y].insert({x,i});
        ys[x].insert({y,i});
    }
    dikstra();
    for(int i=0;i<n;i++){
        ll x=X[i];
        ll y=Y[i];
        ll dif1=0,dif2=0;
        if(D[i]==0)dif2=+(t-cost[i]);
        if(D[i]==1)dif2=-(t-cost[i]);
        if(D[i]==2)dif1=+(t-cost[i]);
        if(D[i]==3)dif1=-(t-cost[i]);
        printf("%lld %lld\n",x+dif1,y+dif2);
    }

}
