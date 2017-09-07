/*
 * UVA_11107.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: Hossam Eissa
 *      Idea: put all the strings in one string ans then build suffix array then LCP and walk on the string to get the answer using LCP
 *      
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5;
const double eps = 1e-9;
const int Mx = 2e5 + 9;
char str[Mx];
int suf[Mx];
int rnk[Mx];
int tmprank[Mx];
int lcp[Mx];
int idx[Mx];
int counter[Mx];
struct cmp {
	int h;
	bool operator()(int i, int j) const {
		return rnk[i] < rnk[j] || (rnk[i] == rnk[j] && rnk[i + h] < rnk[j + h]);
	}
};
void buildSA() {
	int len = 0;
	do {
		suf[len] = len;
		rnk[len] = str[len];
	} while (str[len++]);
	for (int h = 1;; h <<= 1) {
		cmp c = { h };
		sort(suf, suf + len, c);
		for (int i = 1; i < len; i++) {
			tmprank[i] = tmprank[i - 1] + c(suf[i - 1], suf[i]);
		}
		for (int i = 0; i < len; i++) {
			rnk[suf[i]] = tmprank[i];
		}
		if (tmprank[len - 1] == len - 1)
			break;
	}
}
void build_lcp() {
	int len = 0;
	for (int i = 0; str[i]; i++) {
		int j = suf[rnk[i] - 1];
		while (str[i + len] == str[j + len])
			len++;
		lcp[rnk[i]] = len;
		if (len)
			len--;
	}
}

int main() {
	int n;
	int t = 0;
	while (cin >> n && n) {
		if (t++)
			cout << endl;
		int last = -1;
		char cc = 'z' + 1;
		for (int i = 0; i < n; i++) {
			scanf("%s", str + last + 1);
			for (int j = max(0, last); str[j] != 0; j++)
				idx[j] = i;
			last = strlen(str);
			str[last] = cc;
			cc++;
		}
		str[last] = 0;
		if (n == 1) {
			cout << str << endl;
			continue;
		}
		buildSA();
		build_lcp();
		int ans = 0;
		int nx = n / 2 + 1;
		string s = str;
		set<string> answer;
		multiset<int> lcps;
		int cnt = 0;
		for (int i = 0, j = 0; i <= last; i++) {
			//	printf("%d %d %d %s\n", i, idx[suf[i]], lcp[i], str + suf[i]);
			while (cnt < nx && j <= last) {
				lcps.insert(lcp[j]);
				counter[idx[suf[j]]]++;
				if (counter[idx[suf[j]]] == 1)
					cnt++;
				j++;
			}
			counter[idx[suf[i]]]--;
			if (counter[idx[suf[i]]] == 0)
				cnt--;
			lcps.erase(lcps.find(lcp[i]));
			if (ans < *(lcps.begin())) {
				ans = *(lcps.begin());
				answer.clear();
			}
			if (ans == *(lcps.begin())) {
				answer.insert(s.substr(suf[i], ans));
			}
			//cout<<i<<" "<<ans<<endl;

			//cout << i << " " << st.size() << endl;

		}
		//cerr<<ans<<endl;
		if (ans) {
			for (auto &i : answer)
				cout << i << endl;
		} else
			cout << "?" << endl;
	}
	return 0;
}
