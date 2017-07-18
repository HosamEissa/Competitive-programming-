/*
Author: Hossam Eissa
Idea:try building sum s form all the indecies from 1 to i and then calculate answer
*/
#include <bits/stdc++.h>
using namespace std;

/*
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c)
{
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        v.emplace_back(x);
    return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args)
{
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
    err(++it, args...);
}
//*/
#define ll  long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n,m;
vector<int>u,l;
int total=0;
int dp[500*501+5];

int solve2(vector<int>v)
{
    int total=0;
    n=v.size();
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=total; j>=0; j--)
        {

         if(j+v[i-1]<=500*500)dp[j+v[i-1]]|=dp[j];
        }
        total+=v[i-1];
    }
    int ans=1e9;
    for(int j=0; j<=total; j++)
    {
          if(dp[j])
            {
                ans=min(ans,abs(j-(total-j)));
            }

    }
    return ans;
}
int main()
{
    in;
    int t;
    cin>>t;
    while(t--)
    {
        u.clear();
        l.clear();
        cin>>n;
        int vx;
        cin>>vx;
        u.push_back(vx);
        for(int i=0; i<n; i++)
        {
            char bad;
            int a;
            cin>>bad>>a;
            if(i%2)
                u.push_back(a);
            else l.push_back(a);
        }
        if(n<3)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<solve2(l)+solve2(u)<<endl;

    }
}
