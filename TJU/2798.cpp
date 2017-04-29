/*
Author: Hossam Eissa

Idea:generate the seqance


*/
#include <bits/stdc++.h>
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
#define INF 2e12+5
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
int n, m, k;
vector<pair<int, int> >v;

int main()
{

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int a, b, c, d;
		a = 0, b = 1, c = 1, d = n;
		bool f = 0;
		while (c <= n) {
			int k = (n + b) / d;
			int na = c;
			int nb = d;
			int nc = (k*c - a);
			int nd = (k*d - b);
			a = na;
			b = nb;
			c = nc;
			d = nd;
			if (a == b)break;
			if (f)printf(",");
			printf("%d/%d", a, b);
			f = 1;
		}

		printf("\n");
	}
}
