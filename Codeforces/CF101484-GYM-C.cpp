/*
 * contest.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: Hossam Eissa
 *      Idea: for every second of the contest calculate the winner if it is your contestant ans++
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 6;
const double eps = 1e-9;

int n, m, p;
int mat[201][15];
int mat2[201][15];
//<<time,team>,<problem,OkOrNot>>
vector<pair<pair<int, int>, pair<int, int>>> q;
//<name,id>
map<string, int> mp;
pair<int, int> getsum(int idx) {
	int P = 0, sum = 0;
	for (int p1 = 0; p1 < p; p1++) {
		if (mat2[idx][p1]) {
			P++;
			sum += mat2[idx][p1] + mat[idx][p1] * 20;
		}
	}
	return {P,sum};
}
int main() {
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s] = i;
	}
	q.resize(m);
	for (int j = 0; j < m; j++) {
		string s, ok;
		char a;
		int time, ok2, id, problemid;
		cin >> s >> a >> time >> ok;
		ok2 = (ok == "OK");
		problemid = a - 'A';
		id = mp[s];
		q[j]= { {time,id}, {problemid,ok2}};
	}
	sort(q.begin(), q.end());
	int idx = 0;
	int ans=0;
	for (int i = 0; i < 300; i++) {
		while (idx < m && q[idx].first.first <= i) {
			int id = q[idx].first.second;
			int pid = q[idx].second.first;
			int ok = q[idx].second.second;
		//	cerr<<"qurry "<<id<<" "<<pid<<" "<<ok<<endl;
			if (!ok) {
				mat[id][pid]++;
			} else {
				mat2[id][pid] = q[idx].first.first;
			}
			idx++;
		}
		int mxp = 0, mnt = 1e18, best = -1;
		for (int j = 0; j < n; j++) {
			pair<int, int> p = getsum(j);
			if (mxp < p.first) {
				mxp = p.first;
				mnt = p.second;
				best = j;
			}
			if (mxp == p.first && mnt > p.second) {
				mnt = p.second;
				best = j;
			}
		//	cerr<<"team id ="<<j<<" "<<p.first<<" "<<p.second<<endl;
		}
		//cerr<<i<<" "<<mxp<<" "<<mnt<<" "<<best<<" "<<idx<<endl;
		if(best==0)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
