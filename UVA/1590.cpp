/*
 * UVA_1590.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: Hossam Eissa
 *      Idea: use trie to get the commen prefix of all the strings
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
string get2(string tmp) {
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '.')
			tmp[i] = ' ';
	}
	stringstream ss;
	string ret;
	int tmps;
	ss << tmp;
	while (ss >> tmps) {
		//cerr << tmp << " " << tmps << endl;
		for (int i = 7; i >= 0; i--)
			ret += char(((tmps >> i) & 1) + '0');
	}
	return ret;
}
struct Trie {
#define alphabit 2
	struct node {
		int child[alphabit];
		node() {
			for (int i = 0; i < alphabit; i++)
				child[i] = -1;
		}
	};
	vector<node> a;
	Trie() {
		a.push_back(node());
	}
	void insert(string &s) {
		int idx = 0;
		for (int i = 0; i < s.size(); i++) {
			if (a[idx].child[s[i] - '0'] == -1)
				a[idx].child[s[i] - '0'] = a.size(), a.push_back(node());
			idx = a[idx].child[s[i] - '0'];
		}
	}
	string find() {
		string ret;
		int idx = 0;
		while (1) {
			int cnt = 0, tmp;
			for (int i = 0; i < alphabit; i++) {
				if (a[idx].child[i] != -1)
					cnt++, tmp = i;
			}
			if (cnt != 1)
				break;
			ret += '0' + tmp;
			idx = a[idx].child[tmp];
		}
		return ret;
	}

};
int main() {
	int n;
	while (cin >> n) {
		Trie T;
		string mn;
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			//cerr << tmp << endl;
			tmp = get2(tmp);
			//cerr << tmp << endl;
			if (mn == "")
				mn = tmp;
			T.insert(tmp);
			mn = min(mn, tmp);
		}
		string ans = T.find();
		int sz = ans.size();
		//cerr << mn.size() << endl;
		for (int i = 0; i < 4; i++) {
			int val = 0;
			for (int j = 0; j < 8; j++) {
				val *= 2;
				if (i * 8 + j < sz && mn[i * 8 + j] == '1')
					val += 1;
			}
			cout << val << ".\n"[i == 3];
		}
		for (int i = 0; i < 4; i++) {
			int val = 0;
			for (int j = 0; j < 8; j++) {
				val *= 2;
				if (i * 8 + j < sz)
					val += 1;
			}
			cout << val << ".\n"[i == 3];
		}

	}

	return 0;
}
