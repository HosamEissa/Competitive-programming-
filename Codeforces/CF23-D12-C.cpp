/*
 * CF23-D12-C.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: Hossam Eissa
 *      Idea: 
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<pair<int,pair<int,int> > >v(2*n-1);
		n=2*n-1;
		ll total=0;
		for (int i = 0; i < n; i++)
			scanf("%d%d", &v[i].first, &v[i].second.first),v[i].second.second=i,total+=v[i].second.first;
		sort(v.begin(),v.end());
		ll odd=0;
		ll even=0;
		vector<int>ans,ans2;
		for(int i=0;i<n;i++){
			if(i%2==0){
				odd+=v[i].second.first;
				ans.push_back(v[i].second.second+1);
			}
			else {
				even+=v[i].second.first;
				ans2.push_back(v[i].second.second+1);
			}
		}
		even+=v.back().second.first;
		ans2.push_back(v.back().second.second+1);
		cerr<<odd<<" "<<even<<" "<<total<<endl;
		if(odd*2>=total){
			printf("YES\n");
			sort(ans.begin(),ans.end());
			for(int i=0;i<ans.size();i++)
			{
				if(i)printf(" ");
				printf("%d",ans[i]);
			}
			puts("");


		}
		else if(even*2>=total){
			printf("YES\n");
			sort(ans2.begin(),ans2.end());
			for(int i=0;i<ans2.size();i++)
			{
				if(i)printf(" ");
				printf("%d",ans2[i]);
			}
			puts("");

		}
		else printf("NO\n");
	}
	return 0;
}
