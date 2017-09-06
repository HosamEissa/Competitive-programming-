/*
 * UVA_11576.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: Hossam Eissa
 *      Idea: for each two strings add S[i].length - suffix of S[i] that match prefix of S[i-1] 
 */



#include<bits/stdc++.h>
using namespace std;
const int N=2e2+5;
int X[N];
int main()
{
	//FO;
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string>v(m);
		for (auto &i : v)cin >> i;
		int ans = v[0].size();
		for (int I = 0; I<m- 1; I++) {
			memset(X, 0, sizeof X);
			string s = v[I + 1] + '$' + v[I];
			int i = 0, j = -1; X[0] = -1;
			while (i<s.size()) {
				while (j >= 0 && s[i] != s[j])j = X[j];
				i++;
				j++;
				X[i] = j;
			}
			int mx = 0;
			ans +=(int)v[I].size()-X[s.size()];
		}
		cout << ans << endl;
	}

	return 0;
}
