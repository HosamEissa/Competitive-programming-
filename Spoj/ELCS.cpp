/*
Author: Hossam Eissa
Idea: hash all the prefixs of every string and then binary search the answer
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
//const int mod=1000291;
//const int mod3=50001137;
const int mod=1000000007;
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
void shiftleft(ll & a,ll number,ll number2,int mod)
{
   // a=(a-(number*pw)%mod+mod)%mod;
    a=(a*base)%mod;
    a=(a+number2)%mod;
}
void shiftright(ll & a,ll number,ll number2,ll pw,int mod)
{
    a=(a-number+mod)%mod;
    a=(a*inv)%mod;
    a=(a+(number2*pw)%mod)%mod;
}
vector<vector<ll>>v;
char s[500005];
int main()
{
    base=128;
    int n;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++){
     //   v[i].resize(s.size());
        scanf("%s",s);
        int n=strlen(s);
        ll a=0;
        for(int j=0;j<n;j++){
            shiftleft(a,0,s[j],mod);
            v[i].push_back(a);
        }
    }
    scanf("%d",&k);

    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        int l=0,r=min(v[a].size(),v[b].size()),ans=0;

        while(l<r){
            int mid=(l+r)>>1;
         //   cout<<l<<" "<<r<<" "<<mid<<" "<<v[a][mid]<<" "<<v[b][mid]<<endl;
            if(v[a][mid]==v[b][mid]){
                l=mid+1;
                ans=mid;
            }
            else {
                r=mid-1;
            }
        }
        while(v[a][ans]==v[b][ans]&&ans<min(v[a].size(),v[b].size())){
          //  cout<<ans<<" "<<v[a][ans]<<" "<<v[b][ans]<<endl;

            ans++;
        }
        printf("%d\n",ans);
    }



}
