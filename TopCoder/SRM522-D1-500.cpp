/*
 * SRM522-D1-500.cpp
 *
 *  Created on: Aug 22, 2017
 *      Author: Hossam Eissa
 *      Idea: best C will be alwayes in range[c-2000,c+2000]
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
class CorrectMultiplication {
public:
	ll solve(ll C,int A,int B){
		ll ans=1e18;
		for (int i = 1; i * i <= C; i++) {
					if (C % i == 0) {
						ans = min(ans, (ll) abs(i - A) + abs((C / i) - B));
						ans = min(ans, (ll) abs(i - B) + abs((C / i) - A));
					}
				}
				return ans;
	}
	ll getMinimum(int A, int B, int C) {
		ll ans = 1e10;
		for (int i = max(C-5000,1); i<= C+5000; i++) {
			ans=min(ans,solve(i,A,B)+abs(C-i));
		}
		return ans;
	}

};
