/*
Author: Hossam Eissa
Idea:sort all the vectors using angle with X-axis and then try all shifts of the points and check answer if valid
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Y second
#define X first
const double pi=acos(-1);
int n,d;
vector<pair<int,int>>v;
bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.Y*p2.Y<0)
        return p1.Y>p2.Y;
    else {
        int cross=p1.X*p2.Y-p2.X*p1.Y;
        return cross>0;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);
        bool ans=0;
    for(int i=0;i<n;i++){
        bool f=1;
        for(int j=0;j<n-1;j++){
            pair<int,int>p1,p2;
            p1=v[j];
            p2=v[j+1];
            int cross=p1.X*p2.Y-p2.X*p1.Y;
            int dot=p1.X*p2.X+p1.Y*p2.Y;
            if(!(dot>0&&cross>=0))
                f&=0;
        }
        if(f){
            ans=1;
            break;
        }
        v.push_back(v[0]);
        v.erase(v.begin());
    }
    if(!ans)
        return puts("-1");
    for(int i=0;i<n;i++){
        cout<<v[i].X<<" "<<v[i].Y<<endl;
    }
}
