/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
#include<stack>
#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include <map>
#include<unordered_map>
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
#define ll  long long
#define FI freopen("interesting.in", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define edge pair<ll, pair<int, int>>
#define CYA  exit(0);
/*int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1}; //8 direction*/
/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int N = 1e6 + 5;
const double EPS = 1e-10;
const ll INF = 1e18;
const double PI = acos(-1);
ll n, m, k;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a<b ? -1 : 1;
}
int arr[26],prime[N];
vector<int>primes;
int getcnt(int a,int b){
    int res=0;
    while(a){
        res+=a/b;
        a/=b;
    }
    return res;
}
int power(int a,int b){
    a=a%10;
    int ret=1;
    while(b){
        if(b%2)
            ret=a*ret%10;
            b>>=1;
            a=a*a%10;
    }
    return ret;
}
int main()
{
    for(int i=2; i<N; i++)
    {
        if(!prime[i])
        {
            primes.push_back(i);
                for(int j=i; j<N; j+=i)
                {
                    prime[j]=1;
                }

        }
    }
       // in;
        char s[1000005];
        while(scanf("%s",s)==1)
        {
            n=strlen(s);
            memset(arr,0,sizeof arr);
            for(int i=0; i<n; i++)
            {
                arr[s[i]-'a']++;
            }
            vector<int>v;
            for(auto i:primes){
                int cnt=getcnt(n,i);
                    for(int j=0;j<26;j++){
                        cnt-=getcnt(arr[j],i);
                    }
                v.push_back(cnt);
            }
           //             cout<<"a7a"<<endl;

            int ans=1;
            int tens=min(v[0],v[2]);
            v[0]-=tens;
            v[2]-=tens;
            for(int i=0;i<v.size();i++){
                ans=ans*power(primes[i],v[i]);
                ans=ans%10;
            }
            printf("%d\n",ans);

        }
    }
