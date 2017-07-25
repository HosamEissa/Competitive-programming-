/*
Author: Hossam Eissa
Idea:for each col loop on all circles and find the intersections of them using line sweep algorithm
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const double PI=acos(-1);
ll n,m,k;
int X[N],Y[N],R[N],V[N];
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>X[i]>>Y[i]>>R[i]>>V[i];
    }
    ll mx=0,cnt=0;
    for(int i=1;i<=m;i++){
        vector<pair<int,int>>v;
        for(int j=0;j<k;j++){
            double a,b,c;
            a=1;
            b=-2*Y[j];
            c=((X[j]-i)*(X[j]-i)+(Y[j])*(Y[j])-(R[j])*(R[j]));
            if(X[j]+R[j]<i)continue;
            if(X[j]-R[j]>i)continue;
//            if(b*b-4*c<0)
  //          continue;
            double ans1=(-b+sqrt(b*b-4*c))/2;
            double ans2=(-b-sqrt(b*b-4*c))/2;
            if(ans1>ans2)
                swap(ans1,ans2);
            ll a1=ceil(ans1);
            ll a2=ans2;
            v.push_back({max(a1,1LL),-V[j]});
            v.push_back({min(a2,n),V[j]});
         //   cout<<X[j]<<" "<<Y[j]<<" "<<R[j]<<endl;
         //   cout<<"j = "<<j<<" "<<ans1<<" "<<ans2<<" "<<a1<<" "<<a2<<" "<<endl;
        }
        sort(v.begin(),v.end());
        ll ans=0;
        int perv=1;
       // cout<<"row = "<<i<<" "<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            if(ans==mx)
            {
                cnt+=v[i].first-perv;
            }
            ans+=-v[i].second;
             if(mx<ans){
                mx=ans;
                cnt=0;
            }
            if(mx==ans)cnt++;
            perv=v[i].first;
       //     cout<<v[i].first<<" "<<-v[i].second<<" "<<ans<<" "<<mx<<" "<<cnt<<endl;
        }
       //  cout<<"max = "<<mx<<" cnt = "<<cnt<<endl;
    }
    cout<<mx<<" "<<cnt<<endl;

}
