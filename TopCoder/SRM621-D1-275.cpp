/*
Author: Hossam Eissa
Idea:for each circle look at the starting point and end point it will be bad in and if at some point all the circles are good add to the answer
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 2000000000;
const double PI=acos(-1);
class RadioRange{
public :
    vector<pair<double,int>>v;
    int cnt=0;
    void get(ll x,ll y,ll r){
            double dist=hypot(x,y);
          // cout<<x<<" "<<y<<" "<<r<<" "<<dist<<" "<<dist-r<<" "<<dist+r<<endl;
            if(dist>r){
                    double l=dist-r;
                    v.push_back({l,-1});
            }
            else cnt--;
            v.push_back({dist+r,1});
    }
    double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z)
    {
        int n=X.size();
        for(int i=0;i<n;i++){
        get(X[i],Y[i],R[i]);
        }
        v.push_back({Z,-99999999});
        sort(v.begin(),v.end());
        double ans=0;
        double perv=0;
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
          //      cout<<i<<" "<<v[i].first<<" "<<v[i].second<<" "<<perv<<" "<<cnt<<endl;
            if(cnt==0){
                ans+=v[i].first-perv;
            }
        if(v[i].first>=Z)break;
            cnt+=v[i].second;
            perv=v[i].first;
        }
        cout<<ans<<endl;
        return ans/Z;//min(1.0,ans/Z);

    }
};


}
