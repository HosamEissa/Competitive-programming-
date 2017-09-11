/*
 * SRM490-D1-500.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: Hossam Eissa
 *      Idea: use dp[idx] = best answer to write the suffix of the string starts at i
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
struct Trie2 {
#define sz 256
	struct node {
		int child[sz];
		int mnidx;
		int mxidx;
		node() {
			mnidx = 1e9;
			mxidx = -1;
			for (int i = 0; i < sz; i++)
				child[i] = -1;
		}
	};
	vector<node> a;
	Trie2() {
		a.push_back(node());
	}
	void insert(string s, int ind) {
		int idx = 0;
		a[idx].mnidx = min(ind, a[idx].mnidx);
		a[idx].mxidx = max(ind, a[idx].mxidx);
		for (int i = 0; i < s.size(); i++) {
			if (a[idx].child[s[i]] == -1)
				a[idx].child[s[i]] = a.size(), a.push_back(node());
			idx = a[idx].child[s[i]];
			a[idx].mnidx = min(ind, a[idx].mnidx);
			a[idx].mxidx = max(ind, a[idx].mxidx);
		}
	}
	int find(string s) {
		int idx = 0;
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (a[idx].child[s[i]] == -1)
				return -1;
			idx = a[idx].child[s[i]];
		}
		return a[idx].mnidx;
	}

};
class QuickT9 {
public:
	vector<string> v;
	Trie2 t2;
	string s;
	int dp[51];
	map<string, int> mp;
	string getdigs(string s) {
		string ret;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] <= 'c')
				ret += '2';
			else if (s[i] <= 'f')
				ret += '3';
			else if (s[i] <= 'i')
				ret += '4';

			else if (s[i] <= 'l')
				ret += '5';

			else if (s[i] <= 'o')
				ret += '6';

			else if (s[i] <= 's')
				ret += '7';

			else if (s[i] <= 'v')
				ret += '8';

			else if (s[i] <= 'z')
				ret += '9';

		}
		return ret;
	}
	int solve(int idx) {
		//cerr << "start " << idx << endl;
		if (idx == s.size())
			return 0;
		int ans = 1e9;
		if (dp[idx] != -1)
			return dp[idx];
		for (int i = idx; i < s.size(); i++) {
			string tmp = s.substr(idx, i - idx + 1);
			int tmpans = 1e9;
			int c = -1;
			if (mp.count(tmp)) {
				tmpans = mp[tmp];
			} else {
				for (int i = 0; i < v.size(); i++) {

					if (tmp == v[i].substr(0, tmp.size())) {
						//	cerr << tmp << " " << v[i] << endl;
						c = i;
						//break;
						for (int l = tmp.size(); l <= v[c].size(); l++) {
							string tmp2 = v[c].substr(0, l);
							set<string> st;
							for (int i = 0; i < v.size(); i++) {
								string tmp3 = v[i].substr(0, l);
								if (getdigs(tmp3) == getdigs(tmp2))
									st.insert(tmp3);
							}

							int cnt = 0;
							for (auto &xx : st) {
								if (xx == tmp2)
									break;
								cnt++;
							}

							if (l == tmp.size()) {
								tmpans = min(tmpans, l + cnt + 1);
							} else {
								tmpans = min(tmpans,
										l + cnt + int(l - tmp.size()));
							}

						}
					}
				}
			}
			mp[tmp] = tmpans;
			//cerr << idx << " " << i << " " << tmpans << endl;
			ans = min(ans, solve(i + 1) + tmpans);
			//cerr << "end " << i + 1 << endl;
		}
		return dp[idx] = ans;
	}
	int minimumPressings(vector<string> t9, string word) {
		s = word;
		set<string> st;
		for (auto &i : t9) {
			stringstream ss;
			ss << i;
			string tmp;
			while (ss >> tmp) {
				st.insert(tmp);
			}
		}
		for (auto &i : st)
			v.push_back(i);
		for (int i = 0; i < v.size(); i++) {
			t2.insert(v[i], i);

			//cerr << i << " " << v[i] << " " << getdigs(v[i]) << endl;
		}
		memset(dp, -1, sizeof dp);
		//cout << solve(0) << endl;
		if (solve(0) >= 1e6)
			return -1;
		return solve(0);
	}
};
int main() {
	QuickT9 x;
	cout
			<< x.minimumPressings( { "oolong",
					"abba is a swedish musical band dont you know",
					"abbey is something simple",
					"to abandon is easy but to get is hard", "aaaapchkhi" },
					"oooistknaistabbbasomeibandisswaaaaaa") << endl;
	//cout << x.minimumPressings( { "a ab c" }, "acb");

	return 0;
}
