/*
Author: Hossam Eissa

Idea:Pattern every 300 number


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
/*int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
/*int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
ll n, m, k, p;
ll F[N], sum[N];
int main()
{
    FO;
	F[1] = 1;
	F[2] = 1;
	sum[1] = 1;
	sum[2] = 2;
	for (int i = 3; i<N; i++) {
		F[i] = (F[i - 1] + F[i - 2]) % 100;
		sum[i] = sum[i - 1] + F[i];
	}
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ll x, XX;
		ll ans = 0;
		n--;
		if (n % 300 == 0)
			x = n / 300;
		else x = n / 300 + 1;
		XX = x * 300;
		if (m<XX) {
			ans += sum[m % 300] - sum[n % 300];
		}
		else if (m == XX) {
			ans += sum[300] - sum[n % 300];
		}
		else {
			ans += sum[m % 300];
			m -= m % 300;
			int n1 = n % 300;
			if (n1 == 0)n1 = 300;
			ans += sum[300] - sum[n1];
			n =XX;
			ans += (m - n) / 300 * sum[300];
		}

		cout << ans << endl;
	}


}
