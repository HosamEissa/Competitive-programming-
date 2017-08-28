/*
 * CF101484-GYM-A.cpp.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: Hossam Eissa
 *      Idea: if x>mx or x< mn answer = -1 else if x in the array ans =1 else ans =2
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+6;
const double eps=1e-9;

int n,x;
int arr[N];
int main(){
	cin>>n>>x;
	int mx=-1,mn=1e5;
	for(int i=0;i<n;i++)
		cin>>arr[i],mx=max(mx,arr[i]),mn=min(mn,arr[i]);
	if(x>mx||x<mn){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			cout<<1<<endl;
			return 0;
		}
	}
	cout<<2<<endl;
	return 0;
}
