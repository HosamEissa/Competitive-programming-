/*
 * CF670-D2-F.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: Hossam Eissa
 *      Idea: get the length of the string and erase the number equal to it and then try to build the string 
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
int cnt[10];
multiset<int>::iterator it;
string build(string x, string y, multiset<int> st, int inc) {

	while (st.size()) {
		it = st.begin();
		if (y.empty() || *it < y[0] - '0') {
			x += '0' + *it;
			st.erase(it);
		} else if (*it > y[0] - '0') {
			x += y;
			y = "";
		} else {
			if (inc) {
				x += '0' + *it;
				st.erase(it);
			} else {
				x += y;
				y = "";
			}

		}
	}
	if (y != "")
		x += y;
	return x;
}
int main() {
	string s, s2;
	cin >> s >> s2;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - '0']++;
	}
	bool inc = 1;
	for (int i = 0; i < s2.size(); i++) {
		cnt[s2[i] - '0']--;
	}
	for (int i = 0; i < s2.size(); i++) {
		if (i && s2[i] < s2[i - 1]) {
			inc = 0;
			break;
		}
		if (i && s2[i] > s2[i - 1]) {
			inc = 1;
			break;
		}
	}
	int n = s.size();
	int left = 0;
	if (n - 1 < 10)
		left = n - 1;
	else if (n - 2 < 100)
		left = n - 2;
	else if (n - 3 < 1000)
		left = n - 3;
	else if (n - 4 < 10000)
		left = n - 4;
	else if (n - 5 < 100000)
		left = n - 5;
	else if (n - 6 < 1000000)
		left = n - 6;
	cerr << left << " " << inc << endl;
	while (left > 0) {
		cnt[left % 10]--;
		left /= 10;
	}
	multiset<int> st;
	for (int i = 0; i < 10; i++) {
		while (cnt[i])
			cnt[i]--, st.insert(i);
	}
	string ans;
	if (s2[0] == '0') {
		it = st.upper_bound(0);
		if (it == st.end()) {
			ans += s2;
			ans = build(ans, "", st, 0);
			cout << ans << endl;
			return 0;
		}
		ans += '0' + *it;
		st.erase(it);
		ans = build(ans, s2, st, inc);
	} else {
		it = st.upper_bound(0);
		if (it == st.end()) {
			ans += s2;
			ans = build(ans, "", st, 0);
			cout << ans << endl;
			return 0;
		}
		int tmp = s2[0] - '0';
		if (*it < tmp) {
			cerr << "op1" << endl;
			ans += '0' + *it;
			st.erase(it);
			ans = build(ans, s2, st, inc);
		} else if (tmp < *it) {
			ans += s2;
			s2 = "";
			ans = build(ans, s2, st, inc);
		} else {
			string tmp1, tmp2;
			tmp1 = s2;
			tmp1 = build(tmp1, "", st, inc);
			it = st.upper_bound(0);
			tmp2 += '0' + *it;
			st.erase(it);
			tmp2 = build(tmp2, s2, st, inc);
			ans = min(tmp1, tmp2);
		}
	}
	cout << ans << endl;
	return 0;
}
