/*
Author: Hossam Eissa
Idea: the left lower point should be intersection point of two points or intersection point moved at most T
so try all the possible starts
*/
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
class CrouchingAmoebas{
public:
    int count(vector <int> x, vector <int> y, int A, int T){
        int n=x.size();
        int ans=0;
        for(int t1=-T;t1<=T;t1++){
            for(int t2=-T;t2<=T;t2++){
                if(abs(t1)+abs(t2)>T)continue;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        ans=max(ans,solve(x[i]+t1,y[j]+t2,x,y,A,T));
                    }
                }
            }
        }
        return ans;
    }
    ll getdiff(int x,int y,ll A,ll stx,ll sty){
        ll ret=0;
        if(!(stx<=x&&x<=stx+A)){
            ret+=min(abs(stx-x),abs(x-(stx+A)));
        }
        if(!(sty<=y&&y<=sty+A)){
            ret+=min(abs(sty-y),abs(y-(sty+A)));
        }
        return ret;
    }
    int solve(int stx,int sty,vector <int> x, vector <int> y, int A, int T){
        vector<ll>distances;
        int n=x.size();
        for(int i=0;i<n;i++){
            distances.push_back(getdiff(x[i],y[i],A,stx,sty));
        }
        sort(distances.begin(),distances.end());
        int cnt=0;
        for(int i=0;i<distances.size();i++){
            if(distances[i]>T)break;
            cnt++;
            T-=distances[i];
        }
        return cnt;
    }


};

int main()
{
}


