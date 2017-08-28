/*
 * contest.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: Hossam Eissa
 *      Idea: for every person find how many person inside his mask and how many mask he is inside and how many equal to him using dp
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
int arr[(1 << 21)], v[N], dp[21][(1 << 21)];
int n, m;
int solve(int idx, int msk) {
	if (idx == m)
		return 0;
	int &ans = dp[idx][msk];
	if (~ans)
		return ans;
	ans = 0;
	ans += solve(idx + 1, msk);
	if (msk & (1 << idx))
		ans += arr[msk ^ (1 << idx)] + solve(idx + 1, msk ^ (1 << idx));
	return ans;
}
int solve2(int idx, int msk) {
	if (idx == m)
		return 0;
	int &ans = dp[idx][msk];
	if (~ans)
		return ans;
	ans = 0;
	ans += solve2(idx + 1, msk);
	if (!(msk & (1 << idx)))
		ans += arr[msk | (1 << idx)] + solve2(idx + 1, msk| (1 << idx));
	return ans;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[v[i] = a]++;

	}
	ll ans = 0;
	sort(v,v+n);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++) {
		int a = v[i];
		ans += n - 1;
		ans -= solve(0, a);
	//	cerr<<i<<" "<<a<<" "<<ans<<endl;
	}
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++) {
		int a = v[i];
		ans -= solve2(0, a);
		ans-=arr[a]-1;
	//	cerr<<i<<" "<<a<<" "<<ans<<endl;
	}
	cout<<ans/2<<endl;
	return 0;
}
