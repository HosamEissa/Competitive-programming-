/*
Author: Hossam Eissa
	
	Idea: 
		- This is Easy number theory Problem (Generating divisors)	
    
    
 */
#include <bits/stdc++.h>
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
int main()
{
    FO;
    printf("PERFECTION OUTPUT\n");
    while(cin>>n&&n){
            vector<int>divs;

            ll sum=0;
            if(n>1)
            for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i>1){
                   if(i*i!=n)
                    {
                        divs.push_back(n/i);
                    sum+=n/i;
                    }
                }
                sum+=i;
                divs.push_back(i);
            }
        }

        printf("%5d  ",n);
        if(sum==n){
            printf("PERFECT\n");
        }
        else if(sum>n){
                        printf("ABUNDANT\n");
        }
        else {
                        printf("DEFICIENT\n");

        }
    }
    printf("END OF OUTPUT\n");
}
