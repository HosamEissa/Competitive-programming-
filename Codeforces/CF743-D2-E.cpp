/*
Author: Hossam Eissa
Idea:binary search the maximum length you can get and check if it is valid using dp
*/
#include <bits/stdc++.h>
using namespace std;


#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c)
{
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        v.emplace_back(x);
    return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args)
{
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
    err(++it, args...);
}
//*/
#define ll  long long
ll n,m;
vector<int>u,l;
int total=0;
int dp[1005][1<<8];
int vis[1005][1<<8];
vector<vector<int>>pre;
int arr[1001];
int id=1;
int k=0;
int ok(int idx=1,int msk=0)
{
    //error(idx,msk,id);
    // cout<<endl;
    if(msk==(1<<8)-1)return vis[idx][msk]=id,dp[idx][msk]=0;
    if(idx==n+1)return vis[idx][msk]=id,dp[idx][msk]=-1e9;
    if(vis[idx][msk]==id)return dp[idx][msk];
    vis[idx][msk]=id;
    int ans=-1e9;
    for(int i=0; i<8; i++)
    {
        if(!(msk&(1<<i)))
        {
            int nmsk=msk|(1<<i);
            int nidx=lower_bound(pre[i].begin(),pre[i].end(),pre[i][idx-1]+k)-pre[i].begin();
            if(nidx<n+1&&pre[i][nidx]-pre[i][idx-1]==k)
            {
                ans=max(ans,k+ok(nidx+1,nmsk));
            }
            nidx=lower_bound(pre[i].begin(),pre[i].end(),pre[i][idx-1]+k+1)-pre[i].begin();
            if(nidx<n+1&&pre[i][nidx]-pre[i][idx-1]==k+1)
            {
                ans=max(ans,1+k+ok(nidx+1,nmsk));
            }


        }
    }
    return dp[idx][msk]=ans;

}
int main()
{
    cin>>n;
    pre.resize(10,vector<int>(n+1));
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        arr[i]--;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<8; j++)
        {
            pre[j][i]=pre[j][i-1]+(arr[i]==j);
        }
    }

    int l=1,r=n,ans=1;

    while(l<r)
    {
        id++;
        int mid=(l+r)>>1;
        k=mid;
        if(ok()>=8*mid)
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    k=ans;
    id++;
    while(ok()>=8*ans)
    {
        id++;
        ans++;
        k=ans;
    }
    id++;
    ans--;
    k=ans;
    //cout<<k<<endl;
    if(k==0){
            set<int>st;
        for(int i=1;i<=n;i++){
        st.insert(arr[i]);
        }
        cout<<st.size()<<endl;
    }
    else cout<<ok()<<endl;
}
