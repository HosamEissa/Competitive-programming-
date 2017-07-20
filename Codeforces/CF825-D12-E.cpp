/*
Author: Hossam Eissa
Idea:start from the biggest node and give every node degree 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N =1e5+5;
int n,m;
int indeg[N],ans[N];
vector<vector<int>>v2;
int main()
{
    scanf("%d%d",&n,&m);
    v2.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
            v2[b].push_back(a);
        indeg[a]++;
    }
    priority_queue<int>pq;
    for(int i=1;i<=n;i++)
       if(indeg[i]==0)pq.push(i);
    int cnt=n;

    while(!pq.empty()){
        int node=pq.top();
        pq.pop();
        for(auto i : v2[node])
        {
            indeg[i]--;
            if(indeg[i]==0)
                pq.push(i);
        }
        ans[node]=cnt--;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
}
