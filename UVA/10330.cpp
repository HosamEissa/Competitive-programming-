/*
Author: Hossam Eissa
Idea:make dummy sorce and dist and split each vertex into 2 and do maxflow
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;

struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) { }
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) { }

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if(from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *)NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while(head < tail)
        {
            int x = Q[head++];
            for(int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if(!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if(!dad[t]) return 0;

        long long totflow = 0;
        for(int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if(!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if(amt == 0) continue;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t)
    {
        long long totflow = 0;
        while(long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};
const int N=101;
int arr[N];
int main()
{
    int n;
    while(cin>>n){
    for(int i=0;i<n;i++)cin>>arr[i];
    Dinic d(2*n+2);
    int src=2*n;
    int dst=src+1;
    int m;
    cin>>m;
    for(int i=0;i<n;i++){
        d.AddEdge(i,i+n,arr[i]);
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        d.AddEdge(a+n,b,c);
    }
    int x,y;
    cin>>x>>y;
    while(x--){
        int a;
        cin>>a;
        a--;
        d.AddEdge(src,a,INF);
    }

    while(y--){
        int a;
        cin>>a;
        a--;
        d.AddEdge(a+n,dst,INF);
    }
    cout<<d.GetMaxFlow(src,dst)<<endl;
    }
    return 0;
}
