/*
 * SRM321-D1-500.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: Hossam Eissa
 *      Idea: sort the items if you have problem between two items take the first one after them and put it in the middle
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
class WeirdSort {
public:
	int cnt[1001];
	vector<int> sortArray(vector<int> data) {

		sort(data.begin(), data.end());
		set<int> st;
		set<int>::iterator it;
		vector<int> sorted;
		sorted.push_back(-2);
		for (auto i : data)
			st.insert(i), cnt[i]++;
		if (st.size() == 1)
			return data;
		if (st.size() == 2) {
			if (data[0] + 1 != data[data.size() - 1])
				return data;
			reverse(data.begin(), data.end());
			return data;
		}
		vector<int> ans;
		while (st.size() > 2) {
			if (*st.begin() == sorted.back() + 1) {
				it = st.begin();
				it++;
				ans.push_back(*it);
				sorted.push_back(*it);
				cnt[*it]--;
				if (cnt[*it] == 0)
					st.erase(it);
			} else {
				it = st.begin();
				while (cnt[*it] > 0)
					ans.push_back(*it), cnt[*it]--;
				sorted.push_back(*it);
				st.erase(it);
			}
		}
		int val = *st.begin();
		st.erase(st.begin());
		int val2 = *st.begin();
		if (val2 == val + 1) {
			while (cnt[val2]--)
				ans.push_back(val2);
			while (cnt[val]--)
				ans.push_back(val);
		}
		else if(val == sorted.back() + 1){
				cnt[val2]--;
				ans.push_back(val2);
				while (cnt[val]--)
							ans.push_back(val);
						while (cnt[val2]--)
							ans.push_back(val2);
		}
		else {
			while (cnt[val]--)
				ans.push_back(val);
			while (cnt[val2]--)
				ans.push_back(val2);
		}
		return ans;

	}
};
int main(){
	return 0;
}
