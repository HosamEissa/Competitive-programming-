/*
Author: Hossam Eissa

Idea:search for little strings in trie insted of map

*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include <map>
#include<unordered_map>
#include<complex>
using namespace std;
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pf(a) printf("%d",a)
#define pf2(a,b) printf("%d %d",a,b)
#define pf3(a,b,c) printf("%d %d %d",a,b,c)
#define sfl(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pfl(a) printf("%lld",a)
#define pfl2(a,b) printf("%lld %lld",a,b)
#define pfl3(a,b,c) printf("%lld %lld %lld",a,b,c)
#define nl printf("\n")
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define edge pair<ll, pair<int, int>>
#define CYA  exit(0);
#define pi acos(-1);
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
/*int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
/*int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int N = 3e5+ 50;
const int MOD = 20071027;
const double EPS=1e-8;
const double INF=2e15+5;
int n, m,k,d;
string s;
struct node {
	node *arr[28];
	bool val=0;
	node() {
		for (int i = 0; i < 28; i++) {
			arr[i] = NULL;
		}
	}

};
void del(node* no) {
	for (auto &i : no->arr) {
		if (i != NULL) {
			del(i);
		}
	}
	delete no;
}
node* root;
void put(string s) {
	node *curr = root;
	for (int i = 0; i < s.size(); i++) {
		node* nxt = curr->arr[s[i] - 'a'];
		if (nxt == NULL) {
			curr->arr[s[i]-'a']=nxt = new node();
		}
		curr = nxt;
	}
	curr->val=1;
}
ll dp[N];
ll solve(int idx){
    //cout<<idx<<endl;
    if(idx==s.size())return 1;
    ll &ans=dp[idx];
    if(ans!=-1)return ans;
    ans=0;
    string tmp;
    node *p=root;
    for(int i=idx;i<s.size();i++){
        p=p->arr[s[i]-'a'];
        if(p==NULL)
            return ans=(ans%MOD);
       if(p->val)
        ans+=solve(i+1);
        ans=(ans%MOD);
     }
    return ans=(ans%MOD);;

}

int main()
{
    int t=1;

    while(cin>>s){
            root=new node();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            string s2;
            cin>>s2;
            put(s2);

        }
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",t++,(int)solve(0));
        del(root);
        }

}
