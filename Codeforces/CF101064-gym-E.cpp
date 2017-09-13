/*
 * CF101064-gym-E.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Hossam Eissa
 *      Idea:use aho crosik and put all the strings in it the bfs on the ahocrosik with mask indicate strings you have now and if you reach good string stop
 *            if you get all the bad string out put the answer
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
#define mk(a,b) make_pair(a,b)

int n, m;
struct AC_FSM {
#define ALPHABET_SIZE 10
	int vis[301][int(1 << 15)];
	int par[301][int(1 << 15)];
	int par2[301][int(1 << 15)];
	int par3[301][int(1 << 15)];
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
		for (int k = 0; k < 10; ++k) {
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

	int solve() {
		queue<pair<int, pair<int, int> > > q;
		q.push(mk(0, mk(0,0)));
		par[0][0] = -1;
		par2[0][0] = -1;
		par3[0][0] = -1;
		vis[0][0] = 1;
		while (!q.empty()) {
			int r = q.front().first;
			int msk = q.front().second.first;
			int len = q.front().second.second;
			q.pop();
			//cerr << r << " " << msk << " " << len << endl;
			if (msk == (1 << n) - 1) {
				string s;
				while (par[r][msk] != -1) {
					/*cerr << r << " " << msk << " " << char(par3[r][msk])
					 << endl;*/
					s += par3[r][msk];
					int r2 = r;
					r = par[r2][msk];
					msk = par2[r2][msk];
				}
				reverse(s.begin(), s.end());
				cout << s << endl;
				return 1;
			}
			for (int k = 0, arck; k < ALPHABET_SIZE; ++k) {
				if ((arck = a[r].child[k]) != -1) {
					int nmsk = msk | a[arck].mat;
					if (!vis[arck][nmsk] && nmsk < (1 << n)) {
						/*cerr << "node " << r << " to " << arck << " char "
						 << char(k + 'a') << " " << nmsk << endl;*/
						par[arck][nmsk] = r;
						par2[arck][nmsk] = msk;
						par3[arck][nmsk] = k + 'a';
						vis[arck][nmsk] = 1;
						q.push(mk(arck, mk(nmsk,len+1)));
					}

				} else {
					int nmsk = msk;
					int v = a[r].fin[k];
					nmsk |= a[v].mat;
					if (!vis[v][nmsk] && nmsk < (1 << n)) {
						/*		cerr << "opt node " << r << " to " << v << " char "
						 << char(k + 'a') << endl;*/
						par[v][nmsk] = r;
						par2[v][nmsk] = msk;
						par3[v][nmsk] = k + 'a';
						vis[v][nmsk] = 1;
						q.push(mk(v, mk(nmsk,len+1)));
					}
				}
			}
		}
		return -1;
	}
	void aho_corasick(string &sentence, vector<string> &words,
			vector<vector<int> > &matches) {
		matches.assign(words.size(), vector<int>());
		int state = 0, ss = 0;
		for (int i = 0; i < sentence.length(); ++i, ss = state) {
			while (a[ss].child[sentence[i]] == -1)
				ss = a[ss].failure;
			state = a[state].child[sentence[i]] = a[ss].child[sentence[i]];
			for (ss = state; ss != -1; ss = a[ss].match_parent)
				for (int w : a[ss].match)
					matches[w].push_back(i + 1 - words[w].length());
		}
	}
}
;
AC_FSM aho;

int main() {
	cin >> n >> m;
	vector<string> v(n + m);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int j = 0; j < m; j++)
		cin >> v[n + j];
	aho.construct_automaton(v);
	if (aho.solve() == -1)
		cout << "-" << endl;
	return 0;
}
