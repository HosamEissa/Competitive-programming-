/*
Author: Hossam Eissa
Idea: Rabin Karup hashing all the k substrings
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
const int mod=1000291;
const int mod3=50001137;
const int mod2=1000000007;
ll base,pw1,pw2,pw3,inv;
int k,n;
ll fastpow(ll a,ll b,int mod)
{
    ll ret=1;
    while(b)
    {
        if(b%2)
            ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret%mod;
}
void shiftleft(ll & a,ll number,ll number2)
{
    a=(a-(number*pw1)%mod+mod)%mod;
    a=(a*base)%mod;
    a=(a+number2)%mod;
}
void shiftleft3(ll & a,ll number,ll number2)
{
    a=(a-(number*pw3)%mod3+mod3)%mod3;
    a=(a*base)%mod3;
    a=(a+number2)%mod3;
}
void shiftleft2(ll & a,ll number,ll number2)
{
    a=(a-(number*pw2)%mod2+mod2)%mod2;
    a=(a*base)%mod2;
    a=(a+number2)%mod2;
}
void shiftright(ll & a,ll number,ll number2)
{
    a=(a-number+mod)%mod;
    a=(a*inv)%mod;
    a=(a+(number2*pw1)%mod)%mod;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    cin>>k;
    string s;
    cin>>s;
    n=s.size();
    base=128;
    pw1=fastpow(base,k-1,mod);
    pw2=fastpow(base,k-1,mod2);
    pw3=fastpow(base,k-1,mod3);

    ll a=0,b=0,c=0;
    map<pair<ll,pair<ll,ll> >,int>mp;
    for(int i=0;i<k;i++){
        shiftleft(a,0,s[i]);
        shiftleft2(b,0,s[i]);
        shiftleft3(c,0,s[i]);
    }
    mp[{a,{b,c}}]++;
    for(int i=k;i<n;i++)
    {
        shiftleft(a,s[i-k],s[i]);
        shiftleft2(b,s[i-k],s[i]);
        shiftleft3(c,s[i-k],s[i]);
        mp[{a,{b,c}}]++;
    }
    cout<<mp.size()<<endl;
    }
}
