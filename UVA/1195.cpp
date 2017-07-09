/*
Author: Hossam Eissa
Idea:get all the primes less than 5e4 and try every combination of primes
*/
#include <bits/stdc++.h>
using namespace std;


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
#define FI freopen("interesting.in", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CYA  exit(0);
#define de(x) cerr << #x << " is " << x << endl;
#define mt make_tuple
#define eb emplace_back
typedef tuple<int,int,int> State; // operator< defined
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0,1, 0, -1 }; // 4 Direction*/
/*int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1}; //8 direction*/
/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int N = 5e4 + 5;
const double EPS = 1e-10;
const ll INF = 1e18;
const double PI = acos(-1);
ll n, a, b;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a<b ? -1 : 1;
}
int arr[N];
int main()
{
    vector<int>primes;
    for(int i=2; i<N; i++)
    {
        if(arr[i])continue;
        primes.push_back(i);
        for(int j=i; j<N; j+=i)
        {
            arr[j]=1;
        }
    }
    while(cin>>n>>a>>b,a|b|n)
    {
        int idx,idx2;
        ll area=0;
        for(int i=0; i<primes.size(); i++)
        {
            for(int j=i; j<primes.size(); j++)
            {
                ll x=primes[i];
                ll y=primes[j];
                if(x/(y*1.0)<a/(b*1.0))break;
                if(x*y>n)break;
                if(area<x*y){
                    area=x*y;
                    idx=i;
                    idx2=j;
                }
            }

        }
        cout<<primes[idx]<<" "<<primes[idx2]<<endl;

    }
    // FO;
}
