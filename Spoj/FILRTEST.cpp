/*
Author: Hossam Eissa
Idea: look at longest suffix = prefix
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
vector<int> kmparr(string s)
{
    vector<int>ret(s.size());
    int j=0;
    for(int i=1;i<s.size();i++){
        while(j&&s[i]!=s[j])j=ret[j-1];
        if(s[i]==s[j])j++;
        ret[i]=j;
    }
    return ret;

}

int main()
{
    in;
    string s,pat;
    int n;
    while(cin>>n>>s&&n>0)
    {
        if(n<s.size()){
            cout<<0<<endl;
            continue;
        }
        vector<int> v=kmparr(s);
        //for(int i=0;i<v.size();i++){
        //    cout<<i<<" "<<v[i]<<endl;
        //   }
        n-=v.size();
        int val=v.size()-v[v.size()-1];
        //cout<<n<<endl;
        cout<<n/val+1<<endl;

    }


}
