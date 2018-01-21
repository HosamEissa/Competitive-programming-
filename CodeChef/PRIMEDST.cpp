/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define start ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 5e4+5;
const double PI=acos(-1);
bool p[N];
vector<int>prime;
void sieve(){
    for(ll i=2;i<N;i++)
        if(!p[i]){
            prime.push_back(i);
            for(ll j=i*i;j<N;j+=i){
                p[j]=1;
            }
        }
}
int dist[N]={0};
ll ans;
struct TreeCentroid
{

    const int INF = 2000000000;
    vector<set<int>>G;
    int N,lgN,cnt;
    vector<int>par,sum;
    TreeCentroid(int n,int lgn)
    {
        N=n;
        lgN=lgn;
        G.resize(N);
        ans=0;
    }
    void add_edge(int u,int v)
    {
        G[u].insert(v);
        G[v].insert(u);
    }

    int dfs1(int u,int p){
        sum[u]=1;
        cnt++;
        for(auto v : G[u]){
            if(v!=p){
                dfs1(v,u);
                sum[u]+=sum[v];
            }
        }
    //    cout<<"sum = "<<u<< " "<<sum[u]<<endl;
    }
    int dfs2(int u,int p){

      //  cout<<u<<" 2 "<<p<<endl;
        for(auto v : G[u]){
            if(v!=p&&sum[v]>cnt/2)
                return dfs2(v,u);
        }
        return u;
    }
    void dfs3(int u,int par,int add,int sum){
        dist[sum]+=add;
        for(auto v : G[u])
            if(v!=par)
                dfs3(v,u,add,sum+1);
    }
    ll dfs4(int u,int par,int sum){
        ll ret=0;
        for(auto p:prime){
            if(p<sum)continue;
            if(!dist[p-sum])break;
            if(p!=sum)
                ret+=dist[p-sum];
            else
                ret+=2*dist[p-sum];
          //      cout<<"a7a "<<u<<" "<<p<<" "<<sum<<" "<<dist[p-sum]<<endl;
         }
        for(auto v : G[u])
            if(par!=v){
                ret+=dfs4(v,u,sum+1);
            }
        return ret;
    }
    void decompose(int root,int p){
        cnt=0;
        dfs1(root,root);
        int cen=dfs2(root,root);
        dfs3(cen,cen,1,0);
        ll sum2=0;
        for(auto v:G[cen]){
                if(v==p)
                    continue;
            dfs3(v,cen,-1,1);
            sum2+=dfs4(v,cen,1);
            dfs3(v,cen,1,1);
        //    cout<<v<<" "<<sum2<<endl;
        }
        ans+=sum2/2;
     //   cout<<ans<<" "<<cen<<" "<<sum2<<" "<<endl;
        if(p==-1)
            p=cen;
        par[cen]=p;
//        cout<<cen<<" "<<par[cen]<<endl;
        for(auto v:G[cen]){
            memset(dist,0,sizeof dist);
            G[v].erase(cen);
            decompose(v,cen);
        }
    }
    void buildCenTree(){
        sum.resize(N);
        par.resize(N);
        decompose(0,-1);
    }
};


int main()
{
    sieve();
    ll n;
    scanf("%lld",&n);
    TreeCentroid TC(n,19);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        TC.add_edge(a,b);
    }
    TC.buildCenTree();
   // cout<<TC.ans<<endl;
   double v=((n*(n-1))/2.0);
   v=ans/v;
    cout<<fixed<<setprecision(9)<<v<<endl;

}
