/*
Author: Hossam Eissa
Idea:generate all the p permutation after applying at most k steps in both ways normal and inverse and then check the answer 
(handle case 0 and 1 sepratly from the rest of the solution)
*/
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
int n,k;
map<vector<int>,int>le,ri;
vector<int>q,v;
int main()
{
    cin>>n>>k;
    q.resize(n);
    vector<int>v(n+1),v2(n+1),v3(n+1);
    for(int i=1;i<=n;i++)
        v[i]=i,cin>>q[i];
    le[v]=0;
    ri[v]=0;
    int twoways=0;
    for(int i=1;i<=max(n,k);i++){
        for(int i=1;i<=n;i++){
            v2[i]=v[q[i]];
        }
        v=v2;

        /*cout<<"idx = "<<i<<endl;
        for(auto i : v)
            cout<<i<<" ";
        cout<<endl;*/
         if(ri.count(v))
            break;
        ri[v]=i;
    }
    for(int i=0;i<=n;i++)
        v[i]=i;
    for(int i=1;i<=max(n,k);i++){
        for(int i=1;i<=n;i++){
            v2[q[i]]=v[i];
        }
        v=v2;
   /* cout<<"idx = "<<i<<endl;
        for(auto i : v)
            cout<<i<<" ";
        cout<<endl;*/
      if(le.count(v))
        break;
        le[v]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>v3[i];
    }
    if(!ri.count(v3))
        ri[v3]=1e9;

    if(!le.count(v3))
        le[v3]=1e9;
    if(ri[v3]==0){
        cout<<"NO"<<endl;
    }
    else {
            int cost1=ri[v3];
            int cost2=le[v3];
            if(k<cost1&&k<cost2){
                cout<<"NO"<<endl;
            }
            else if(cost1==k||cost2==k){
                    cout<<"YES"<<endl;
            }
            else if(cost1==1&&cost2==1){
                    cout<<"NO"<<endl;
            }
            else{
                if(cost1%2==k%2&&k>=cost1||cost2%2==k%2&&k>=cost2){
                    cout<<"YES"<<endl;
                }
                else cout<<"NO"<<endl;

            }
    }
    ri.clear();
    le.clear();

    return 0;
}
