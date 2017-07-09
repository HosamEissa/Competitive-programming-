/*
Author: Hossam Eissa
Idea:get the binary of the two numbers if the same out 0 else flip equal bits
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include<queue>
#include <vector>
#include <set>
#include<cmath>
//#include<bits/stdc++.h>
#include <map>
#include<stack>
#include<iomanip>
using namespace std;
#define ll long long
#define MAX 200000+5
#define MOD 100000000
#define INF 10000000
ll n, n2, st = 0;
ll val[MAX], vis[MAX];

int comp(string s, int s2);
ll power(ll x, ll times){
	if (times == 0)return 1;
	return x*power(x, times - 1);
}
int get_diff(string s, string s2){
	for (int i = 0; i < s2.size(); i++){
		if (s[i] != s2[i])return i;
	}

	return -1;
}
int main()
{
	cin >> n >> n2;

	string s = "",s2="";
	for (int i = 0; (n2 >> i) != 0; i++){
		if ((n >> i) & 1)s += '1';
		else s += '0';
	};
	for (int i = 0; (n2 >> i) != 0; i++){
		if ((n2 >> i) & 1)s2 += '1';
		else s2 += '0';
	};
	reverse(s.begin(), s.end());
	reverse(s2.begin(), s2.end());
	//cout << s << endl << s2<<endl;
	int c = get_diff(s, s2);
	if (c == -1)cout << 0;
	else {
		for (int i = c; i < s2.size();i++)
		if (s[i] == s2[i]){
			if (s[i] == '1')s[i] = '0';
			else if (s[i] == '0')s[i] = '1';
		}
		string s3 = "";
		for (int i = 0; i < s2.size(); i++)
		{
			if (s[i] != s2[i])s3 += '1';
			else s3 += '0';
		}
		ll sum = 0;
		reverse(s3.begin(), s3.end());
		for (int i = 0; i <s3.size(); i++){
			if (s3[i] == '1')sum += power(2, i);
		}
		cout << sum;

	}








	//system ("pause");
	//return 0;
}
