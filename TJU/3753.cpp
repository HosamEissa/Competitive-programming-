/*
 * TJU_3753.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: Hossam Eissa
 *      Idea: use trie to store words and variable childs to count how many childs you have in this node
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
const double eps=1e-9;
struct Trie {
#define sz 256
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
	void insert(string s) {
		int idx = 0;
		a[idx].childs++;
		for (int i = 0; i < s.size(); i++) {
			if (a[idx].child[s[i]] == -1)
				a[idx].child[s[i]] = a.size(), a.push_back(node());
			idx = a[idx].child[s[i]];
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

};
int main() {
	/*ios::sync_with_stdio(false);
	 cin.tie();
	 cout.tie();*/
	int n, m;
	while (cin >> n >> m) {
		Trie t;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			t.insert(s);
		}
		ll ans = 0;
		while (m--) {
			string s;
			int k;
			cin >> k;
			for (int i = 0; i < k; i++) {
				vector<double> v, v2;
				for (int j = 0; j < 8; j++) {
					double a;
					cin >> a;
					v.push_back(a);
				}
				v2 = v;
				sort(v2.begin(), v2.end());
				double mn = v2[0], mx = v2[7];
				mn=(mn+mx)/2;
				int val=0;
				for (int j = 0; j < 8; j++) {
					if(v[j]>mn){
						val |= (1 << (7 - j));
					}
				}
				s += char(val);
			}
//		cout<<s<<endl;
			ans += t.find(s);

		}
		printf("%lld\n", ans);
	}

	return 0;
}
