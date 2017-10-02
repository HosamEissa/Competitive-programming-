/*
 * UVA_12167.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Hossam Eissa
 *      Idea: build component graph and answer is maximum between count in ==0 and out ==0
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps = 1e-9;
const int N = 20000 + 5;

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
	cin >> T;
	while (T--) {
		init();
		int n, m;
		scanf("%d%d", &n, &m);
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
		int ans = 0,c=0,x=0;
		for (int i = 0; i < cnt; i++) {
			//cerr << i << " " << inDeg[i] << " " << outDeg[i] << endl;

			if (inDeg[i] == 0)
				c++;
			if (outDeg[i] == 0)
				x++;
		}
		if(cnt==1)c=0,x=0;
		printf("%d\n", max(c, x));
	}
	return 0;
}
