/*
Author: Hossam Eissa
Idea: look for the two strings in the first if not append them to it
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
int solve(string s1,string s2,string s3){
    vector<int>v=kmparr(s2+'#'+s1);

    string tmp=s1+s2.substr(v[v.size()-1]);
    for(int i=0;i<v.size();i++){
        if(v[i]==s2.size())
        {
            tmp=s1;
            break;
        }
    }
    v=kmparr(s3+'#'+tmp);
    string  tmp2=tmp+s3.substr(v[v.size()-1]);
    for(int i=0;i<v.size();i++){
        if(v[i]==s3.size()){
            tmp2=tmp;
            break;
        }
    }
    return tmp2.size();
}
int main()
{
    in;
   // FO;
   //int n1,n2;
   string s1,s2,s3;
   while(cin>>s1>>s2>>s3){
    vector<string>v={s1,s2,s3};
    sort(v.begin(),v.end());
    int ans=s1.size()+s2.size()+s3.size();
    do{
        ans=min(ans,solve(v[0],v[1],v[2]));
    }while(next_permutation(v.begin(),v.end()));
        cout<<ans<<endl;
   }


}
