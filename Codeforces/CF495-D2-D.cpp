/*
 * CF495-D2-D.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Hossam Eissa
 *      Idea: 
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
string s, t;
int match[N];
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

void kmp(vector<int> v) {
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j && s[i] != t[j])
			j = v[j - 1];
		if (s[i] == t[j])
			j++;
		if (j == t.size())
			j = v[j - 1], match[i] = 1;
	}
}
int q1[N], q2[N], sum[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin >> s >> t;
	kmp(kmparr(t));
	q1[0] = q2[0] = sum[0] = match[0];
	for (int i = 1; i < s.size(); i++) {
		if (match[i]) {
			sum[i] = (q2[i - t.size()] + i - t.size() + 2) % MOD;
			q1[i] = (q1[i - 1] + sum[i]) % MOD;
			q2[i] = (q2[i - 1] + q1[i]) % MOD;
		} else {
			sum[i] = sum[i - 1];
			q1[i] = (q1[i - 1] + sum[i]) % MOD;
			q2[i] = (q2[i - 1] + q1[i]) % MOD;

		}
	}
	cout << q1[s.size() - 1];
	return 0;
}
