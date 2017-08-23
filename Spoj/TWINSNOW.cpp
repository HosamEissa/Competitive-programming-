/*
 * TWINSNOW.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: Hossam Eissa
 *      Idea: take the input match if two vectors are equal output yes
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
int main() {
	int n;
	scanf("%d", &n);
	map<vector<int>, bool> mp;
	vector<vector<int>>v2;
	for (int i = 0; i < n; i++) {
		vector<int> v(6);
		for (int j = 0; j < 6; j++)
			scanf("%d", &v[j]);
		sort(v.begin(),v.end());
		v2.push_back(v);
	}
	sort(v2.begin(),v2.end());
	for(int i=1;i<n;i++){
			if(v2[i]==v2[i-1]){
				printf("Twin snowflakes found.");
					return 0;
			}
	}
	printf("No two snowflakes are alike.");
	return 0;
}
