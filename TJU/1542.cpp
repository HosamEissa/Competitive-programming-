/*
Author: Hossam Eissa

Idea:

*/
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include <map>
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
const int N = 1e7 + 5;
int n, m, d;
int prime[1000005];
int arr[1005];
int sum[1005];
bool vis[1001];
bool ans;
int answer[1005];
bool isprime(int x)
{
    if(x<2)return 0;
    for(int i=2; i*i<=x; i++)if(x%i==0)return 0;
    return 1;
}
bool ok(int pos){
    for(int i=2;i<=min(pos,d);i++){
            if(prime[sum[pos-1]-sum[pos-i-1]])
             return 0   ;
    }
    return 1;
}
void solve(int pos)
{
    if(ok(pos))
    {
        if(pos==m-n+2)
        {
            if(!ans){
                ans=1;
                for(int i=1;i<=pos;i++)answer[i]=arr[i];
            }
            return ;
        }

        for(int i=n; i<=m; i++)
        {
            if(vis[i])
                continue;
            vis[i]=1;
            arr[pos]=i;
            sum[pos]=arr[pos]+sum[pos-1];
            solve(pos+1);
            if(ans)return ;
            vis[i]=0;
        }
    }

}
int main()
{
    in;
    for(int i=1; i<=1e6; i++)
    {
        prime[i]=isprime(i);
    }
    while(cin>>n>>m>>d)
    {
        if(!n&&!m&&!d)break;
        memset(vis,0,sizeof vis);
        memset(answer,0,sizeof arr);
        memset(sum,0,sizeof arr);
        memset(arr,0,sizeof arr);
        ans=0;
        solve(1);
        if(ans)
        {
            for(int i=1; i<=m-n+1; i++)
            {
                if(i-1)cout<<",";
                cout<<answer[i];
            }
            cout<<endl;
        }
        else cout<<"No anti-prime sequence exists."<<endl;
    }
}
