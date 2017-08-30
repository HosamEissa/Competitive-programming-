/*
 * Contest.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: Hossam Eissa
 *      Idea: build a graph with k nodes and the cost of edges between 2 nodes is there costs if they contigous
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
const double eps = 1e-9;
const int INF = 2000000000;

struct Edge {
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index) :
			from(from), to(to), cap(cap), flow(flow), index(index) {
	}
};

struct Dinic {
	int N;
	vector<vector<Edge> > G;
	vector<Edge *> dad;
	vector<int> Q;

	Dinic(int N) :
			N(N), G(N), dad(N), Q(N) {
	}

	void AddEdge(int from, int to, int cap) {
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to)
			G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	long long BlockingFlow(int s, int t) {
		fill(dad.begin(), dad.end(), (Edge *) NULL);
		dad[s] = &G[0][0] - 1;

		int head = 0, tail = 0;
		Q[tail++] = s;
		while (head < tail) {
			int x = Q[head++];
			for (int i = 0; i < G[x].size(); i++) {
				Edge &e = G[x][i];
				if (!dad[e.to] && e.cap - e.flow > 0) {
					dad[e.to] = &G[x][i];
					Q[tail++] = e.to;
				}
			}
		}
		if (!dad[t])
			return 0;

		long long totflow = 0;
		for (int i = 0; i < G[t].size(); i++) {
			Edge *start = &G[G[t][i].to][G[t][i].index];
			int amt = INF;
			for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
				if (!e) {
					amt = 0;
					break;
				}
				amt = min(amt, e->cap - e->flow);
			}
			if (amt == 0)
				continue;
			for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
				e->flow += amt;
				G[e->to][e->index].flow -= amt;
			}
			totflow += amt;
		}
		return totflow;
	}

	long long GetMaxFlow(int s, int t) {
		long long totflow = 0;
		while (long long flow = BlockingFlow(s, t))
			totflow += flow;
		return totflow;
	}
};
int arr[N], x[N], y[N];
int cost[N][N];
int main() {
	int k, a, b, n;
	cin >> k >> n >> a >> b;
	Dinic d(k + 2);

	ll ans = 0;
	int src = k, snk = src + 1;
	for (int i = 0; i < a; i++) {
		int sss;
		cin >> sss;
		sss--;
		x[sss] = 1;

	}
	for (int j = 0; j < b; j++) {
		int a;
		cin >> a;
		a--;
		y[a] = 1;
	}
	for (int i = 0; i < k; i++) {
		if (!x[i])
			d.AddEdge(src, i, INF);
		if (!y[i])
			d.AddEdge(i, snk, INF);
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		ans += a;
		cost[arr[i - 1]][arr[i]] += a;
		//cost[arr[i - 1]][arr[i] + k] += a;
	}
	cerr << ans << endl;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			if (i != j && cost[i][j]) {
				d.AddEdge(i, j, cost[i][j]);
				d.AddEdge(j, i, cost[i][j]);
			}
	cout << ans - d.GetMaxFlow(src, snk);
	return 0;
}
