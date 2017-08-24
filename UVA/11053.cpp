/*
 * UVA_11053.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: Hossam Eissa
 *      Idea: generate the seqance till you match number for the third time
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
const double eps=1e-9;
int main(){
	ll n,a,b;
	while(scanf("%lld",&n)&&n)
	{
		scanf("%lld%lld",&a,&b);
		ll cur=0;
		map<ll,int>mp;
		int cnt=0;
		while(mp[cur]!=2)
		{
			mp[cur]++;
			if(mp[cur]==2)cnt++;
			cur=((a*((cur%n*cur%n)%n))%n+b)%n;
		}
		printf("%d\n",n-cnt);
	}
	return 0;
}
