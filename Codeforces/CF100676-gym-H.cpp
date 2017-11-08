/*
*
*
*
*   Author: Hossam Eissa
*   Bridges and articulation points tarjan
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
vector<int> adj[N];
vector<pair<int,int > > adjComp[N];

int n, DFSN[N], LOW[N], id, root, rootCalls,Comp[N],valcomp[N],par[N];
ll vis[N];
void init()
{
    for(int i=0; i<N; i++)
        adj[i].clear(),adjComp[i].clear();
    id = -1;
    memset(DFSN, -1, sizeof DFSN);
    memset(LOW, 0, sizeof LOW);
    memset(valcomp, -1, sizeof LOW);
    fill(Comp,Comp+N,1e9);
}
void Tarjan(int u, int p = -1)
{
    DFSN[u] = LOW[u] = ++id;
    for(int v: adj[u])
    {
        if(DFSN[v]==-1)
        {
            Tarjan(v, u);
            rootCalls += u == root;
            LOW[u] = min(LOW[u], LOW[v]);

        }
        else if(p != v)
            LOW[u] = min(LOW[u], DFSN[v]);

    }
}
pair<int,int>bfs(int st)
{
    queue<int>q;
    memset(vis,-1,sizeof vis);
    vis[st]=0;
    q.push(st);
    pair<int,int>ret={-1,-1};
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ret=max(ret,{vis[u],u});
        for(auto xx : adjComp[u])
        {
            int v=xx.first;
            if(vis[v]==-1)
            {
                vis[v]=vis[u]+xx.second;
                q.push(v);
            }
        }
    }
    return ret;
}
int sparse[N][19],lvl[N];
ll cost[N][19];
void dfs(int u)
{

    for(auto xx : adjComp[u])
    {
        int v=xx.first;
        if(vis[v])continue;
        vis[v]=1;
        lvl[v]=lvl[u]+1;
        par[v]=u;
        cost[v][0]=xx.second;
        dfs(v);
    }
}
void buildSparse(int n)
{
    memset(sparse,-1,sizeof sparse);
    //memset(cost,0,sizeof cost);

    for(int i=0; i<n; i++)
        sparse[i][0]=par[i];
    for(int i=1; i<18; i++)
    {
        for(int j=0; j<n; j++)
        {
            int tmp=sparse[j][i-1];
            if(tmp!=-1)
                sparse[j][i]=sparse[tmp][i-1],cost[j][i]=cost[j][i-1]+cost[tmp][i-1];
        }
    }
}
pair<int,ll> getPth(int v,int p)
{
    pair<int,int>ret;
    for(int i=0; v!=-1&&i<18; i++)
    {
        if(p&(1<<i))
        {
            ret.second+=cost[v][i];
            v=sparse[v][i];
        }
    }
    ret.first=v;
    return ret;
}
ll getCost(int u,int v)
{
    if(lvl[u]>lvl[v])
        swap(u,v);
   // cout<<u<<" "<<v<<" "<<lvl[u]<<" "<<lvl[v]<<endl;
    int p=lvl[v]-lvl[u];
    pair<int,ll>ret=getPth(v,p);
    v=ret.first;
    //cout<<"a7a "<<ret.first<<" "<<ret.second<<endl;
    if(v==u)return ret.second;
    //cout<<"u = "<<u<<" v = "<<v<<endl;
    for(int i=17; i>=0; i--)
    {
        //cout<<" i = "<<i<<" "<<sparse[u][i]<<" "<<sparse[v][i]<<endl;
        if(sparse[u][i]!=sparse[v][i])
        {
            ret.second+=cost[u][i];
            ret.second+=cost[v][i];
            u=sparse[u][i];
            v=sparse[v][i];
        }
    }
      //  cout<<"a7a2 "<<ret.first<<" "<<ret.second<<endl;
    ret.second+=cost[u][0];
    ret.second+=cost[v][0];
    return ret.second;
}
int getF(int i){
    if(DFSN[i]==LOW[i])
        return DFSN[i];
    return LOW[i]=getF(LOW[i]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        int n,m;
        scanf("%d%d",&n,&m);
        vector<pair<int,pair<int,int > > > edges;
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.push_back({a,{b,c}});
        }
        for(int i=0; i<n; i++)
        {
            if(DFSN[i]==-1)
            {
                root = i;
                rootCalls = 0;
                Tarjan(i);
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
          //  cout<<i<<" "<<LOW[i]<<endl;
            int val=getF(i);
            if(valcomp[val]==-1)
            {
                valcomp[val]=cnt;
                Comp[cnt]=i;
                cnt++;
            }
            else
            {
                Comp[valcomp[val]]=min(Comp[valcomp[val]],i);
            }
        }
        for(int i=0; i<m; i++)
        {
            int a=edges[i].first;
            int b=edges[i].second.first;
            int c=edges[i].second.second;
            int c1=valcomp[LOW[a]];
            int c2=valcomp[LOW[b]];
            if(c1!=c2)
            {
               // cout<<c1<<" "<<c2<<" "<<c<<endl;
                adjComp[c1].push_back({c2,c});
                adjComp[c2].push_back({c1,c});
            }
        }
       // cout<<"a7a"<<endl;
        memset(par,0,sizeof par);
        memset(cost,0,sizeof cost);
        memset(vis,0,sizeof vis);
        vis[0]=1;
        dfs(0);
        buildSparse(cnt);
        if(cnt==1)
        {
            printf("1 0\n");
        }
        else
        {
            pair<int,int> p=bfs(0);
            int st=p.second;
            p=bfs(st);
            int en=p.second;
            pair<ll,int>ans={p.first,min(Comp[st],Comp[en])};

            for(int i=0;i<cnt;i++){
                    ll c=getCost(i,st);
                    pair<ll,int>p={c,i};
                    p.first=max(p.first,getCost(i,en));

                    ans=min(ans,p);
            }
            cout<<Comp[ans.second]+1<<" "<<ans.first<<endl;

        }

    }
}
