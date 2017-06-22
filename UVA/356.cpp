/*
Author: Hossam Eissa
Idea: try all points for every cell
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
int dx[] = { 0, 1, 0, 1 };
int dy[] = { 0, 0, 1, 1 }; // 4 Direction*/
/*int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int N = 5e2 + 5;
const double EPS = 1e-10;
const ll INF = 1e18;
const double PI = acos(-1);
ll n, m, k;
double r;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a<b ? -1 : 1;
}
bool ok(int x1,int y1,int x2,int y2)
{
   // cout<<x1 <<" "<<y1<<" "<<x2<<" "<<y2<<" "<<r*r<<" "<<(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<<endl;
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=r*r;
}
int main()
{
    in;
    int t=0;
    while(sf(n)==1)
    {
        r=(2*n-1)/2.0;
        if(t++)printf("\n");
        int cnt1,cnt2;
        cnt1=cnt2=0;
        for(int i=0; i<2*n; i++)
        {
            for(int j=0; j<2*n; j++)
            {
                int cnt=0;
                for(int k=0; k<4; k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    cnt+=ok(x,y,n,n);
                }
                if(cnt==4){
                    cnt1++;
                }
                else cnt2+=cnt==0?0:1;
            //    cout<<i<<" "<<j<<" "<<cnt<<endl;
            }
        }
        printf("In the case n = %d, %d cells contain segments of the circle.\n",n,cnt2);
        printf("There are %d cells completely contained in the circle.\n",cnt1);

    }

}
