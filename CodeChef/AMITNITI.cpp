/*
Author: Hossam Eissa
Idea:generate all numbers in seqance less than 1e10 and divide them into 2 arrays and generate every possible sum from every array and then find the answer
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define start ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const double PI=acos(-1);
int n,m,k;
vector<ll>v;
int main()
{
    v.push_back(2);
    v.push_back(7);
    for(int i=2;;i++){
        if(i%2){
            v.push_back(v[i-1]+7);
        }
        else {
            v.push_back(v[i-1]+v[i-2]*3);
        }
        if(v.back()>=1e10)break;
    }
    v.pop_back();
    vector<ll>v1,v2;
    for(int i=0;i<v.size();i++)
    {
        if(i<v.size()/2)
            v1.push_back(v[i]);
        else v2.push_back(v[i]);
    }
    set<ll>st,st2;
    for(int i=0;i<(1<<16);i++){
            ll sum=0;
            for(int j=0;j<16;j++){
                if(i&(1<<j))
                sum+=v1[j];
            }
            st.insert(sum);
    }
    for(int i=0;i<(1<<16);i++){
            ll sum=0;
            for(int j=0;j<16;j++){
                if(i&(1<<j))
                sum+=v2[j];
            }
        st2.insert(sum);
    }
    start;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        bool ans=0;
        if(st.count(n)||st2.count(n))ans=1;
        for(auto i : st){
                if(i<n)
            if(st2.count(n-i)){
                ans=1;
                break;
            }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}
