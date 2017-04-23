/*
Author: Hossam Eissa

Idea:implementation


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
const int N = 1e3 + 5;
double n, m, k;
map<char, int>mp;
vector<int>v;
string s;
int idx2 = 0;
int solve2() {
	if (s[idx2] >= 'a'&&s[idx2] <= 'z') {
		
		return v[mp[s[idx2++]]];
	}
	else {
		idx2++;
		if (s[idx2-1] == 'K') {
			int a = solve2();
			int b = solve2();
			return a&b;
		}
		else if (s[idx2-1] == 'A') {
			int a = solve2();
			int b = solve2();
			return a|b;
		}

		else if (s[idx2-1] == 'N') {
			int a = solve2();
			return !a;
		}

		else if (s[idx2-1] == 'C') {
			int a = solve2();
			int b = solve2();
			if (a&&!b) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else if (s[idx2-1] == 'E') {
				int a = solve2();
				int b = solve2();
				return a==b;
			}

		}

	}

int ans=1;
void solve(int idx) {
	if (!ans)return;
	if (idx == mp.size()) {
		idx2 = 0;
		bool c = solve2();
		if (!c)
			ans=0;
		return;
	}
	else {
		for (int i = 0; i <= 1; i++) {
			v.push_back(i);
			solve(idx + 1);
			v.pop_back();
		}
	}
}
int main()
{
	in;
	map<char, int>input;
	input['p'];
	input['q'];
	input['r'];
	input['s'];
	input['t'];
	input['K'];
	input['A'];
	input['N'];
	input['C'];
	input['E'];
	while (getline(cin,s)&&s != "0") {
		n = s.size();
		int c = 0;
		mp.clear();
		v.clear();
		ans = 1;
		string s2 = "";
		for (int i = 0; i < n; i++) {
			if (input.count(s[i]))
				s2 += s[i];
		}
		s = s2;
		n = s.size();
		for (int i = 0; i<n; i++) {
			if (s[i] >= 'a'&&s[i] <= 'z'&&!mp.count(s[i])) {
				mp[s[i]] = c;
				c++;
			}
			
		}
		if(s.size())solve(0);
		if (ans) {
			cout << "tautology" << endl;
		}
		else {

			cout << "not" << endl;
		}
	}
}
