/*
 * SPOJ_BOTTOM.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Hossam Eissa
 *      Idea: build SCC and swap the graph with component graph and if any component have outDegree = 0 print all the nodes in it
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps = 1e-9;
const int N = 5000 + 5;

vector<int> adj[N], comp[N], adjComp[N];
int n, DFSN[N], LOW[N], inStack[N], id, f[N], cnt, inDeg[N], outDeg[N];
stack<int> st;

void init() {
	for (int i = 0; i < N; i++) {
		comp[i].clear();
		adj[i].clear();
		adjComp[i].clear();
	}
	cnt = id = 0;
	memset(inDeg, 0, sizeof inDeg);
	memset(outDeg, 0, sizeof outDeg);
	memset(DFSN, 0, sizeof DFSN);
	memset(LOW, 0, sizeof LOW);
}

void Extract(int u) {
	int node = -1;
	while (node != u) {
		node = st.top();
		st.pop();
		comp[cnt].push_back(node);
		f[node] = cnt;
		inStack[node] = 0;
	}
	++cnt;
}

void Tarjan(int u) {
	DFSN[u] = LOW[u] = ++id;
	inStack[u] = 1;
	st.push(u);
	for (int v : adj[u]) {
		if (!DFSN[v]) {
			Tarjan(v);
			LOW[u] = min(LOW[u], LOW[v]);
		} else if (inStack[v]) {
			LOW[u] = min(LOW[u], DFSN[v]);
		}
	}
	if (LOW[u] == DFSN[u])
		Extract(u);
}

int T, m;
int main() {
	int n, m;
	while (scanf("%d", &n) && n) {
		init();
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (!DFSN[i]) {
				Tarjan(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (auto v : adj[i]) {
				int cu = f[i];
				int cv = f[v];
				if (cu == cv)
					continue;
				adjComp[cu].push_back(cv);
				++inDeg[cv];
				++outDeg[cu];
			}
		}

		vector<int>ans;
		for (int i = 0; i < cnt; i++) {
			if(!outDeg[i]){
				for(auto v:comp[i]){
					ans.push_back(v);
				}
			}
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
		}
	}
	return 0;
}

