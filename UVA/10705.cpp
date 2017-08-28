/*
 * UVA 10705.cpp
 *
 *  Created on: Aug 28, 2017
 *      Author: Hossam Eissa
 *      Idea: back track on the digit every time try to put 1 or 0 if you reach the answer stop
 */

#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll  long long

const int N = 1e5;
const double eps = 1e-9;
string s;
int n;
ll k;
bool f = 0;
char answer[70];
ull powers[70];
void solve(int idx, ll val) {
	if (f)
		return;
	if (idx == n) {
		if (val == k) {
			f = 1;
		}
		return;
	}
	ll mn, mx;
	mn = mx = val;
	for (int i = idx; i < n; i++) {
		if (s[i] == 'n')
			mn -= powers[n-1-i];
		else
			mx += powers[n-1-i];
	}
	if (mn > k || mx < k)
		return;
	ll v = powers[n-1-idx];
	if (s[idx] == 'n')
		v = -v;
	answer[idx] = '1';
	solve(idx + 1, val + v);
	if (f)
		return;
	answer[idx] = '0';
	solve(idx + 1, val);

}
int main() {
	powers[0]=1LL;
	for (int i = 1; i < 64; i++)
		powers[i] =powers[i-1]*2;
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(answer, 0, sizeof answer);
		scanf("%d", &n);
		//	cerr << n << " " << k << endl;
		cin >> s>>k;
		ll mn = 0;
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'n')
				mn -= powers[n-1-i];
			else
				mx += powers[n-1-i];
		}
		f = 0;
		if (k < -9223372036854775807LL) {
			if (n == 64 && s[n-1] == 'n') {
				for(int i=0;i<n;i++)
				answer[i] = '0';
				answer[n-1] = '1';
				f= true;
			}
		} else {
			solve(0, 0);
		}
		if (f) {
			for (int i = 0; i < n; i++)
				putchar(answer[i]);
				puts("");
		} else {
			puts("Impossible");
		}

	}
	return 0;
}
