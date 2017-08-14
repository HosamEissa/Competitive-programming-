/*
Author: Hossam Eissa
Idea:use nested loop to try every two elemnts as start of the seqance and get the seqance 
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
#define ll long long
vector<ll>v;
ll mx=-1e18,mn=1e18;
void solve(){
	int n;
	cin>> n;
	v.resize(n);
	map<ll,int>st;
	int z=0;
	for (int i = 0; i< v.size(); i++){
		cin>>  v[i];
		mx=max(mx,v[i]);
		mn=min(mn,v[i]);
        st[v[i]]++;
        z+=(v[i]==0);
    }
	//sort(v.begin(), v.end());
	//cout<<z<<endl;
	int ans = max(2,z);
	for (int i = 0; i< n; i++){
		for (int j = i + 1; j<n; j++){
			ll a=v[i];
			ll b=v[j];
			//cout<<a<<" "<<b<<" ";
			if(a==b&&st[a]<2)continue;
			if(a==b&&a==0){
                    continue;
			}
			vector<ll>v2;
			v2.push_back(a);
			v2.push_back(b);
			st[a]--;
			st[b]--;
			for(int x=3;;x++){
                if(!st.count(a+b))break;
                if(st[a+b]==0)break;
                st[a+b]--;
                ll c=b+a;
                //cout<<a<<" "<<b<<" "<<c<<" "<<x<<endl;
                v2.push_back(c);
                a=b;
                b=c;
                ans=max(ans,x);
			}
			for(auto i : v2)
                st[i]++;
			v2.clear();
			b=v[i];
			a=v[j];
			st[a]--;
			st[b]--;
			v2.push_back(a);
			v2.push_back(b);
			for(int x=3;;x++){
                if(!st.count(a+b))break;
                if(st[a+b]==0)break;
                st[a+b]--;
                ll c=b+a;
                v2.push_back(c);
                a=b;
                b=c;
                ans=max(ans,x);
			}
			for(auto i : v2)
                st[i]++;
      //  for(auto i : st)
       //     cout<<i.first<<" "<<i.second<<endl;
//		cout<<v[i]<<" "<<v[j]<<" "<<ans<<endl;
		}
	}
	cout << ans;
}
int main(){
	solve();
	//system("pause");
	return 0;
}
