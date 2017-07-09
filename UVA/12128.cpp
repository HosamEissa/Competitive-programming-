/*
Author: Hossam Eissa
Idea:bfs from all the nodes to calculate the distances and BS the distance value and use bfs as check function
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
const int N = 1e3 + 5;
const double EPS = 1e-10;
const ll INF = 1e18;
const double PI = acos(-1);
ll n, m, k;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a<b ? -1 : 1;
}
int arr[N][N];
int cost[N][N];
bool ok(int x,int y){
return x>=0&&x<n&&y>=0&&y<m;
}
int stx,sty,enx,eny;
int bfs(int k){
    queue<pair<int,int>>q;
    q.emplace(stx,sty);
    memset(cost,-1,sizeof cost);
    cost[stx][sty]=0;
    if(arr[stx][sty]<k)return -1;
    while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int c=0;c<4;c++){
                int x,y;
                x=p.first+dx[c];
                y=p.second+dy[c];
                if(ok(x,y)&&arr[x][y]>=k&&cost[x][y]==-1){
                    cost[x][y]=cost[p.first][p.second]+1;
                    q.emplace(x,y);
                }
            }
    }
    return cost[enx][eny];
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>k>>n>>m;
        cin>>stx>>sty>>enx>>eny;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=1e5;
            }
        }
            queue<pair<int,int>>q;
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            arr[x][y]=0;
            q.emplace(x,y);
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int c=0;c<4;c++){
                int x,y;
                x=p.first+dx[c];
                y=p.second+dy[c];
                if(ok(x,y)&&arr[x][y]>arr[p.first][p.second]+1){
                    arr[x][y]=arr[p.first][p.second]+1;
                    q.emplace(x,y);
                }
            }
        }
        if(stx==enx&&sty==eny){
            cout<<arr[stx][sty]<<" "<<0<<endl;
            continue;
        }
        int l=0,r=1000*1000,ans=0;
        while(l<r){

            int mid=(l+r)>>1;
            int c=bfs(mid);
          //  error(l,r,mid,c);
            if(c!=-1){
                l=mid+1;
                ans=mid;
            }
            else {
                    r=mid-1;
            }
        }
        while(bfs(ans)!=-1){
          //  error(ans,bfs(ans));
            ans++;
        }
            //error(ans,bfs(ans));
           // ans++;

        ans--;
        cout<<ans<<" "<<bfs(ans)<<endl;
    }
   // FO;
}
