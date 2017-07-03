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
const int N = 1e5 + 5;
const double EPS = 1e-10;
const ll INF = 1e18;
const double PI = acos(-1);
ll n, m, k;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a<b ? -1 : 1;
}
ll dp[N];
ll arr[N],arr2[N];
inline bool checkValid(const pair<ll, ll> & line1, const pair<ll, ll> & line2,
                       const pair<ll, ll> & line3)
{
// d=(C2-C1)/(M1-M2)
    double i1 = (line3.second - line1.second)
                / (line1.first - line3.first * 1.0);
    double i2 = (line3.second - line2.second)
                / (line2.first - line3.first * 1.0);
    if (i1 > i2)
        return 0;
    return 1;
}/*
ll solve(int idx)
{
    error(idx);
    if(idx==n)
        return 0;

    ll ret=1e18;
    for(int i=idx+1;i<=n;i++){
        ret=min(ret,solve(i)+arr[i]*arr2[idx]+(sum[i-1]-sum[idx])*arr2[i]);
      //  error(i,ret);
    }
    return ret;
}*/
int main()
{
    in;
    cin>>n;
    arr[n+1]=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>arr2[i];
    }
    //fill(dp,dp+N,1e9);
   /* dp[0]=0;
    for(int i=1;i<n;i++){
        //error(i,dp[i]);
        for(int j=0;j<n;j++){
                if(i==j)continue;
            dp[i]=min(dp[i],dp[j]+arr[i]*arr2[j]);
        error(j,dp[j]);
        }
    }*/
    fill(dp,dp+n,1e18);
    dp[0]=0;
    set<pair<ll,ll>,greater<pair<ll,ll> > >st;
    for(int i=0; i<n; i++)
    {

        ll &r=dp[i];
    /*// cout<<"a7a"<<endl;
        for(int j=0; j<i; j++)
        {
            dp[i]=min(dp[i],dp[j]+v[i].first*v[j+1].second);
        }
        error(i,r);
        //*/
        while (st.size() >= 2)
        {
            pair<ll, ll> line1 = *st.begin();
            pair<ll, ll> line2 = *(++st.begin());
            ll v1 = line1.second + line1.first * arr[i];
            ll v2 = line2.second + line2.first * arr[i];
          //  error(v1,v2);
            if (v1 > v2)
            {
                st.erase(st.begin());
            }
            else
            {
                break;
            }
        }
        set<pair<ll,ll>,greater<pair<ll,ll> > >::iterator it1, it2, it3, cur;
        r = min(r,(*st.begin()).second + (*st.begin()).first * arr[i]);
     //   error(i,dp[i]);
    //     it1=st.begin();
    //        error(it1->first,it1->second,v[i].second);
        long long C1 = r;
        long long M1 = arr2[i];
        cur = it1 = it2 = it3 = st.insert(make_pair(M1, C1)).first;
        --it1;
        ++it3;

        // If a parallel line exist before, remove
        if (it2 != st.begin() && it1->first == it2->first)
        {
            st.erase(it1);
        }
        it1 = it2;
        --it1;

        // If a parallel line exist after, remove
        if (it3 != st.end() && it2->first == it3->first)
        {
            st.erase(it2);
            continue;
        }
        if (it2 != st.begin() && it3 != st.end())
        {
            if (!checkValid(*it1, *it2, *it3))
            {
                st.erase(it2);
                continue;
            }
        }

        while (1)
        {
            it1 = it2 = it3 = cur;
            ++it2;
            if (it2 == st.end())
                break;
            ++(++it3);
            if (it3 == st.end())
                break;
            if (!checkValid(*it1, *it2, *it3))
            {
                st.erase(it2);
            }
            else
            {
                break;
            }
        }

        while (1)
        {
            it1 = it2 = it3 = cur;
            if (it3 == st.begin())
                break;
            --it2;
            if (it2 == st.begin())
                break;
            --(--it1);
            if (!checkValid(*it1, *it2, *it3))
            {
                st.erase(it2);
            }
            else
            {
                break;
            }
        }



    }


    cout<<dp[n-1]<<endl;
}
