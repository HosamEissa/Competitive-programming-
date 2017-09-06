/*
 * SPOJ_SUB_PROB.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: Hossam Eissa
 *      Idea: use aho crosik to check if string match or not
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;

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
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	string s;
	cin >> s;
	int n;
	cin>>n;
	vector<string>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	AC_FSM AC;
	AC.construct_automaton(v);
	vector<vector<int>>ans;
	AC.aho_corasick(s,v,ans);
	for(int i=0;i<n;i++){
		if(ans[i].size()){
			cout<<"Y"<<endl;
		}
		else cout<<"N"<<endl;
	}
	return 0;
}
