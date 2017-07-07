/*
Author: Hossam Eissa
Idea: take every two numbers and look at the intersection of the two strings
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
//const int mod=1000291;
//const int mod3=50001137;
const int mod=1000000007;
ll base,pw1,pw2,pw3,inv;
int k,n,m;
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
vector<int> getZarr(string s)
{

    string ans=s;
    vector<int>Z(ans.size());
    int l,r,k;
    l=r=0;
  //cout<<ans<<endl;
    for(int i=1; i<ans.size(); i++)
    {

        if(i>r)
        {


            l=r=i;
            while(r<ans.size()&&ans[r]==ans[r-l])
                r++;
            Z[i]=r-l;
            r--;
        }
        else
        {
            k=i-l;

            if(Z[k]<r-i+1)
                Z[i]=Z[k];
            else
            {
                l=i;
                while(r<ans.size()&&ans[r-l]==ans[r])r++;

                Z[i]=r-l;
                r--;
            }

        }
    }
    return Z;

}
int main()
{
    base=26;
    cin>>n>>m;
    string s,s2;
    cin>>s;
    bool ans=1;
    int perv=-1e8;
    vector<int>v=getZarr(s);
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
                if(a-perv>=s.size()){
                    n-=s.size();
                }
                else {
                        int c=a-perv;
                 //       cout<<"xxxxxxxxxxxx "<<c<<" "<<s.size()-c<<endl;
                        if(v[c]==s.size()-c){
                                n-=s.size()-v[c];
                        }
                        else {
                                ans=0;

                        }
                }
        perv=a;
    }
    if(!ans){
        cout<<0;
        return 0;
    }
   //cout<<n<<endl;
    cout<<fastpow(base,n,mod)<<endl;

}
