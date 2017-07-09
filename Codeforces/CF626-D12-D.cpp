/*
Author: Hossam Eissa
Idea:loop N^2 and generate all the differences and loop over all the values and get the answer
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
int arr[N],arr2[N];
int main()
{
    cin>>n;
    vector<int>v(n),v2;
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {
            arr[v[j]-v[i]]++;
        }
    }
    ll total=0;
    for(int i=0;i<10004;i++){
        total+=arr[i];
    }
    for(int i=10003;i>0;i--){
        arr2[i]=arr2[i+1]+arr[i];
    }
    double answer=0;
    for(int i=0;i<5001;i++){
        for(int j=0;j<5001;j++)
        {
            answer+=arr[i]/(total*1.0)*arr[j]/(total*1.0)*arr2[i+j+1]/(total*1.0);
        }
    }
    cout<<fixed<<setprecision(7)<<answer<<endl;


    // FO;
}
