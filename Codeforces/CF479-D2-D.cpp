/*
Author: Hossam Eissa
Idea: if have both x and y ans=0 else try to put 1 pos and check if you found the other else ans =2
*/
#include <bits/stdc++.h>
#include <map>
using namespace std;
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
#define INF 1 << 29
#define MOD 1000000007
#define MAX (int)1e5 + 5
#define FI freopen("i.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define edge pair<int, pair<int, int>>
/*int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1}; // 4 Direction*/
/*int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
/* int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1};//Knight Direction
*/
ll n,l,x,y;
vector<int>v,v2;
bool x1,y1;
int main()
{
    cin>>n>>l>>x>>y;
    vector<ll>v(n);
    int cnt=0,c1,c2;
    c1=c2=0;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    for(int i=0; i<n; i++)
    {
        if(!x1&&v[i]-x>=0&&binary_search(v.begin(),v.end(),v[i]-x))
        {
            x1=1;
            cnt++;
            c1=1;
        }
        if(!x1&&v[i]+x<=l&&binary_search(v.begin(),v.end(),v[i]+x))
        {
            x1=1;
            cnt++;
            c1=1;
        }
        if(!y1&&v[i]+y<=l&&binary_search(v.begin(),v.end(),v[i]+y))
        {
            y1=1;
            cnt++;
            c2=1;
        }

        if(!y1&&v[i]-y>=0&&binary_search(v.begin(),v.end(),v[i]-y))
        {
            y1=1;
            cnt++;
            c2=1;
        }

    }
    if(!cnt)
    {
        if(l-y==x)
        {
            cout<<1<<endl;
            cout<<x<<endl;
        }
        else
        {
            int c=abs(y-x);
            for(int i=0; i<n; i++)
            {
                if(v[i]-c>=0&&binary_search(v.begin(),v.end(),v[i]-c)&&v[i]+x<=l&&v[i]+x>=0)
                {
                    cout<<1<<endl;
                    cout<<v[i]+x;
                    return 0;
                }
                if(v[i]+c<=l&&binary_search(v.begin(),v.end(),v[i]+c)&&v[i]-x>=0&&v[i]-x<=l)
                {
            //cout<<"HERE "<<v[i]<<" "<<c<<" "<<endl;
                    cout<<1<<endl;
                    cout<<v[i]-x;
                    return 0;
                }

            }
            for(int i=0; i<n; i++)
            {
                int pos=v[i]-x;
                if(pos>0)
                {
                    if(pos-y>=0&&binary_search(v.begin(),v.end(),pos-y))
                    {
                        cout<<1<<endl;
                        cout<<pos<<endl;
                        return 0;
                    }
                    if(pos+y<=l&&binary_search(v.begin(),v.end(),pos+y))
                    {
                        cout<<1<<endl;
                        cout<<pos<<endl;
                        return 0;
                    }
                }
                pos=v[i]+x;
                if(pos<=l)
                {
                    if(pos-y>=0&&binary_search(v.begin(),v.end(),pos-y))
                    {
                        cout<<1<<endl;
                        cout<<pos<<endl;
                        return 0;
                    }
                    if(pos+y<=l&&binary_search(v.begin(),v.end(),pos+y))
                    {
                        cout<<1<<endl;
                        cout<<pos<<endl;
                        return 0;
                    }
                }
            }


            for(int i=0; i<n; i++)
            {
                int pos=v[i]-y;
                if(pos>0)
                {
                    if(pos-x>=0&&binary_search(v.begin(),v.end(),pos-x))
                    {
                        cout<<1<<endl;
                        cout<<pos<<endl;
                        return 0;
                    }
                    if(pos+x<=l&&binary_search(v.begin(),v.end(),pos+x))
                    {
                        cout<<1<<endl;
                        cout<<pos<<endl;
                        return 0;
                    }
                }
                pos=v[i]+y;
                if(pos<=l)
                {
                    if(pos-x>=0&&binary_search(v.begin(),v.end(),pos-x))
                    {
                        cout<<1<<endl;
                        cout<<pos<<endl;
                        return 0;
                    }
                    if(pos+x<=l&&binary_search(v.begin(),v.end(),pos+x))
                    {
                        cout<<1<<endl;
                        cout<<pos<<endl;
                        return 0;
                    }
                }
            }
            cout<<2<<endl;
            cout<<x<<" "<<y<<endl;
        }
    }
    else if(cnt==1)
    {
        cout<<1<<endl;
        if(c1)cout<<y<<endl;
        if(c2)cout<<x<<endl;
    }
    else cout<<0<<endl;
}
