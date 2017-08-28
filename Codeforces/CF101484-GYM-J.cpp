/*
 * CF101484-GYM-J.cpp
 *
 *  Created on: Aug 27, 2017
 *      Author: Hossam Eissa
 *      Idea: the new edge alwayes will be equal to the bigger edge
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+6;
const double eps=1e-9;

int n,m;

int main(){
	cin>>n>>m;
	if(n>m)
		swap(n,m);
	cout<<m<<endl;
	return 0;
}
