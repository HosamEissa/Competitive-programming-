/*
 * SPOJ_CAPCITY.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Hossam Eissa
 *      Idea: build revearse graph and build component graph and if you have one connected component with one component with indegree 0 print answer
 */




#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps = 1e-9;
const int N = 100000 + 5;

vector<int> adj[N], comp[N], adjComp[N];
int n, DFSN[N], LOW[N], inStack[N], id, f[N], cnt, inDeg[N], outDeg[N], par[N],
		grp;
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
int find(int a) {
	if (a == par[a])
		return a;
	return par[a] = find(par[a]);
}
void connect(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	par[a] = b;
	grp--;
}
int T, m;
int main() {
		init();
		int n, m;
		scanf("%d%d", &n,&m);
		for (int i = 1; i <= m; i++) {
				int a,b;
				scanf("%d%d", &a,&b);
				adj[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!DFSN[i]) {
				Tarjan(i);
			}
		}
		for (int i = 0; i < cnt; i++)
			par[i] = i;
		grp = cnt;
		for (int i = 1; i <= n; i++) {
			for (auto v : adj[i]) {
				int cu = f[i];
				int cv = f[v];
				if (cu == cv)
					continue;
				connect(cu, cv);
				++inDeg[cv];
				++outDeg[cu];
			}
		}
		int ans = 0, c = 0;
		for (int i = 0; i < cnt; i++) {

			if (inDeg[i] == 0)
				ans = max(ans, (int) comp[i].size()), c++;
		}
		if (grp > 1 || c > 1)
			ans = 0;
		printf("%d\n", ans);
		if(ans)
		for(int i=1;i<=n;i++){
			if(inDeg[f[i]]==0){
				printf("%d%c",i," \n"[i==n]);
			}
		}
	return 0;
}
