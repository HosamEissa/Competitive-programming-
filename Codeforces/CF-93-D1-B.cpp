/*
Author: Hossam Eissa
Idea: search for suffix appeared more than ones
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
    string s;
    cin>>s;
    vector<int>v=kmparr(s);
    int val=v[v.size()-1];
    for(int i=1;i<v.size()-1;i++){
        if(val&&v[i]==val){
            cout<<s.substr(0,val);
            return 0;
        }
    }
    if(val&&v[val-1]!=0){
        cout<<s.substr(0,v[val-1]);
        return 0;
    }

    cout<<"Just a legend"<<endl;
}
