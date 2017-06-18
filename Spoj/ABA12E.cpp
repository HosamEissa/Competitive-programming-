/*
Author: Hossam Eissa

Idea:binary search over all sums less than or equal X

*/
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include <map>
#include<complex>
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
#define ll  long long int
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
const int N = 5e4+ 50;
const double EPS=1e-8;
const double INF=2e15+5;
ll n, m, k;
ll arr[N];
bool ok(ll mid){

int st=1,en=1;
ll sum=0,tot=0;
while(en<=n){
    sum+=arr[en];
    en++;
    while(sum>mid&&st<en){
    sum-=arr[st];
    st++;
    }
    if(sum<=mid){
        tot+=en-st;
    }

   // cout<<st<<" "<<en<<" "<<sum<<" "<<mid<<" "<<tot<<endl;
}
if(tot<k)return 1;
return 0;
}
int main()
{
    while(cin>>n>>k){
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        ll l=0,r=1e15,ans=0;
        while(l<r){
            ll mid=(l+r)/2;
            //cout<<endl;
                if(ok(mid)){
                    l=mid+1;
                    ans=mid;
                }
                else {
                    r=mid-1;
                }
        }
        while(ok(ans))ans++;
        ans--;
        cout<<ans+1<<endl;

    }



}
