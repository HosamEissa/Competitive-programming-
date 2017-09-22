/*
 * UVA_12244.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Hossam Eissa
 *      Idea: put all the strings in ahocrosik and for each node the answer = max between parent and the failure node
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 6;
const double eps = 1e-9;
#define mk(a,b) make_pair(a,b)
struct AC_FSM {
#define ALPHABET_SIZE 26
	struct Node {
		int child[ALPHABET_SIZE], failure = 0, match_parent = -1, mat = 0;
		int fin[ALPHABET_SIZE];
		int presum;
		vector<int> match;
		Node() {
			presum = 0;
			for (int i = 0; i < ALPHABET_SIZE; ++i)
				child[i] = -1, fin[i] = -1;
		}
	};
	vector<Node> a;
	AC_FSM() {
		a.push_back(Node());
	}

	int construct_automaton(vector<string> &words) {
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
			a[n].mat = 1;
			a[n].presum = 1;
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
		int ans = 0;
		while (!q.empty()) {
			int r = q.front();
			q.pop();
			ans = max(ans, a[r].presum);
		//	cerr << ans << " " << a[r].presum << " " << r << endl;
			for (int k = 0, arck; k < ALPHABET_SIZE; ++k) {
				if ((arck = a[r].child[k]) != -1) {
					q.push(arck);
					int v = a[r].failure;
					while (a[v].child[k] == -1)
						v = a[v].failure;
					v = a[v].child[k];
					a[arck].failure = v;
					a[arck].match_parent = v;
					//a[arck].mat |= a[v].mat;
					/*cerr << arck << " " << a[arck].failure << " " << a[arck].mat
					 << endl;*/
					a[arck].presum = max(a[r].presum, a[a[arck].failure].presum)
							+ a[arck].mat;
		//			cerr << arck << " failure " << a[arck].failure << endl;
				}

				//cerr << r << " " << char(k + 'a') << " " << a[r].fin[k] << endl;
			}
		}
		return ans;
	}

};
int main() {
	int n;
	while (cin >> n && n) {
		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		//	cerr << "done" << endl;
		AC_FSM aho;
		cout << aho.construct_automaton(v) << endl;
	}

	return 0;
}
