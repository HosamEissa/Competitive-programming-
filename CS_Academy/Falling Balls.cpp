#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
int n,m;
const int N=1e5+5;
int x1[N],x2[N],Y1[N],ind[N];
int le[N],ri[N];
int seg[N];
int pos[N];
int dp[2][N];
bool cmp(int i,int j)
{
    return make_pair(x1[i],x2[i])<make_pair(x1[j],x2[j]);
}
int solve(int xx,int seid){
    if(seid==-1){
        return xx;
    }
    double md=(x1[seid]+x2[seid])/2.0;
    if(xx<=md){
            if(dp[0][seid]!=-1)
                return dp[0][seid];
        return dp[0][seid]=solve(x1[seid],le[seid]);
    }
    else {
            if(dp[1][seid]!=-1)
                return dp[1][seid];
        return dp[1][seid]=solve(x2[seid],ri[seid]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
                //x      type,idx
    vector<pair<int,pair<int,int> > >vp;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d",&x1[i],&x2[i],&Y1[i]);
        ind[i]=i;
        vp.push_back({x2[i]+1,{-1,i}});
        vp.push_back({x1[i],{0,i}});
    }
    /////       x,idx
    for(int i=0;i<m;i++){
        int a;
        scanf("%d",&a);
        pos[i]=a;
        vp.push_back({a,{1,i}});
    }
    //// y,idx;
    sort(vp.begin(),vp.end());
    memset(le,-1,sizeof le);
    memset(ri,-1,sizeof ri);
    memset(seg,-1,sizeof seg);
    memset(dp,-1,sizeof dp);
    set<pair<int,int> >st;
    set<pair<int,int> >::iterator it;
    for(int i=0; i<vp.size(); i++)
    {
        int x=vp[i].first;
        int type=vp[i].second.first;
        int idx=vp[i].second.second;
        if(type==0){
            it=st.upper_bound(make_pair(Y1[idx],-1));
            if(it!=st.begin())
            {
                it--;
                int idx2=it->second;
                le[idx]=idx2;
            }
            st.insert({Y1[idx],idx});
        }
        else if(type==1){
            it=st.end();
            if(it!=st.begin())
            {
                it--;
                int idx2=it->second;
                seg[idx]=idx2;
            }
        }
        else {
            it=st.upper_bound(make_pair(Y1[idx],-1));
            if(it!=st.begin())
            {
                it--;
                int idx2=it->second;
                ri[idx]=idx2;
            }
            st.erase({Y1[idx],idx});
        }
    }
    for(int i=0;i<m;i++){
        int x=pos[i];
        if(seg[i]==-1){
            printf("%d\n",x);
        }
        else {
                printf("%d\n",solve(x,seg[i]));

        }
    }

}
