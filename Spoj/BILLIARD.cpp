/*
 * SPOJ_BILLIARD.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Hossam Eissa
 *      Idea: get total distance in X and total distance in Y and get the angle from them then calculate the speed
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
const double PI = acos(-1);
int main() {
	int a, b, s, n, m;
	cout << fixed << " " << setprecision(2);
	while (cin >> a >> b >> s >> m >> n && (a || b || s || m || n)) {
		ll x = a * m;
		ll y = b * n;
		long double ang = atan2(y, x)*180.0/PI;
		long double speed = sqrt(x * x + y * y) / s;
		cout << ang << " " << speed << endl;
	}

	return 0;
}
