/*
 * SRM519-D1-500.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Hossam Eissa
 *      Idea: build ahocrosik from the strings and dp[node][len][mask] to get the answer of the problem
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
#define mk(a,b) make_pair(a,b)

int n, l, c;
int dp[305][305][64];
const int MOD = 1e9 + 9;
struct AC_FSM {
#define ALPHABET_SIZE 26
	struct Node {
		int child[ALPHABET_SIZE], failure = 0, match_parent = -1, mat = 0;
		int fin[ALPHABET_SIZE];
		vector<int> match;
		Node() {
			for (int i = 0; i < ALPHABET_SIZE; ++i)
				child[i] = -1, fin[i] = -1;
		}
	};
	vector<Node> a;
	AC_FSM() {
		a.push_back(Node());
	}
	void construct_automaton(vector<string> &words) {
		for (int w = 0, n = 0; w < words.size(); ++w, n = 0) {
			//	cerr << "adding " << w << endl;
			for (int i = 0; i < words[w].size(); ++i) {
				if (a[n].child[words[w][i] - 'a'] == -1) {
					a[n].child[words[w][i] - 'a'] = a.size();
					a.push_back(Node());
				}
				//	cerr << n << " ";
				n = a[n].child[words[w][i] - 'a'];
			}
			//	cerr << n << endl;
			a[n].match.push_back(w);
			a[n].mat |= (1 << w);
		}
		queue<int> q;
		for (int k = 0; k < ALPHABET_SIZE; ++k) {
			if (a[0].child[k] == -1)
				a[0].child[k] = 0;
			else if (a[0].child[k] > 0) {
				a[a[0].child[k]].failure = 0;
				q.push(a[0].child[k]);
			}
		}
		while (!q.empty()) {
			int r = q.front();
			q.pop();
			for (int k = 0, arck; k < ALPHABET_SIZE; ++k) {
				if ((arck = a[r].child[k]) != -1) {
					q.push(arck);
					int v = a[r].failure;
					while (a[v].child[k] == -1)
						v = a[v].failure;
					v = a[v].child[k];
					a[arck].failure = v;
					a[arck].match_parent = v;
					a[arck].mat |= a[v].mat;
					/*cerr << arck << " " << a[arck].failure << " " << a[arck].mat
					 << endl;*/
				}
				a[r].fin[k] = 0;
				int u = r;
				while (1) {
					if (a[u].child[k] != -1) {
						a[r].fin[k] = a[u].child[k];
						break;
					}
					if (u == 0)
						continue;
					u = a[u].failure;
				}
				//cerr << r << " " << char(k + 'a') << " " << a[r].fin[k] << endl;
			}

		}
	}

	int solve(int u, int len, int msk) {
		if (len == l) {
			int cnt = __builtin_popcount(msk);
			return cnt == c;
		}
		int ans = 0;
		if (dp[u][len][msk] != -1)
			return dp[u][len][msk];
		for (int k = 0, arck; k < ALPHABET_SIZE; ++k) {
			if ((arck = a[u].child[k]) != -1) {

				ans += solve(arck, len + 1, msk | a[arck].mat);
				ans %= MOD;
			} else {
				int v = a[u].fin[k];
				ans += solve(v, len + 1, msk | a[v].mat);
				ans %= MOD;
			}
		}
		return dp[u][len][msk] = ans;
	}

} aho;
class RequiredSubstrings {
public:
	int solve(vector<string> words, int C, int L) {
		aho.construct_automaton(words);
		c = C;
		l = L;
		memset(dp, -1, sizeof dp);
		return aho.solve(0, 0, 0);
	}
};
