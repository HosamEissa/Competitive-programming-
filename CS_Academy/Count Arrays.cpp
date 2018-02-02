/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int MOD=1e9+7;
int r[N];
int ans[N];
int sum[N];
int main() {
    ios_base::sync_with_stdio();
    int n,q;
    cin>>n>>q;
    for(int i=0;i<=n+1;i++)
        r[i]=n+1;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        r[a-1]=min(r[a-1],b);
    }
    for(int i=n;i>=0;i--){
        r[i]=min(r[i],r[i+1]);
    }
    sum[n]=1;
    for(int i=n;i>=0;i--){
            if(r[i]>n){
                ans[i]=sum[i];
                sum[i-1]=(sum[i]+ans[i])%MOD;
            }
            else {
           //     cout<<"op2 "<<sum[i]<<" "<<sum[r[i]]<<endl;
                ans[i]=((sum[i]-sum[r[i]])+MOD)%MOD;
                if(i-1>=0)
                    sum[i-1]=(sum[i]+ans[i])%MOD;
            }
          //  cout<<i<<" "<<r[i]<<" "<<ans[i]<<" "<<sum[i-1]<<endl;
    }
    cout<<ans[0]<<endl;
}
