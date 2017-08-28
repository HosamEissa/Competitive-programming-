/*
 * AtCoder079-ARC-B.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: Hossam Eissa
 *      Idea: do the opposite of the operation start with array 0 1 2 3 n-1 and try to do k operations 
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
const double eps=1e-9;
ll arr[51];
int main(){
	ll k;
	cin>>k;
	int n=50;
	for(int i=0;i<n;i++)
		arr[i]=i;
	ll x=k/n;
	k-=x*n;
	for(int i=0;i<n;i++)
		arr[i]+=x;
	for(int i=0;i<n&&k;i++,k--){
		arr[i]+=n+1;
		for(int j=0;j<n;j++){
			arr[j]--;
		}
	}
	cout<<n<<endl;
	for(int j=0;j<n;j++)
		cout<<arr[j]<<" \n"[j==n-1];
	return 0;
}
