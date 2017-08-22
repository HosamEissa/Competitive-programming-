/*
 * SRM504-D2-1000.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: Hossam Eissa
 *      Idea: use recurion to try every possible string and check if it gives the
 *      needed output or not
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
class Algrid {
public:
	vector<string> avali;
	bool f=false;
	bool ok(string &o, string &perv, string tmp) {
		int sz = o.size();
		for (int i = 0; i < sz - 1; i++) {
			if (perv[i] == 'W' && perv[i + 1] == 'W')
				continue;
			if (perv[i] == 'W' && perv[i + 1] == 'B')
				tmp[i] = 'W', tmp[i + 1] = 'W';
			if (perv[i] == 'B' && perv[i + 1] == 'W')
				tmp[i] = 'B', tmp[i + 1] = 'B';
			if (perv[i] == 'B' && perv[i + 1] == 'B')
				swap(tmp[i], tmp[i + 1]);
		}
		return o == tmp;
	}
	void solve(vector<string>&o, vector<string>&ans) {
		if (ans.size() == o.size()){
			f=1;
			return;
		}
		int sz = avali.size();
		int idx = ans.size();
		for (int i = 0; i < sz; i++) {
			string tmp = avali[i];
			if (ok(o[idx], o[idx - 1], tmp)) {
				ans.push_back(tmp);
				solve(o, ans);
				if(f)
					return;
				ans.pop_back();
			}
		}
	}
	vector<string> makeProgram(vector<string> output) {
		vector<string> ans;
		int n = output[0].size();
		for (int i = 0; i < (1 << n); i++) {
			string tmp;
			for (int j = n - 1; j >= 0; j--) {
				if (i & (1 << j))
					tmp += 'W';
				else
					tmp += 'B';
			}
			avali.push_back(tmp);
		}
		ans.push_back(output[0]);
		solve(output, ans);
		if(!f)return vector<string>();
		return ans;
	}
};
int main() {
	Algrid d;
	vector<string>ans=d.makeProgram({"WWBBBBW",
		 "BWBBWBB",
		 "BWBBWBW",
		 "BWWBWBB"});
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}
