/*
Author: Hossam Eissa
Idea: kmp then for each substring output answer if exist
*/
#include <bits/stdc++.h>
using namespace std;
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
int main()
{

    int n;
    int t=1;
    while(scanf("%d",&n)&&n)
    {
        printf("Test case #%d\n",t++);
        string s;
        cin>>s;
        vector<int>v=kmparr(s);
        for(int i=2; i<=v.size(); i++)
        {
            int vx=i-v[i-1];
            if(i!=vx&&i%vx==0)
            {

                printf("%d %d\n",i,i/vx);
            }
        }
        printf("\n");
    }


}
