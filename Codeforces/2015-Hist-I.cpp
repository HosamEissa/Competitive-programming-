/*
Author: Hossam Eissa

Idea:

*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include <map>
#include<unordered_map>
#include<complex>
using namespace std;
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


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
const int N = 1e4+ 50;
const double EPS=1e-8;
const double INF=2e15+5;
ll n, x,y;
ll mat[3][N];
bool answer;
int clockwise()
{
    int x1=x,y1=y;
    ll mn=1e18;
    int c=0,i,j,c2=1,c3;
    while(c2<=2*n)
    {
     //   cout<<x1<<" "<<y1<<endl;
      //  cout<<"done"<<endl;
        if(mat[x1][y1]==0)
        {
            i=x1;
            j=y1;
            c3=c2-1;
            mn=0;
            break;
        }
        if(mn>mat[x1][y1])
        {
            mn=mat[x1][y1];
            i=x1;
            j=y1;
            c3=c2-1;
         //   mat[x1][y1]--;
        }
        c++;
        if(x1==1)
        {
            if(y1==n)x1++;
            else y1++;
        }
        else
        {
            if(y1==1)x1--;
            else y1--;
        }
        c2++;
    }
    if(mn==-1)
    {
        answer=0;
        return -1;
    }
    ll cnt=c3+mn*2*n;
   // cout<<mn<<" "<<c3<<endl;
   // cout<<c<<" ----------"<<cnt<<endl;


       c2=1;
       x1=x;
       y1=y;

    while(c2<=2*n)
    {
        mat[x1][y1]-=mn;
        if(c3>0)mat[x1][y1]--;
        c3--;
         if(x1==1)
        {
            if(y1==n)x1++;
            else y1++;
        }
        else
        {
            if(y1==1)x1--;
            else y1--;
        }
        c2++;
    }




    mat[i][j]=cnt;
    if(i==1)
        answer=0;
    return cnt;
}

int main()
{
    // FO;
    in;
    int t=1;
    while(cin>>n>>x>>y)
    {
        if(!n&&!x&&!y)break;
        memset(mat,0,sizeof mat);
        cout<<"Case "<<t++<<":"<<endl;
        answer=1;
        for(int j=1; j<=2; j++)
            for(int i=1; i<=n; i++)
            {
                cin>>mat[j][i];
            }
        ll val=clockwise();
        if(!answer)
        {
            cout<<"INVALID"<<endl;
        }
        else
        {
            for(int j=1; j<=2; j++)
            {

                for(int i=1; i<=n; i++)
                {
                    cout<<mat[j][i]<<" ";
                }
                cout<<endl;
            }
        }

    }
}
