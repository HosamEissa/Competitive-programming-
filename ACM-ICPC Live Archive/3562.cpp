#include <bits/stdc++.h>
using namespace std;
const int mxN = 150;
const int inf = 1000000010;
struct Edge {
    int to, cost, cap, flow, backEdge;
};
struct MCMF {
    int s, t, n;
    vector<Edge> g[mxN];
    MCMF(int _s, int _t, int _n) {
        s = _s, t = _t, n = _n;
    }
    void addEdge(int u, int v, int cost, int cap) {
     //   cout<<"adding2 "<<u<< " " <<v<<" "<<cost<<" "<<cap<<endl;
        Edge e1 = { v, cost, cap, 0, g[v].size() };
        Edge e2 = { u, -cost, 0, 0, g[u].size() };
        g[u].push_back(e1); g[v].push_back(e2);
    }
    pair<int, int> minCostMaxFlow() {
        int flow = 0, cost = 0;
        vector<int> state(n), from(n), from_edge(n), d(n);
        deque<int> q;
        while (true) {
            for (int i = 0; i < n; i++)
                state[i] = 2, d[i] = inf, from[i] = -1;
            state[s] = 1; q.clear(); q.push_back(s); d[s] = 0;
            while (!q.empty()) {
                int v = q.front(); q.pop_front(); state[v] = 0;
                for (int i = 0; i < (int) g[v].size(); i++) {
                    Edge e = g[v][i];
                    if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
                        continue;
                    int to = e.to; d[to] = d[v] + e.cost;
                    from[to] = v; from_edge[to] = i;
                    if (state[to] == 1) continue;
                    if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
                        q.push_front(to);
                    else q.push_back(to);
                    state[to] = 1;
                }
            }
            if (d[t] == inf) break;
            int it = t, addflow = inf;
            while (it != s) {
                addflow = min(addflow,
                        g[from[it]][from_edge[it]].cap
                        - g[from[it]][from_edge[it]].flow);
                it = from[it];
            }
            it = t;
            while (it != s) {
                g[from[it]][from_edge[it]].flow += addflow;
                g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
                cost += g[from[it]][from_edge[it]].cost * addflow;
           //     cout<<it<<" "<<g[from[it]][from_edge[it]].cost<<" "<<g[from[it]][from_edge[it]].cost * addflow<<endl;
                it = from[it];
            }
          //  cout<<"\nnew cycle"<<" "<<addflow<<" "<<cost <<endl;
            flow += addflow;
        }
        return {cost,flow};
    }
};

int main(){

    int P, I;
    int t=1;
    cout<<fixed<<setprecision(2);
    while(scanf("%d %d", &P , &I)==2&&(P|I)){
            int src=P+I+1,dst=src+1;
            //cout<<"src "<<src<<" dst "<<dst<<endl;
            MCMF mc(src,dst,dst+1);
            MCMF mc2(src,dst,dst+1);
            vector<int>PIE(P),ICE(I);
            for(int i = 0 ; i < P ; i++){
                int a;
                scanf("%d", &a);
                PIE[i] =  a;
            //    cout<<"add "<<src <<" "<<i<<" "<<a<<endl;
                mc.addEdge(src,i,0,a);
                mc2.addEdge(src,i,0,a);
            }
            for(int i = 0 ; i < I ; i++){
                int a;
                scanf("%d", &a);
                ICE[i] = a;

                mc.addEdge(i+P,dst,0,a);
                mc2.addEdge(i+P,dst,0,a);
            //    cout<<"add "<<i+P <<" "<<dst<<" "<<a<<endl;
            }

            for(int i = 0 ; i < P ;i++){
                for(int j = 0 ; j < I; j++ ){
                    double x;
                    cin>>x;
                    if(x == -1)
                        continue;
                    int c=ceilf(x * 100) ;  ;
                 ///   cout<<i<<" "<<j<<" "<<c<<endl;
                    mc.addEdge(i,P+j,c,inf);
                    mc2.addEdge(i,P+j,-c,inf);
                }
            }
            pair<int,int>px=mc.minCostMaxFlow();
            pair<int,int>px2=mc2.minCostMaxFlow();
           cout<<"Problem "<<t++<<": "<<px.first/100.0<<" to "<<fabs(px2.first)/100.0<<endl;
        //system("pause");
    }
}
