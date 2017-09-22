/*
 * CF822-D2-E.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: Hossam Eissa
 *      Idea: build a Suffix array of the two string to get LCP in o(logn) and dp[char][numberofadding] on the answer
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
const double eps = 1e-9;
/*
 zura Ja - nai.
 KATSURA DA.
 */

#define F first
#define S second
#define debug(x) cout << "WHY" << x << '\n';

struct entry {
	int idx;
	int rnk[2];
} L[2 * N];
bool cmp(entry a, entry b) {
	if (a.rnk[0] == b.rnk[0])
		return a.rnk[1] < b.rnk[1];
	return a.rnk[0] < b.rnk[0];
}

int SA[20][N + N];

int n, m, nn;
string str1, str2;
string str;
int k;
int stp = 1, cnt = 1;
int lcp(int x, int y) {
	int ret = 0;

	if (x == y)
		return n - x;

	for (int i = stp - 1; i >= 0 && x < nn && y < nn; i--)
		if (SA[i][x] == SA[i][y])
			x += (1 << i), y += (1 << i), ret += (1 << i);
	return ret;
}
int dp[N + N][33];
int main() {
	cin >> n;
	cin >> str1;
	cin >> m;
	cin >> str2;
	str = str2 + "#" + str1;
	cin >> k;
	nn = str.size();

	for (int i = 0; i < nn; i++)
		SA[0][i] = str[i];
	for (; cnt < nn; cnt *= 2, ++stp) {
		for (int i = 0; i < nn; i++) {
			L[i].rnk[0] = SA[stp - 1][i];
			L[i].idx = i;
			L[i].rnk[1] = i + cnt >= nn ? -1 : SA[stp - 1][i + cnt];
		}

		sort(L, L + nn, cmp);

		SA[stp][L[0].idx] = 0;

		for (int i = 1, curRank = 0; i < nn; i++) {

			if (L[i - 1].rnk[0] != L[i].rnk[0]
					|| L[i - 1].rnk[1] != L[i].rnk[1])
				curRank++;

			SA[stp][L[i].idx] = curRank;

		}
	}
	/*	for (int i = 0; i < nn; i++)
	 cout << L[i].idx << " " << SA[stp - 1][L[i].idx] << " "
	 << str.substr(SA[stp - 1][L[i].idx]) << endl;
	 */
	for (int j = 0; j <= k; j++) {

		for (int i = m + 1; i <= nn; i++) {
			if (j)
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			int le = lcp(i, dp[i][j]);
			//cerr << i << " " << j << " " << dp[i][j] << " " << le << endl;
			if (i + le <= nn)
				dp[i + le][j + 1] = max(dp[i + le][j + 1], dp[i][j] + le);
			else
				dp[nn][j + 1] = max(dp[nn][j + 1], dp[i][j] + le);
			//if (le)
			//		cerr << "new " << i + le << " " << j + 1 << " "
			//	<< dp[i + le][j + 1] << endl;

		}
		if (dp[nn][k] >= m) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
