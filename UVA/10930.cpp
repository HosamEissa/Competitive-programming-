/*
Author: Hossam Eissa
Idea: try to take or leave every number
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
#define vi vector<int>
int n;
vector<int>v;
bool ans=1;
void solve(int idx,int sum){
   // cout<<idx<<" "<<sum<<endl;
    if(idx==n)return;
    if(ans==0)return ;
    if(sum>v.back())return;
    if(sum==v[idx]){
        ans=0;
        return;
    }
    solve(idx+1,sum);
    solve(idx+1,sum+v[idx]);
}
int main()
{

    int t=0;
    while(scanf("%d",&n)==1){
        v.clear();
        v.resize(n);
        ans=1;
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
            if(v[i]<0)
                ans=0;
            if(i&&v[i]<=v[i-1])ans=0;
        }
        printf("Case #%d:",++t);
        for(int i=0;i<v.size();i++){
            printf(" %d",v[i]);
        }
        if(ans){
                solve(0,0);
        }
        if(ans){
            printf("\nThis is an A-sequence.\n");
        }
        else {
            printf("\nThis is not an A-sequence.\n");

        }
    }
}
