/*
Author: Hossam Eissa

Idea:dfs the 2d grid getting the maximum value for each cell


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
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
							/*int dx[]={1,1,0,-1,-1,-1,0,1};
							int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
							/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
							int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
ll n, m, k;
int mat[101][101], vis[101][101];
bool ok(int x, int y) {
	if (x >= 0 && x<n&&y >= 0 && y<m)return 1;
	return 0;
}
int dfs(int i, int j) {
	int sum = 0;
	for (int k = 0; k <= 3; k++) {
		int x = i + dx[k];
		int y = j + dy[k];
		if (ok(x, y) && mat[x][y]<mat[i][j]) {
			if (vis[x][y]) {
				sum = max(sum, vis[x][y]);
			}
			else {
				vis[x][y] = 1;
				sum = max(sum, dfs(x, y));
			}
		}
	}
	return vis[i][j]+=sum;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		memset(mat, 0, sizeof vis);
		string name;
		cin >> name;
		cin >> n >> m;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				cin >> mat[i][j];
			}
		}
		int mx = 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (!vis[i][j]) {
					vis[i][j] = 1;
					dfs(i, j);
				}
				mx = max(mx, vis[i][j]);
			}
		}
		cout << name << ": " << mx << endl;
	}

}
