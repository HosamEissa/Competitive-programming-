/*
 * SPOJ_SUBST1.cpp
 *
 *  Created on: Sep 1, 2017
 *      Author: Hossam Eissa
 *      Idea: different substrings =all substrings - summtion of (lcp) for all suffix
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
const int Mx = 2e5 + 9;
char str[Mx];
int suf[Mx];
int rnk[Mx];
int tmprank[Mx];
int lcp[Mx];
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
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int n = strlen(str);
		ll cnt = 0;
		buildSA();
		build_lcp();
		for (int i = 0; i <= n; i++) {
			cnt += n - suf[i] - lcp[i];
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
