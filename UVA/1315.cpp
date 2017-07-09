/*
Author: Hossam Eissa
Idea:pre calculate all the values and answer querys in o(1)
*/
#include <bits/stdc++.h>
using namespace std;
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
const int N = 35000 + 5;
const double EPS = 1e-10;
const ll INF = 1e18;
const double PI = acos(-1);
ll n, m, k;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a<b ? -1 : 1;
}
int arr[N];
int main()
{
    int cnt=2;
    int val=1;
    for(int i=3;i<N;i++){
        arr[i]=arr[i-1]+val;
        cnt--;
        if(cnt==0){
            cnt=2;
            val++;
        }
    }
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        int n;
        cin>>n;
        cout<<arr[n]<<endl;
    }
}
