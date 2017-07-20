/*
Author: Hossam Eissa
Idea:binary search the number of edges then use topological sort to check graph length
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N =1e5+5;
int n,m;
int indeg[N],ans[N];
vector<vector<int>>v2;
vector<pair<int,int> >v;

bool ok(int k){
    v2.clear();
   // cout<<k<<endl;
    v2.clear();
    memset(indeg,0,sizeof indeg);
    v2.resize(n+1);
    int cnt=n;
    for(int i=0;i<k;i++){
        v2[v[i].first].push_back(v[i].second);
        indeg[v[i].second]++;
        if(indeg[v[i].second]==1)cnt--;
    }
    if(cnt!=1)return 0;
    queue<pair<int,int> >q;
    int mx=0;
    for(int i=1;i<=n;i++)
        if(indeg[i]==0)q.push({0,i});
    while(!q.empty()){
        int node=q.front().second;
        int c=q.front().first;
        q.pop();
        mx=max(mx,c);
        for(auto i : v2[node]){
            indeg[i]--;
            if(indeg[i]==0)
            q.push({c+1,i});
        }
    }
    return mx==(n-1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v.push_back({a,b});
    }
    int l=1,r=m,ans=m;
    while(l<r){
   //         cout<<l<<" "<<r<<endl;
        int mid=(l+r)>>1;
        if(ok(mid)){
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    while(ok(ans))ans--;
    ans++;
    if(ans>m)ans=-1;
    printf("%d",ans);
}
