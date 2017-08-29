/*
 * TJU_3512.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: Hossam Eissa
 *      Idea: do pattern searching using kmp with each string
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 500;
const double eps = 1e-9;
int n, m;
char st[151][78];
char s[N];
int cnt[151];
int ret[71];
int main() {
	while (scanf("%d", &n) == 1 && n) {
		memset(cnt, 0, sizeof cnt[0] * n);
		for (int i = 0; i < n; i++) {
			scanf(" %s", st[i]);
		}
		scanf(" %s", s);
		int mx = 0;
		int l = strlen(s);
		for (int i = 0; i < n; i++) {
			int k = 0;
			int len = strlen(st[i]);
			for (int j = 1; j < len; j++) {
				while (k && st[i][j] != st[i][k])
					k = ret[k - 1];
				if (st[i][j] == st[i][k])
					k++;
				ret[j] = k;
				//cerr<<j<<" "<<ret[j]<<endl;
			}
			k = 0;
			for (int j = 0; j < l; j++) {
				//cerr<<k<<" "<<j<<endl;
				while (k && s[j] != st[i][k])
					k = ret[k - 1];
				if (st[i][k] == s[j])
					k++;
				if (k == len) {
					cnt[i]++;
					k = ret[k - 1];
				}
			}
			mx = max(cnt[i], mx);

		}
		printf("%d\n", mx);
		for (int i = 0; i < n; i++) {
			if (mx == cnt[i])
				printf("%s\n", st[i]);
		}
	}
}

