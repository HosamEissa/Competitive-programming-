/*
Author: Hossam Eissa

Idea:do only the last level moving


*/
#include <bits/stdc++.h>
#include<stdio.h>
#include <map>
#include<unordered_map>
using namespace std;
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pf(a) printf("%d",a)
#define pf2(a,b) printf("%d %d",a,b)
#define pf3(a,b,c) printf("%d %d %d",a,b,c)
#define sfl(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pfl(a) printf("%lld",a)
#define pfl2(a,b) printf("%lld %lld",a,b)
#define pfl3(a,b,c) printf("%lld %lld %lld",a,b,c)
#define nl printf("\n")
#define ll long long
#define se second
#define fi first
#define mk(a, b) make_pair(a, b)
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvpi vector<vector<pii>>
#define pli pair<ll, int>
#define INF 2e9+5
#define MAX (int)1e6 + 5
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define edge pair<ll, pair<int, int>>
#define CYA  exit(0);
#define pi acos(-1);
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 }; // 4 Direction*/
							/*int dx[]={1,1,0,-1,-1,-1,0,1};
							int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
							/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
							int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
ll n, m, k;
ll vals[N];
int main()
{
    //FO;
	ll val = 0;
	ll x1 = 1;
	vals[0] = 1;
	for (int i = 1; i < 100000; i++) {
		val += 8;
		x1 += val;
		vals[i] = x1;
	}
	while (scanf("%lld %lld", &n, &m)) {
		if (!n && !m)break;
		int st1, en1;
		st1 = (n+1) / 2;
		en1 = (n+1) / 2;
		if (m == 1) {
			printf("Line = %d, column = %d.\n", st1, st1);
			continue;
		}

		ll l = lower_bound(vals, vals + N, m) - vals;

		ll le = 2*l-1, d = le+1, ri = le+1, u = le+1;
		ll cnt = vals[l-1] + 1;
		cnt = m-cnt;
		int x = st1+l-1, y = en1+l;
		if (le <= cnt) {
			cnt -= le;
			x -= le;
		}
		else {
			x -= cnt;
			cnt = 0;
		}
		if (d <= cnt) {
			cnt -= d;
			y -= d;
		}
		else {
			y -= cnt;
			cnt = 0;
		}
		if (ri <= cnt) {
			cnt -= ri;
			x += ri;
		}
		else {
			x += cnt;
			cnt = 0;
		}
		if (u <= cnt) {
			cnt -= u;
			y += u;
		}
		else {
			y += cnt;
			cnt = 0;
		}
		printf("Line = %d, column = %d.\n", y, x);


	}
}
