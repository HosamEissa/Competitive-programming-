/*
Author: Hossam Eissa
Idea:get each line and look at points up and down and calculate area up and down and sum them
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 3e2+5;
const double PIs=acos(-1);
ll n,m,k;
int X[N],Y[N];
int cross(int x1,int y1,int x2,int y2)
{
    return x1*y2-x2*y1;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>X[i]>>Y[i];
    int mxarea=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            vector<int>up;
            vector<int>down;
            int xL,yL;
            xL=X[j]-X[i];
            yL=Y[j]-Y[i];

            for(int k=0; k<n; k++)
            {
                if(i==k||j==k)continue;
                int tmpX,tmpY;
                tmpX=X[k]-X[i];
                tmpY=Y[k]-Y[i];
                int c=cross(xL,yL,tmpX,tmpY);
                if(c>=0)up.push_back(k);
                else down.push_back(k);
            }
            if(up.size()==0||down.size()==0)continue;

            int val1,val2;
            val1=val2=0;
            for(auto k : up)
            {
                int tmpX,tmpY;
                tmpX=X[k]-X[i];
                tmpY=Y[k]-Y[i];
                val1=max(val1,abs(cross(xL,yL,tmpX,tmpY)));
            }
            for(auto k :down)
            {
                int tmpX,tmpY;
                tmpX=X[k]-X[i];
                tmpY=Y[k]-Y[i];

                val2=max(val2,abs(cross(xL,yL,tmpX,tmpY)));
            }
           //cout<<i<<" "<<j<<" "<<X[i]<<" "<<Y[i]<<" "<<X[j]<<" "<<Y[j]<<" "<<val1<<" "<<val2<<endl;
            mxarea=max(mxarea,val1+val2);
        }
    }
    cout<<fixed<<setprecision(12)<<mxarea/2.0<<endl;
}
