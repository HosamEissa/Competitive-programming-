/*
 * CODECHEF_LYRC.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Hossam Eissa
 *      Idea: use aho crosik to find the words in the strings but normal aho crosik will get TLE so store only how many time each node is visited
 *            then give the value to it's failures the count the answers
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mk(a,b) make_pair(a,b)
const int N = 1e5;
const double eps = 1e-9;
vector<int> val;
vector<vector<int>> level;
struct AC_FSM {
#define ALPHABET_SIZE 256
	struct Node {
		int child[ALPHABET_SIZE], failure = 0, match_parent = -1;
		vector<int> match;
		Node() {
			for (int i = 0; i < ALPHABET_SIZE; ++i)
				child[i] = -1;
		}
	};
	vector<Node> a;
	AC_FSM() {
		a.push_back(Node());
	}
	void construct_automaton(vector<string> &words) {
		for (int w = 0, n = 0; w < words.size(); ++w, n = 0) {
			for (int i = 0; i < words[w].size(); ++i) {
				if (a[n].child[words[w][i]] == -1) {
					a[n].child[words[w][i]] = a.size();
					a.push_back(Node());
				}
				n = a[n].child[words[w][i]];
			}
			a[n].match.push_back(w);
		}
		level.resize(5005);
		queue<pair<int, int>> q;
		for (int k = 0; k < ALPHABET_SIZE; ++k) {
			if (a[0].child[k] == -1)
				a[0].child[k] = 0;
			else if (a[0].child[k] > 0) {
				a[a[0].child[k]].failure = 0;
				q.push(mk(a[0].child[k], 1));
			}
		}
		while (!q.empty()) {
			int r = q.front().first;
			int lvl = q.front().second;
			q.pop();
			level[lvl].push_back(r);
			for (int k = 0, arck; k < ALPHABET_SIZE; ++k) {
				if ((arck = a[r].child[k]) != -1) {
					q.push(mk(arck, lvl + 1));
					int v = a[r].failure;
					while (a[v].child[k] == -1)
						v = a[v].failure;
					a[arck].failure = a[v].child[k];
					a[arck].match_parent = a[v].child[k];
					while (a[arck].match_parent != -1
							&& a[a[arck].match_parent].match.empty())
						a[arck].match_parent =
								a[a[arck].match_parent].match_parent;
				}
			}
		}
	}
	void aho_corasick(string &sentence, vector<string> &words,
			vector<int>&matches) {
		matches.resize(a.size());
		int state = 0, ss = 0;
		for (int i = 0; i < sentence.length(); ++i, ss = state) {
			while (a[ss].child[sentence[i]] == -1)
				ss = a[ss].failure;
			state = a[state].child[sentence[i]] = a[ss].child[sentence[i]];
		//	cerr << state << " " << matches[state] << endl;
			matches[state]++;
		}
	}
	void solve(vector<int>&ans) {
		for (int i = level.size() - 1; i >= 0; i--) {
			for (auto j : level[i]) {
				val[a[j].failure] += val[j];
			}
		}
		for (int i = 0; i < val.size(); i++) {
			if (a[i].match.size())
				for (auto u : a[i].match)
					ans[u] += val[i];
		}
	}
}
;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	AC_FSM aho;
	aho.construct_automaton(v);
	string s;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		s += tmp;
		s += ' ';
	}
	//cerr << s << endl;
	s.pop_back();
	/*for (int i = 0; i < s.size(); i++)
	 if (s[i] == '-')
	 s[i] = ' ';*/
	vector<int> match;
	aho.aho_corasick(s, v, match);
	val = match;
	vector<int> ans(v.size());
	aho.solve(ans);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
