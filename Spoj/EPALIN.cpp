/*
Author: Hossam Eissa
Idea: Z table
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
vector<int> getZarr(string s,string s2)
{

    string ans=s2+"$"+s;
    vector<int>Z(ans.size());
    int l,r,k;
    l=r=0;
   // cout<<ans<<endl;
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
    in;
    string s,pat;
    while(cin>>s)
    {
        pat=s;
        reverse(pat.begin(),pat.end());
        vector<int>Z=getZarr(s,pat);
        int mx=0,idx=0;
        for(int i=s.size(); i<Z.size(); i++)
        {
           // cout<<i<<" "<<Z[i]<<endl;
            if(Z[i]+i==Z.size()&&mx<=Z[i]){
                mx=Z[i];
            }
        }
        cout<<s+pat.substr(mx)<<endl;
    }


}
