/*
 * CF291-D2-E.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: Hossam Eissa
 *      Idea: build a tree from the input and then traverse it with another variable idx in pat you have matched so far
 *            and use dp [char][patidx] to pass the TLE of the failure function
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const double eps = 1e-9;
const int MOD = 1e9 + 7;
int n, m, ans;
vector<vector<int> > v2(N);
string pat;
vector<int> kmpv;
string st[N];
int dp[28][3 * N];
vector<int> kmparr(string &s) {
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
void dfs(int u, int idx) {
	//cerr << u + 1 << " " << idx << endl;
	for (auto v : v2[u]) {
		int j = idx;
		string &s = st[v];
		for (int i = 0; i < s.size(); i++) {
			if (dp[s[i] - 'a'][j] == -1) {
				int tmpj = j;
				while (j && s[i] != pat[j])
					j = kmpv[j - 1];
				dp[s[i] - 'a'][tmpj] = j;
			} else {
				j = dp[s[i] - 'a'][j];
			}
			if (s[i] == pat[j])
				j++;
			if (j == pat.size()) {
				ans++;
				j = kmpv[j - 1];
				//	cerr << "found " << v.first + 1 << " " << j << " " << i << endl;
			}
		}
		dfs(v, j);
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i < n; i++) {
		int p;
		string s;
		cin >> p >> st[i];
		v2[p - 1].push_back(i);

	}
	cin >> pat;
	kmpv = kmparr(pat);
	//for (int i = 0; i < kmpv.size(); i++)
	//	cerr << i << " " << kmpv[i] << endl;
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
