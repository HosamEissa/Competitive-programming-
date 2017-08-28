/*
 * CF101484-GYM-F.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: Hossam Eissa
 *      Idea: since you are given complete binary tree you will have maximum tree of depth log(N)
 *            so preprocess the answer for each node in log(n) and answer qurry in o(1)
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 6;
const double eps = 1e-9;
vector<vector<int>> G(N);
int shi[N];
int n, m, w;
int lvl[N], ans[N], par[N], sum[N][18], total[N];
int mx = 0;
set<pair<int, int>> st;
set<pair<int, int>>::iterator it;
void dfs(int u, int l = 0, int p = -1) {
	lvl[u] = l;
	par[u] = p;
	mx = max(mx, l);
	for (auto v : G[u]) {
		dfs(v, l + 1, u);
	}
	total[lvl[u]] += shi[u];
	int idx = 0;
	int tmpu = u;
	while (u != -1) {
		sum[u][idx] += shi[tmpu];
		idx++;
		u = par[u];
	}
}
void solve(int u) {
	for (auto v : G[u]) {
		solve(v);
	}
	int mxv = 0;
	cerr << "node = " << u+1 << endl;
	for (int i = 0; lvl[u] + i <= mx; i++) {
		total[lvl[u] + i] -= sum[u][i];
	//	cerr<<"lvl "<<lvl[u]+i<<" total = "<<total[lvl[u]+i]<<" "<<sum[u][i]<<endl;
	}
	for (int i = 0; i <= mx; i++)
		mxv = max(mxv, total[i]);
	for (int i = 0; lvl[u] + i <= mx; i++) {
		total[lvl[u] + i] += sum[u][i];
	}
	ans[u] = mxv;
}
int main() {
	cin >> n >> m >> w;
	shi[0] = w;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		shi[a] = c;
		G[b].push_back(a);
	}
	dfs(0);
	/*for (int i = 0; i < n; i++) {
	 cerr << "node = " << i + 1 << endl;
	 for (int j = 0; j < 4; j++) {
	 cerr << "j = " << j << " sum = " << sum[i][j] << endl;
	 }
	 }*/
	solve(0);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		a--;
		printf("%d\n", ans[a]);
	}
	return 0;
}
