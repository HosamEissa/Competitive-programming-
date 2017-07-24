/*
Author: Hossam Eissa
Idea:for each circle look at the first point and last point and do line sweep to sum them
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Y second
#define X first
const double pi=acos(-1);
int n,d;
const int N=1e5+5;
ll X[N],Y[N],R[N];

int main()
{
     freopen("walk.in","r",stdin);
    in;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<double,ll>>v;
        for(int i=0; i<n; i++)
        {
            cin>>X[i]>>Y[i]>>R[i];
            if(abs(Y[i]) + R[i] > m) continue;
            double a,b,c;
            a=1;
            b=-2*X[i];
            c=(X[i]*X[i]+Y[i]*Y[i]-(m-R[i])*(m-R[i]));
            if(b*b-4*c<0)
            continue;
            double ans1=(-b+sqrt(b*b-4*c))/2;
            double ans2=(-b-sqrt(b*b-4*c))/2;
            if(ans1>ans2)swap(ans1,ans2);
            v.push_back({ans1,-R[i]});
            v.push_back({ans2,R[i]});
        }
        sort(v.begin(),v.end());
        ll ans=0;
        ll mx=0;
        for(int i=0; i<v.size(); i++)
        {
            ans+=(-v[i].second);
            // cout<<v[i].first<<" "<<-v[i].second<<" "<<ans<<endl;
            mx=max(mx,ans);
        }
        cout<<mx<<endl;
    }

}
