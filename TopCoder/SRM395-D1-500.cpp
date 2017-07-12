/*
Author: Hossam Eissa
Idea:try to put item to the left or to the right or try to put the rest of the items in the middle
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[101][101][101];
class Skyscrapers{
const int mod=1e9+7;
public:
ll solve(int idx,int l,int r){
   // cout<<idx<<" "<<l<<" "<<r<<endl;
	if(idx==1)
        return (l==1)&&(r==1)?1:0;
	if(idx==0)return 0;
	if(!l||!r)return 0;
	ll &ans=dp[idx][l][r];
	if(ans!=-1)return ans;
	ans=0;
	ans=(solve(idx-1,l-1,r)%mod)+(solve(idx-1,l,r-1)%mod)+((idx-2)*solve(idx-1,l,r)%mod);
	ans=(ans%mod);
	return ans;
}
int buildingCount(int N, int leftSide, int rightSide)
{
	memset(dp,-1,sizeof dp);
	return 	(int)solve(N,leftSide,rightSide);
}
};
