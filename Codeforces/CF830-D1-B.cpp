/*
Author: Hossam Eissa
Idea:range sum the deleted elemnts from idx to next min number
*/
#include <bits/stdc++.h>
using namespace std;
int n;
const int N=(1<<18);
#define ll long long
struct BIT {
	ll C[N];
	int n;
	void init(int n) {

		this->n = n = (1 << (int) ceil(log2(n)));

		memset(C, 0, n * sizeof(C[0]));
	}

	void add(int idx, ll valC) {
        idx++;
        while (idx <= n) {
			C[idx] += valC;
			idx += (idx & (-idx));
		}
	}
	ll get(int idx) {
		ll valC = 0;
		idx++;
		while (idx) {
			valC += C[idx];
			idx -= (idx & (-idx));
		}
		return valC;
	}

	int find(ll val) {
		int st = 0;
		for (int mid = (n >> 1); mid; mid >>= 1) {
			int idx = st + mid - 1;
			ll cur = C[idx];
			if (val > cur) {
				st += mid;
				val -= cur;
			}
		}
		return st;
	}
	void print(){
	    cout<<"\ntree st\n";
        for(int i=1;i<=n;i++)
            cout<<i<<" "<<C[i]<<endl;
	    cout<<"tree en\n\n";
	}

} bit;


int main()
{
    cin>>n;
    vector<pair<int,int> >v(n);
    set<pair<int,int> >st;
    for(int i=0; i<n; i++)
    {
       cin>>v[i].first;
      // v[i].first=n-i;
       v[i].second=i;
        st.insert(v[i]);
    }
    bit.init(n);
    sort(v.begin(),v.end());
    ll idx=0,ans=0;
    auto it=st.lower_bound({2,0});
    //cout<<it->first<<" "<<it->second<<endl;
    for(int i=0; i<n; )
    {
        auto it=st.lower_bound({v[i].first,idx});
        if(it==st.end()){
            ans+=n-idx;
            ans-=bit.get(n)-bit.get(idx-1);
            idx=0;
             it=st.lower_bound({v[i].first,idx});
        }
        if(it->first!=v[i].first){
                ans+=n-idx;
                ans-=bit.get(n)-bit.get(idx-1);
                idx=0;
                it=st.lower_bound({v[i].first,idx});
        }
        ans+=it->second-idx+1;
        ans-=bit.get(it->second)-bit.get(idx-1);
       // error(idx,v[i].first,it->second,st.size(),ans);
        bit.add(it->second,1);
      //  bit.print();
        idx=it->second+1;
        st.erase(it);
        i++;
    }
    cout<<ans<<endl;

}
