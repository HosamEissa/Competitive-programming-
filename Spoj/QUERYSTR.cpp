/*
Author: Hossam Eissa
Idea: rev(s)+rev(s) Z table then get answer from back
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> getZarr(string s,string s2)
{

    string ans=s+"$"+s2;
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
    in;
   int t;
   cin>>t;
   while(t--){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    vector<int>Z=getZarr(s,s);
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        int x=s.size()-a;
        //cout<<x<<" "<<s.size()+x<<" "<<Z[s.size()]<<endl;
        cout<<Z[s.size()+x+1]<<endl;
    }
   }


}
