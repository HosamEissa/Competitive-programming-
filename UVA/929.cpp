/*
Author: Hossam Eissa

Idea:dijkstra 


*/
#include <bits/stdc++.h>
#include<stdio.h>
#include <map>
#include<unordered_map>
using namespace std;
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pf(a) printf("%d",a)
#define pf2(a,b) printf("%d %d",a,b)
#define pf3(a,b,c) printf("%d %d %d",a,b,c)
#define sfl(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pfl(a) printf("%lld",a)
#define pfl2(a,b) printf("%lld %lld",a,b)
#define pfl3(a,b,c) printf("%lld %lld %lld",a,b,c)
#define nl printf("\n")
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
#define INF 2e9+5
#define MAX (int)1e6 + 5
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define edge pair<ll, pair<int, int>>
#define CYA  exit(0);
#define pi acos(-1);
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
							/*int dx[]={1,1,0,-1,-1,-1,0,1};
							int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
							/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
							int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;
int n, m, k;
int mat[N][N];
int vis[N][N];
bool ok(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m)return 1;
    return 0;
}
int dikstra(){
priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > > ,greater<pair<int,pair<int,int> > > >q;
q.push({0,{0,0}});
vis[0][0]=mat[0][0];
while(!q.empty()){
    int cost=q.top().first;
    int x=q.top().second.first;
    int y=q.top().second.second;
    q.pop();
    if(x==n-1&&y==m-1)break;
    for(int k=0;k<=3;k++){
        int i=x+dx[k];
        int j=y+dy[k];
       // printf("%d %d %d %d\n",i,j,vis[x][y]+mat[i][j],vis[i][j]);
        if(ok(i,j)&&cost+mat[i][j]<vis[i][j]){
            vis[i][j]=vis[x][y]+mat[i][j];
            q.push({vis[i][j],{i,j}});
        }
    }
}

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              scanf("%d",&mat[i][j]);
                vis[i][j]=INF;
            }
        }
        dikstra();
        printf("%d\n",vis[n-1][m-1]);
	}

}
