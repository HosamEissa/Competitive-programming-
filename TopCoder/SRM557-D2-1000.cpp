/*
 * SRM557-D2-1000.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Hossam Eissa
 *      Idea: build ahocrosik from the strings and dp[node][len][summtion][found] to get the answer of the problem
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
//const int N = 1e5;
const double eps = 1e-9;
const int MOD = 1e9 + 9;
int N;
int dp[100][100][100][2];
struct AC_FSM {
#define ALPHABET_SIZE 2
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
	void construct_automaton(vector<int> words) {
		int w = 0, n = 0;
		for (int i = 0; i < words.size(); ++i) {
			if (a[n].child[words[i]] == -1) {
				a[n].child[words[i]] = a.size();
				a.push_back(Node());
			}
			//	cerr << n << " ";
			n = a[n].child[words[i]];
		}
		//	cerr << n << endl;
		a[n].match.push_back(w);
		a[n].mat |= (1 << w);

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

	int solve(int u, int len, int sum, bool msk) {
		//cerr << u << " " << len << " " << sum << " " << msk << endl;
		if (len == N) {
			return ((sum == 0) && msk);
		}
		if (sum < 0)
			return 0;
		//	cerr << "N = " << N << endl;
		if (dp[u][len][sum][msk] != -1)
			return dp[u][len][sum][msk];
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			int c = 1;
			if (i == 0)
				c = -1;
			if (a[u].child[i] != -1) {
				int nu = a[u].child[i];
				int nmsk = msk | a[nu].mat;
				ans += solve(nu, len + 1, sum + c, nmsk);
				ans %= MOD;
			} else {
				int nu = a[u].fin[i];
				int nmsk = msk | a[nu].mat;
				ans += solve(nu, len + 1, sum + c, nmsk);
				ans %= MOD;
			}
		}
		return dp[u][len][sum][msk] = ans;
	}

} aho;
class FoxAndMountain {
public:
	int count(int n, string history) {
		vector<int> v;
		N = n;
		for (int i = 0; i < history.size(); i++) {
			if (history[i] == 'U')
				v.push_back(1);
			else
				v.push_back(0);
		}
		memset(dp, -1, sizeof dp);
		aho.construct_automaton(v);
		return aho.solve(0, 0, 0, 0);
	}
};
int main() {
	FoxAndMountain F;
	cout << F.count(20, "UUUDUUU") << endl;
	return 0;
}
