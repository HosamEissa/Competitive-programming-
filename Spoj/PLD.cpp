/*
Author: Hossam Eissa
Idea: Rabin Karp
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll base,pw1,inv;
int k,n;
ll fastpow(ll a,ll b)
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

void shiftright(ll & a,ll number,ll number2)
{
    a=(a-number+mod)%mod;
    a=(a*inv)%mod;
    a=(a+(number2*pw1)%mod)%mod;
}
int main()
{
    cin>>k;
    string s;
    cin>>s;
    if(k>s.size()){
            cout<<"0"<<endl;
        return 0;
    }
    n=s.size();
    base=26;
    inv=fastpow(base,mod-2);
    pw1=fastpow(base,k-1);
    ll a=0,b=0;
    for(int i=0;i<k;i++){
        shiftleft(a,0,s[i]-'a');
        shiftleft(b,0,s[k-i-1]-'a');
    }
    int res=0;
    for(int i=k;i<n;i++)
    {
        if(a==b)
            res++;
        shiftleft(a,s[i-k]-'a',s[i]-'a');
        shiftright(b,s[i-k]-'a',s[i]-'a');
    }
    if(a==b)res++;
    cout<<res<<endl;
}
