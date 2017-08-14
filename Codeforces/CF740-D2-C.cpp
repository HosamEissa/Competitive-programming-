/*
Author: Hossam Eissa
Idea:the shortest interval is the maximum value of the mex
*/
#include<bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FI freopen("fegla.in","r",stdin);
#define FO freopen("o.txt","w",stdout);
#define N 262144
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define INF 1<<20
//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, 1, 0, -1 }; // 4 Direction
// int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
// int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};// 8 direction
//int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
//int dy[] = { 1,2,2,1,-1,-2,-2,-1};// Knight Direction
int n,m,t,mx;
int main()
{

    cin>>n>>m;
    int mx=n;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mx=min(b-a+1,mx);
    }
    cout<<mx<<endl;
    int cn=0;
    for(int i=0;i<n;i++){
        cout<<cn++<<" ";
        if(cn==mx)cn=0;
    }


    //cout<<ans<<endl;
}
