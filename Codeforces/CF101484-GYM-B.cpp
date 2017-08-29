/*
 *  CF101484-GYM-B.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: Hossam Eissa
 *      Idea: compress all the points and rectangles then sort points on X's and do a line sweep on them if you hit rectangle add its begin and end in the BIT
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n, m;
int tree[N], answer[N];
void add(int idx, int val) {
	idx++;
	while (idx < N) {
		tree[idx - 1] += val;
		idx += (idx & -idx);
	}
}
int get(int idx) {
	idx++;
	int val = 0;
	while (idx > 0) {
		val += tree[idx - 1];
		idx -= (idx & -idx);
	}
	return val;
}
struct rect {
	int x1, x2, y1, y2;
	rect(int a, int b, int c, int d) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
};
bool cmp(rect &a, rect &b) {
	if (a.x1 != b.x1)
		return a.x1 < b.x1;
	return a.x2 < b.x2;
}
vector<pair<int, pair<int, int>> > v;
vector<rect> rects;
int main() {
	map<int, int> mxx, myy;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back(pair<int, pair<int, int> >(a, pair<int, int>(b, i)));
		mxx[a];
		myy[b];
	}
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a++;
		b++;
		d--;
		mxx[a];
		mxx[c];
		myy[b];
		myy[d];
		if (b <= d) {
			rects.push_back(rect(a, b, c, d));
		}
	}
	int c = 1;
	for (auto &i : mxx)
		i.second = c++;
	c = 1;
	for (auto &i : myy)
		i.second = c++;
	for (int i = 0; i < n; i++) {
		v[i].first = mxx[v[i].first];
		v[i].second.first = myy[v[i].second.first];
		//cerr << i << " " << v[i].first << " " << v[i].second.first << endl;
	}
	m=rects.size();
	for (int i = 0; i < m; i++) {
		rects[i].x1 = mxx[rects[i].x1];
		rects[i].x2 = mxx[rects[i].x2];
		rects[i].y1 = myy[rects[i].y1];
		rects[i].y2 = myy[rects[i].y2];
		//cerr << i << " " << rects[i].x1 << " " << rects[i].y1 << " "
		//			<< rects[i].x2 << " " << rects[i].y2 << endl;

	}
	sort(v.begin(), v.end());
	sort(rects.begin(), rects.end(), cmp);
	int cnt = 0;
	set<pair<int, int>> st;
	//cerr << "work" << endl;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0, ii = 0;
		x = v[i].first;
		y = v[i].second.first;
		ii = v[i].second.second;
		//cerr << ii << " " << x << " " << y << endl;
		while (cnt < m && x >= rects[cnt].x1) {
			int y1 = rects[cnt].y1, y2 = rects[cnt].y2;
			//	cerr<<"add rect from "<<y1<<" to "<<y2<<endl;
			st.insert(pair<int, int>(rects[cnt].x2, cnt));
			add(y1, 1);
			add(y2 + 1, -1);
			cnt++;
		}
		while (st.size() && x >= st.begin()->first) {
			pair<int, int> p = *st.begin();
			int y1 = rects[p.second].y1, y2 = rects[p.second].y2;

			//	cerr<<"delete rect from "<<y1<<" to "<<y2<<endl;
			add(y1, -1);
			add(y2 + 1, 1);
			st.erase(st.begin());
		}
		answer[ii] = get(y);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}
