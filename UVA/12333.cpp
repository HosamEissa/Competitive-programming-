/*
 * UVA_12333.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Hossam Eissa
 *      Idea: do a big number class and store for each fib number only the first digits and store them in trie to get the answer
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
struct Trie {
#define sz 10
	struct node {
		int child[sz];
		int childs, index;
		node() {
			childs = 0;
			index = 1e8;
			for (int i = 0; i < sz; i++)
				child[i] = -1;
		}
	};
	vector<node> a;
	Trie() {
		a.push_back(node());
	}
	void insert(vector<int> &s, int ind) {
		int idx = 0;
		a[idx].index = min(a[idx].index, ind);
		for (int i = 0; i < s.size(); i++) {
			if (a[idx].child[s[i]] == -1)
				a[idx].child[s[i]] = a.size(), a.push_back(node());
			idx = a[idx].child[s[i]];
			a[idx].index = min(a[idx].index, ind);
		}
		return;
	}
	int find(vector<int> &s) {
		int idx = 0;
		for (int i = 0; i < s.size(); i++) {
			if (a[idx].child[s[i]] == -1)
				return -1;
			idx = a[idx].child[s[i]];
		}
		return a[idx].index;
	}

} T;
void rev(vector<int> &s) {
	reverse(s.begin(), s.end());
}
void getsum(vector<int> &v1, vector<int>&v2, vector<int> &v3) {
	v3 = v2;
	int c = 0;

	int i;
	for (i = 0; i < v1.size(); i++) {
		v3[i] = (v2[i] + v1[i] + c) % 10;
		c = (v2[i] + v1[i] + c) / 10;
	}
	if (c) {
		if (i < v3.size())
			v3[i] += c;
		else
			v3.push_back(c);
	}
	//rev(v3);

}
int main() {
	vector<int> a = { 1 };
	vector<int> b = { 1 };
	vector<int> c;
	T.insert(a, 0);
	T.insert(b, 1);
	for (int i = 2; i < 100000; i++) {
		getsum(a, b, c);
		vector<int> tmp = c;
		rev(tmp);
		T.insert(tmp, i);
		a = b;
		b = c;
		/*cerr << "Vec =" << i << endl;
		 for (int j = 0; j < tmp.size(); j++)
		 cerr << c[j];
		 cerr << endl;*/
		while (b.size() > 50) {
			int x = b.size() - 50;
			a.erase(a.begin(), a.begin() + x);
			b.erase(b.begin(), b.begin() + x);
		}
	}

	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		string s;
		cin >> s;
		vector<int> v;
		for (int i = 0; i < s.size(); i++)
			v.push_back(s[i] - '0');
		printf("Case #%d: %d\n", tc, T.find(v));
	}
	return 0;
}
