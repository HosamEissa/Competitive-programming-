/*
Author: Hossam Eissa
Idea:DP on 2d grid
*/
#include <bits/stdc++.h>
#include <map>
using namespace std;
#define ll long long
#define se second
#define fi first
#define mk(a, b) make_pair(a, b)
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvpi vector<vector<pii>>
#define pli pair<ll, int>
#define INF (int)2e9
#define MOD 100000000
#define MAX (int)2e5 + 5
#define FI freopen("i.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sf(a, b) scanf("%d %d", &a, &b)
#define edge pair<pair<int, int>, int>
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 }; // 4 Directio
// int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
// int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
// 8 direction

// int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
// int dy[] = { 1,2,2,1,-1,-2,-2,-1};
// Knight Direction

const int N=1e2+5;
const double EPS=1e-1;
int dcmp(double a,double b)
{
    return fabs(a-b)<= EPS?0:a<b?-1:1;
}
int n,m;
ll dp[N][N];
int mat[N][N];
int arr[]= {0,1,-1};
int arr2[]= {1,-1,0};
int arr3[]= {-1,0,1};
ll solve(int row,int col)
{
    // cout<<"st-------- "<<row<<" "<<col<<endl;
    if(col==m)
    {
        //     cout<<"en------ "<<row<<" "<<col<<" "<<mat[row][col]<<endl;

        return dp[row][col]=mat[row][col];
    }
    ll &ans=dp[row][col];
    if(ans!=-1)return ans;
    ans=1e18;
    for(int i=0; i<3; i++)
    {
        int nr=row+arr[i];
        int nc=col+1;
        if(nr==0)nr=n;
        if(nr==n+1)nr=1;
        ans=min(ans,solve(nr,nc)+mat[row][col]);
    }
    //  cout<<"en------ "<<row<<" "<<col<<" "<<ans<<endl;
    return ans;
}
void f(int row,int col)
{
    if(col>1)cout<<" ";
    if(col==m)
    {
        cout<<row;

        return ;
    }
    for(int i=0;i<3; i++)
    {
        int nr,nc;
        if(row==1)
        {
            nr=row+arr[i];
            nc=col+1;
            if(nr==0)nr=n;
            if(nr==n+1)nr=1;
        }
        else if(row==n)
        {
            nr=row+arr2[i];
            nc=col+1;
            if(nr==0)nr=n;
            if(nr==n+1)nr=1;
        }
        else
        {
            nr=row+arr3[i];
            nc=col+1;
            if(nr==0)nr=n;
            if(nr==n+1)nr=1;
        }
        if(dp[nr][nc]==dp[row][col]-mat[row][col]){
            cout<<row;
            f(nr,nc);
            return;
        }
    }

}
int main()
{
    in;
    //  FO;
    //cout<<fixed<<setprecision(1);
    while(cin>>n>>m)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>mat[i][j];
            }
        }
        /* for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                 cout<<mat[i][j]<< " ";
             }
             cout<<endl;
         }*/
        memset(dp,-1,sizeof dp);
        ll ans=1e18,r=0;
        for(int i=1; i<=n; i++)
        {
            ll val=solve(i,1);
            if(val<ans)
            {
                ans=val;
                r=i;
            }
        }
        f(r,1);
        cout<<endl<<ans<<endl;
    }
}
