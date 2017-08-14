/*
Author: Hossam Eissa
Idea:convert points to king distance and get maximum distance between every two values
*/
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
int n,m,k,k2;
vector<vector<vector<int> > >cnt(10,vector<vector<int>>(2));
int main()
{
   // cin>>n>>m>>k>>k2;
    scanf("%d%d%d%d",&n,&m,&k,&k2);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int a;
            scanf("%d",&a);
            cnt[a][0].push_back(i+j);
            cnt[a][1].push_back(i-j);
            //   cout<<a<<" "<<i+j<<" "<<i-j<<endl;
        }
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<2; j++)
        {
            sort(cnt[i][j].begin(),cnt[i][j].end());
        }
    }
    vector<int>v(k2);
    int ans=0;
    for(int i=0; i<k2; i++)scanf("%d",&v[i]);
    for(int i=1; i<k2; i++)
    {
        int val=v[i];
        int val2=v[i-1];
        //cout<<val<<" "<<val2<<" ";
            int mx=cnt[val][0].back();
            int mn=cnt[val2][0][0];
            //cout<<mx<<" "<<mn<<" ";
            ans=max(ans,mx-mn);

            mx=cnt[val2][0].back();
            mn=cnt[val][0][0];
            //cout<<mx<<" "<<mn<<" ";
            ans=max(ans,mx-mn);

            mx=cnt[val2][1].back();
            mn=cnt[val][1][0];
            //cout<<mx<<" "<<mn<<" ";
            ans=max(ans,mx-mn);


            mx=cnt[val][1].back();
            mn=cnt[val2][1][0];
            //cout<<mx<<" "<<mn<<" ";
            ans=max(ans,mx-mn);

          //  cout<<endl;
    }
    printf("%d",ans);


    return 0;
}
