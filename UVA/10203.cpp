/*
Author: Hossam Eissa
Idea:calculate all the distances of the roads then calculate the answer
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
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--){
        string s;
        getline(cin,s);
        string s2;
        double sum=0;
        while(getline(cin,s2)&&s2.size()){
            stringstream ss;
            ss<<s2;
           vector<int>v;
           ll a;
           while(ss>>a){
            v.push_back(a);
           }
           sum+=dist(v[0],v[1],v[2],v[3]);
        }
        sum*=2;
        sum/=1000.0;
        ll h=sum/20;
        ll mn=round((sum/20-h)*60);
        if(mn==60)
        {
            mn=0;
            h++;
        }
        cout<<h<<":";
        if(mn<10)cout<<"0";
        cout<<mn<<endl;
        if(t)cout<<endl;
    }
    // FO;
}
