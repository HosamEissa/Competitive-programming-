/*
 * UVA_10774.cpp
 *
 *  Created on: Aug 26, 2017
 *      Author: Hossam Eissa
 *      Idea: 
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e4 + 5;
const double eps = 1e-9;
int win[N];

int main() {
	for (int i = 2; i < N; i++) {
		win[i]=(2+win[i-1])%i;
	}
	for (int i = 1; i < N; i++) {
		win[i]++;
	}

	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		int n;
		scanf("%d",&n);
		int c=0;
		while(win[n]!=n){
			n=win[n];
			c++;
		}
		printf("Case %d: %d %d\n",tc,c,win[n]);
	}


	return 0;
}
