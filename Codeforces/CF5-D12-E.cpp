/*
 * CF5-D12-E.cpp
 *
 *  Created on: Aug 28, 2017
 *      Author: Hossam Eissa
 *      Idea: rotate the array so that the highest hill is at first and put temp 1 after last position 
 *            now the problem is line and you want to know what is the index of highest hill on right and left
 *            
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 6;
const double eps = 1e-9;
int arr[N], r[N], l[N], c[N], c2[N];
int main() {
	int n;
	scanf("%d",&n);
	int mx = 0, idx = 0;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
		if (arr[i] > mx) {
			mx = arr[i];
			idx = i;
			cnt = 0;
		}
		if (arr[i] == mx)
			cnt++;
	}
	rotate(arr, arr + idx, arr + n);
	arr[n] = mx;
	for (int i = n - 1; i >= 0; i--) {
		r[i] = i + 1;
		while (r[i] < n && arr[i] > arr[r[i]]) {
			r[i] = r[r[i]];
		}
		if (r[i] < n && arr[i] == arr[r[i]]) {
			c[i] = c[r[i]] + 1;
			r[i] = r[r[i]];
		}
	}
	for (int i = 1; i < n; i++) {
		l[i] = i - 1;
		while (l[i] > 0 && arr[i] > arr[l[i]]) {
			l[i] = l[l[i]];
		}
		if (l[i] > 0 && arr[i] == arr[l[i]]) {
			c2[i] = c2[l[i]] + 1;
			l[i] = l[l[i]];
		}
	}
	/*for (int i = 0; i < n; i++)
	 cerr << i << " " << arr[i] << " " << l[i] << " " << c2[i] << " " << r[i]
	 << " " << c[i] << endl;
	 */
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] != mx) {
			ans += c[i];
			if (l[i] != 0 || r[i] != n)
				ans += 2;
			else
				ans++;
		}
	}

	cerr << ans << " " << cnt << endl;
	cout << ans + (cnt * (cnt - 1)) / 2 << endl;
	return 0;
}
