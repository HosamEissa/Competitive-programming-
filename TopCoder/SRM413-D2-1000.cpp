/*
Author: Hossam Eissa

Idea:Memorize with map

*/
#include <bits/stdc++.h>
#include<stdio.h>
#include <map>
#include<unordered_map>
using namespace std;
#define ll long long
class InfiniteSequence{
map<ll,ll>mp;
public:
long long calc(long long i,int a,int b){
return solve(i,a,b);
};
long long solve(long long i,int a,int b){	
	if(mp[i]>0)return mp[i];
	if(i==0)return 1;
	{
   	 return mp[i]=solve(i/a,a,b)+solve(i/b,a,b);
	}
}
};
