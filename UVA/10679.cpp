/*
Author: Hossam Eissa
Idea: kmp the pattern and match
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
string s;
vector<int> kmparr(string s)
{
    vector<int>ret(s.size());
    int j=0;
    for(int i=1; i<s.size(); i++)
    {
        while(j&&s[i]!=s[j])j=ret[j-1];
        if(s[i]==s[j])j++;
        ret[i]=j;
    }
    return ret;

}
bool match(string b)
{
    int j=0;
    vector<int>ret=kmparr(b);
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==b[j])
        {
            j++;
        }
        else
        {
            while(j&&s[i]!=b[j])j=ret[j-1];
        }
        if(j==b.size())return 1;

    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        int q;
        scanf("%d",&q);
        while(q--)
        {
            string s2;
            cin>>s2;
            if(match(s2))
            {
                printf("y\n");
            }
            else
            {
                printf("n\n");
            }
        }

    }


}
