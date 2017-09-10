/*
 * SPOJ_DNALAB.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: Hossam Eissa
 *      Idea: use dp[mask][lastusedstring] to get the string with minmum size() that have all the strings as sub string
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 18;
const double eps = 1e-9;
string st[N];
int cost[N][N];
int n;
string answer;
vector<int> kmparr(string s) {
	vector<int> ret(s.size());
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j && s[i] != s[j])
			j = ret[j - 1];
		if (s[i] == s[j])
			j++;
		ret[i] = j;
	}
	return ret;

}
int dp[(int) (1 << 17)][N];
int solve(int msk, int last = N - 1) {
	if (msk == (1 << n) - 1) {
		return dp[msk][last] = 0;
	}
	if (dp[msk][last] != -1)
		return dp[msk][last];
	int ans = 1e6;
	for (int i = 0; i < n; i++) {
		if (msk & (1 << i))
			continue;
		int nmsk = msk | (1 << i);
		ans = min(ans, solve(nmsk, i) + cost[last][i]);
	}
	return dp[msk][last] = ans;
}
void print(int msk, int last = N - 1) {
	if (msk == (1 << n) - 1) {
		return;
	}
	int tmpsk = 0, tmplast = 0;
	string ans = "|";
	for (int i = 0; i < n; i++) {
		if (msk & (1 << i))
			continue;
		int nmsk = msk | (1 << i);
		if (dp[msk][last] == solve(nmsk, i) + cost[last][i]) {
			string tmp = answer
					+ st[i].substr(st[i].size() - cost[last][i], cost[last][i]);
			if (tmp < ans) {
				ans = tmp;
				tmpsk = nmsk;
				tmplast = i;
			}
		}
	}
	answer = ans;
	print(tmpsk, tmplast);
}
int main() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		answer = "";

		cin >> n;
		memset(dp, -1, sizeof dp);
		memset(cost, 0, sizeof cost);
		for (int i = 0; i < n; i++) {
			cin >> st[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (st[i].find(st[j]) != string::npos) {
					st[j] = st[i];
				}
			}
		}

		sort(st, st + n);
		n = unique(st, st + n) - st;
		//cerr << "done" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				int c1 = st[i].size() - 1;
				int c2 = 0;
				int cnt = 0;
				while (c1 >= 0 && c2 < st[j].size()) {
					if (st[i].substr(c1) == st[j].substr(0, c2 + 1)) {
						cnt = c2 + 1;
					}
					c2++;
					c1--;
				}
				cost[i][j] = st[j].size() - cnt;
				//		cerr << i << " " << st[i] << " " << c1 << " " << j << " "
				//				<< st[j] << " " << c2 << " " << cost[i][j] << endl;
			}
			cost[N - 1][i] = st[i].size();
		}
		solve(0);
		//	cout << solve(0) << endl;
		print(0);

		cout << "Scenario #" << tc << ":" << endl;
		cout << answer << endl << endl;
		//cout << solve(0, "") << endl;

	}
	return 0;
}
