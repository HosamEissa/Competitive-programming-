/*
Author: Hossam Eissa
Idea:make 4 D BIT first for index and second for character and thrid for string repeat every X and position of character in X 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const int TN = 1<<18;
const double PI=acos(-1);
int n,m,k;
int tree[N][10][10][4];
int ty(char x)
{
    if(x=='A')return 0;
    if(x=='C')return 1;
    if(x=='G')return 2;
    if(x=='T')return 3;
    return 4;
}
void add(int i,int pos,int rep,int ch,int val)
{
    i++;
    for(; i<N; i+=(i&-i))
    {
        tree[i][pos][rep][ch]+=val;
    }
}
int get(int i,int pos,int rep,int ch)
{
    i++;
    int val=0;
    for(; i>0; i-=(i&-i))
    {
        val+=tree[i][pos][rep][ch];
    }
    return val;
}
int main()
{
    in;
    string s;
    cin>>s;
    cin>>n;
    for(int i=0;i<s.size();i++)
    {
        int ch=ty(s[i]);
        for(int j=1;j<=10;j++){
            add(i,i%j,j,ch,1);
        }
    }
    while(n--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            char y;
            cin>>x>>y;
            x--;
            int ch=ty(s[x]);
            for(int i=1;i<=10;i++)
                add(x,x%i,i,ch,-1);
            s[x]=y;
            ch=ty(y);
            for(int i=1;i<=10;i++)
                add(x,x%i,i,ch,1);
        }
        else {
                int a,b;
        string x;
        cin>>a>>b>>x;
        a--;
        b--;
        int ans=0;
        for(int i=0;i<x.size();i++){
            int ch=ty(x[i]);
            ans+=get(b,(i+a)%x.size(),x.size(),ch)-get(a-1,(i+a)%x.size(),x.size(),ch);
        }
            cout<<ans<<endl;
        }
    }
}
