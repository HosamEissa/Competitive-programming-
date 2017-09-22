/*
 * LIVEARCHIVE_5792.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Hossam Eissa
 *      Idea:add all the strings in two tries and dfs one of them to know how many char is repeted and dfs the other to get 
 *             the answer for each char take all the nodes in the other trie
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
struct Trie {
#define sz 26
	struct node {
		int child[sz];
		int childs;
		node() {
			childs = 0;
			for (int i = 0; i < sz; i++)
				child[i] = -1;
		}
	};
	vector<node> a;
	Trie() {
		a.push_back(node());
	}
	void clear() {
		a.clear();
		a.push_back(node());
	}
	void insert(string s) {
		int idx = 0;
		a[idx].childs++;
		for (int i = 0; i < s.size(); i++) {
			if (a[idx].child[s[i] - 'a'] == -1)
				a[idx].child[s[i] - 'a'] = a.size(), a.push_back(node());
			idx = a[idx].child[s[i] - 'a'];
			a[idx].childs++;
		}
	}
	int find(string s) {
		int idx = 0;
		for (int i = 0; i < s.size(); i++) {
			if (a[idx].child[s[i]] == -1)
				return 0;
			idx = a[idx].child[s[i]];
		}
		return a[idx].childs;
	}

} t1, t2;
int start[26];

void dfs1(int u, int dep) {

	for (int i = 0; i < 26; i++) {
		if ((t2.a[u].child[i]) == -1)
			continue;
		if (dep)
			start[i]++;
		dfs1(t2.a[u].child[i], dep + 1);
	}
}
ll dfs2(int u, int dep) {
	//cerr << u << " " << dep << endl;

	ll ans = 0;
	if (dep)
		ans += t2.a.size() - 1;
	for (int i = 0; i < 26; i++) {
		if ((t1.a[u].child[i]) == -1)
			continue;
		if (dep)
			ans -= start[i];
		ans += dfs2(t1.a[u].child[i], dep + 1);
	}
	return ans;
}
int main() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		memset(start, 0, sizeof start);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			t1.insert(s);
		}
		for (int i = 0; i < m; i++) {
			string s;
			cin >> s;
			reverse(s.begin(), s.end());
			t2.insert(s);
		}
		dfs1(0, 0);
		cout << dfs2(0, 0) << endl;
		t1.clear();
		t2.clear();
	}
	return 0;
}
