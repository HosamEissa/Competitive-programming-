/*
 * CF631-D2-D.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: Hossam Eissa
 *      Idea: 
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
int n, m;
vector<pair<char, ll>> v, v2;
bool ok(int j, int i, vector<pair<char, ll>> &s) {
	//cerr<<j<<" "<<i<<" "<<s[i].first<<" "<<s[i].second<<" "<<s[j].first<<" "<<s[j].second<<endl;
	if (!j)
		return 0;
	if (s[i].first != s[j].first)
		return 1;
	if (s[i].second < s[j].second)
		return 1;
	if (j < m - 1 && s[i].second == s[j].second)
		return 0;
	if (j == m - 1 && s[i].second >= s[j].second)
		return 0;
	return 1;
}
vector<int> kmparr(vector<pair<char, ll>> s) {
	vector<int> ret(s.size());
	int j = 0;
	for (int i = 1; i < (int) s.size(); i++) {
		while (ok(j, i, s))
			j = ret[j - 1];
		if (s[i].first == s[j].first && s[i].second >= s[j].second)
			j++;
		//	cerr<<i<<" "<<j<<endl;
		ret[i] = j;
		if (j == m && s[i].second > s[j - 1].second) {
			j = ret[j - 1];
			while (ok(j, i, s))
				j = ret[j - 1];
			if (s[i].first == s[j].first && s[i].second >= s[j].second)
				j++;

		}

	}
	return ret;

}
vector<pair<char, ll>> getin(int n) {
	vector<pair<char, ll>> v, tmp;
	for (int i = 0; i < n; i++) {
		char x, c;
		int a;
		cin >> a >> c >> x;
		//a=1e5;
		//x='a';
		v.push_back(pair<char, int>(x, a));
	}
	tmp.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		if (tmp.back().first == v[i].first) {
			tmp.back().second += v[i].second;
		} else {
			tmp.push_back(v[i]);
		}
	}
	return tmp;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v = getin(n);
	v2 = getin(m);
	//v2[0].second=1;
	m = v2.size();
	n = v.size();
	if (m == 1) {
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].first == v2[0].first && v[i].second >= v2[0].second) {
				ans += v[i].second - v2[0].second + 1;
			}
		}
		cout << ans << endl;

	} else {
		v2.push_back(pair<char, int>('?', 0));
		for (int i = 0; i < v.size(); i++)
			v2.push_back(v[i]);
		vector<int> ret = kmparr(v2);
		int j = 0;
		ll ans = 0;
		for (int i = 0; i < ret.size(); i++) {
			//	cerr << i << " " << ret[i] << endl;
			if (ret[i] == m)
				ans++;
		}
		cout << ans << endl;
	}
}
