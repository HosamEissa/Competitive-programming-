/*
 * SPOJ_PARSUMS .cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: Hossam Eissa
 *      Idea: copy the array to the end of it and do prefix sum and use min segment tree to check if the current cycle have min >=0 or not
 
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
const double eps = 1e-9;
int arr[N];
ll sum[N];
ll tree[4 * N], lazy[4 * N] = { 0 };
void probagate(int l, int r, int p) {
	tree[p] -= lazy[p];
	if (l != r) {
		lazy[p << 1] += lazy[p];
		lazy[(p << 1) | 1] += lazy[p];
	}
	lazy[p] = 0;
}
void build(int l, int r, int p) {
	if (l == r) {
		tree[p] = sum[l];
		lazy[p] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, (p << 1));
	build(m + 1, r, (p << 1) | 1);
	tree[p] = min(tree[(p << 1)], tree[(p << 1) | 1]);
	lazy[p] = 0;
	return;
}
ll get(int ql, int qr, int l, int r, int p) {
	probagate(l, r, p);
	if (ql > r || qr < l)
		return 1e18;
	if (ql <= l && r <= qr)
		return tree[p];
	int m = (l + r) >> 1;
	return min(get(ql, qr, l, m, p << 1), get(ql, qr, m + 1, r, (p << 1) | 1));
}
void update(ll val, int ql, int qr, int l, int r, int p) {
	probagate(l, r, p);
	if (ql > r || qr < l)
		return;
	if (ql <= l && r <= qr) {
		lazy[p] = val;
		probagate(l, r, p);
		return;
	}
	int m = (l + r) >> 1;
	update(val, ql, qr, l, m, (p << 1));
	update(val, ql, qr, m + 1, r, (p << 1) | 1);
	tree[p] = tree[(p << 1)] & tree[(p << 1) | 1];
}
int main() {
	int n;
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			arr[i + n] = arr[i];
		}
		for (int i = 1; i <= 2 * n; i++) {
			sum[i] = arr[i] + sum[i - 1];
		}
		int nn = 2 * n;
		build(1, nn, 1);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (get(i, i + n - 1, 1, nn, 1) >= 0)
				ans++;
			update(arr[i],i,nn,1,nn,1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
