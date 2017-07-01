/*
Author: Hossam Eissa
Idea:
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
const int N = 1e6 + 5;
const double EPS = 1e-10;
const ll INF = 1e18;
const double PI = acos(-1);
ll n, m, k;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a<b ? -1 : 1;
}/*
int solve(int idx)
{
    if(idx==0)
        return m;
    for(int perv=0; perv<idx; perv++)
    {
        if(solve(idx)>=buy[i])
        {
            ret=max(ret,solve(perv)-buy[perv]+sell[perv]+(time[idx]-time[perv]-1)*profit[perv]);
        }
    }
}*/
struct machine
{
    ll d,p,r,g;
    inline bool operator<(machine a)
    {
        return d<a.d;
    }
} arr[N];
ll dp[N];
set<pair<ll,ll> >st;
bool valid(pair<ll,ll>p1,pair<ll,ll>p2,pair<ll,ll>p3)
{
    double i2=(p3.second-p2.second)/((p2.first-p3.first*1.0));
    double i1=(p3.second-p1.second)/((p1.first-p3.first*1.0));
    if(i1>i2)
        return 0;
    return 1;
}
int main()
{
    int tc=0;
    while(cin>>n>>m>>k)
    {
        if(!n&&!m&&!k)break;
        tc++;
        st.clear();
        //memset(dp,0,sizeof dp);
        for(int i=0; i<n; i++)
        {
            machine & x=arr[i];
            cin>>x.d>>x.p>>x.r>>x.g;
        }
        sort(arr,arr+n);
        arr[n].d=k+1;
        arr[n].g=0;
        arr[n].p=0;
        arr[n].r=0;
        for(int i=0; i<=n; i++)
        {
            ll &c=dp[i];
            c=m;
            machine &x=arr[i];
           while(st.size()>=2)
            {
                auto it=st.begin();
                auto it2=++st.begin();
                ll v1=it->second+(ll)it->first*x.d;
                ll v2=it2->second+(ll)it2->first*x.d;
                if(v1<v2)
                {
                    st.erase(st.begin());
                }
                else
                {
                    break;
                }
            }
            c=max(c,(st.begin()->second+(st.begin()->first)*x.d));
           set<pair<ll, ll> >::iterator it, it2, it3, curr;
           // error(c,x.p);
            if(c>=x.p)
            {
               // cout<<"a7a"<<endl;
                ll val=c-x.p+x.r-x.g*x.d-x.g;
                 curr=it=it2=it3=st.insert({x.g,val}).first;
                it--;
                if(it2!=st.begin()&&it2->first==it->first)
                {
                    st.erase(it);
                }
                it=it2;
                it--;
                it3++;
                if(it3!=st.end()&&it2->first==it3->first)
                {
                    st.erase(it2);
                    continue;
                }

                if(it2!=st.begin()&&it3!=st.end())
                {

                    if(!valid(*it,*it2,*it3))
                    {
                        st.erase(it2);
                        continue;
                    }
                }


                while(1)
                {
                    it=it2=it3=curr;
                    it2++;
                    if(it2==st.end())break;
                    it3++;
                    it3++;
                    if(it3==st.end())break;
                    if(!valid(*it,*it2,*it3)){
                            st.erase(it2);
                    }
                    else {
                        break;
                    }

                }


                while(1)
                {
                    it=it2=it3=curr;
                    if(it3==st.begin())break;
                    it2--;
                    if(it2==st.begin())break;
                    it--;
                    it--;
                    if(!valid(*it,*it2,*it3)){
                            st.erase(it2);
                    }
                    else {
                        break;
                    }

                }
            }

        }
        printf("Case %d: %lld\n",tc,dp[n]);
    }



}
