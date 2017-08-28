/*
 * CF101484-GYM-G.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: Hossam Eissa
 *      Idea: use floyed to get minmum cost from every pair of chars then use dp to try every possible configration 
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+6;
const double eps=1e-9;

int n,x;
int adj[26][26];
void floyed(){
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			for(int k=0;k<26;k++)
				adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);
}
int dp[10004][27];
int solve(int idx,int l){
	if(idx==n)
		return 0;
	int &ans=dp[idx][l];
	if(dp[idx][l]!=-1)
		return dp[idx][l];
	ans=1e9+5;
	for(int j=0;j<26;j++)
		ans=min(ans,solve(idx+1,j)+adj[l][j]);
	return ans;
}
int main(){
	memset(dp,-1,sizeof dp);
	cin>>n;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			cin>>adj[i][j];
		}
	}
	floyed();
	int ans=1e9+5;
	for(int i=0;i<26;i++)
		ans=min(ans,solve(1,i));
	cout<<ans<<endl;
	return 0;
}
