/*
Author: Hossam Eissa

	Idea:Get Prime factors


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
/*int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
/*int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
ll n, m, k;
bool vis[N];
int main()
{
    //FO;
    vector<int>primes;
    for(int i=2;i*i<=1e6;i++){
        if(!vis[i]){
        primes.push_back(i);
        for(int j=i*i;j<=1e6;j+=i)
        vis[j]=1;
        }
    }
    vector<int>lucky;
    lucky.push_back(0);
    for(int i=1;i<1e6;i++){
        int tmp=i;
        int cnt=0;
        for(auto j:primes){
            if(j<=tmp&&(tmp%j)==0){

               while(tmp%j==0) tmp/=j;
                cnt++;
            }
        }
        if(cnt>=3)
            lucky.push_back(i);
            if(lucky.size()>1000)break;
    }
    int t;
    cin>>t;
    while(t--){
        cin>>n;
    cout<<lucky[n]<<endl;
    }
}
