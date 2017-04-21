/*
Author: Hossam Eissa

	Idea:Sum the two numbers then revearse the summtion (strings)


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
int main()
{
    //FO;
    int t;
    cin>>t;
    while(t--){
    string a,b;
    cin>>a>>b;
    while(a.size()<b.size()){
        a.push_back('0');
    }
    while(b.size()<a.size())
        b.push_back('0');
    vector<char>v1(a.size()),v2(a.size());
    for(int i=0;i<v1.size();i++){
        v1[i]='0';
        v2[i]='0';
    }
    vector<char>v3=v1;
    for(int i=0;i<a.size();i++){
    v1[i]=a[i];
    //cout<<v1[i];
    }
    //cout<<endl;
    for(int i=0;i<b.size();i++){
    v2[i]=b[i];
    //    cout<<v2[i];
    }
    int c=0;
    for(int i=0;i<v1.size();i++){
    int a=v1[i]-'0';
    int b=v2[i]-'0';

    int sum=a+b+c;
    v3[i]=(sum%10)+'0';
    c=sum/10;
    }
    if(c)v3.push_back(c+'0');
    bool x=0;
    reverse(v3.begin(),v3.end());
    for(int i=v3.size()-1;i>=0;i--){
        if(v3[i]=='0'&&!x)continue;
        else x=1,cout<<v3[i];
    }
    cout<<endl;
    }
}
