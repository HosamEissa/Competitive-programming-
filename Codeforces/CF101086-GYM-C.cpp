/*
Author: Hossam Eissa
Idea:sort strings and add them into try for each node store mn and mx idx so u know what is your postion in every node
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define start ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const double PI=acos(-1);
int n,m,k;
struct node
{
    node * a[26];
    int mn,mx;
    node()
    {
        mn=1e9;
        mx=-1e9;
        for(int i=0; i<26; i++)
            a[i]=NULL;
    }
} *root;
void del(node* u)
{
    for(int i=0; i<26; i++)
        if(u->a[i]!=NULL)
            del(u->a[i]);
    delete u;
}
void insertnode(int idx,string s)
{
    node* cur=root;
    //cout<<idx<<" "<<s<<endl;
    cur->mn=min(cur->mn,idx);
    cur->mx=max(cur->mx,idx);
    for(int i=0; i<s.size(); i++)
    {
        if(cur->a[s[i]-'a']==NULL)
            cur->a[s[i]-'a']=new node();
        cur=cur->a[s[i]-'a'];
        cur->mn=min(cur->mn,idx);
        cur->mx=max(cur->mx,idx);
    }

}
int Find(int idx,string s)
{
    node* cur=root;
    int ans=idx+1;
    ans=min(ans,2+cur->mx-idx);
    for(int i=0; i<s.size(); i++)
    {
        cur=cur->a[s[i]-'a'];
        ans=min(ans,i+2+idx-cur->mn);
        ans=min(ans,i+3+cur->mx-idx);
    }
    return ans;
}
int main()
{
    start;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        root=new node();
        vector<pair<string,int>>vec(n);
        for(int i=0; i<n; i++)cin>>vec[i].first,vec[i].second=i;
        sort(vec.begin(),vec.end());
        vector<int>ans(n);
        for(int i=0; i<n; i++)
        {
            insertnode(i,vec[i].first);
        }
        for(int i=0; i<n; i++)
        {
            ans[vec[i].second]=Find(i,vec[i].first);
        }
        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        del(root);
    }
}
