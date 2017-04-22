/*
Author: Hossam Eissa

	Idea:Big Number Multiplication


 */

#include <bits/stdc++.h>
#include<stdio.h>
#include <map>
#include<unordered_map>
using namespace std;
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
#define INF 2e9+5
#define MAX (int)1e6 + 5
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define edge pair<ll, pair<int, int>>
#define CYA  exit(0);
#define pi acos(-1);
/*int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 }; // 4 Direction*/
/*int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction*/
int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };//Knight Direction*/
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
ll n, m, k;
vector<int> mult(vector<int> a1,vector<int> a2){
    vector<vector<int> >tmp;
    tmp.resize(a2.size()+1,vector<int>(a1.size()+a2.size()+2));
    vector<int>ans;
    for(int i=0;i<a2.size();i++){
            int l=i;
        int c=0;
        for(int j=0;j<a1.size();j++){
                int sum=(a1[j]*a2[i])+c;
                tmp[i][l]=sum%10;
                c=sum/10;
                l++;
        }
        if(c)
            tmp[i][l]=c;
    }
/*
    for(int i=0;i<a2.size();i++){
        for(int j=0;j<a1.size()+i;j++){
        cout<<tmp[i][j]<<" ";
        }
            cout<<endl;
    }
    cout<<endl;
*/
     int c=0;
    for(int i=0;i<tmp[0].size();i++)
    {
     int sum=0;
        for(int j=0;j<a2.size();j++){
        sum+=tmp[j][i];

        }
        sum+=c;
        ans.push_back(sum%10);
        c=sum/10;
    }
    if(c)ans.push_back(c);

reverse(ans.begin(),ans.end());
return ans;
}
int main()
{
    FO;
    string a,b;
    while(cin>>a>>b){
 //           cout<<a<<b<<endl;
    vector<int>a1,a2;
    for(int i=0;i<a.size();i++){
        a1.push_back(a[i]-'0');
    }

    for(int i=0;i<b.size();i++){
        a2.push_back(b[i]-'0');
    }
    reverse(a1.begin(),a1.end());
    reverse(a2.begin(),a2.end());
  /*  for(int i=0;i<a1.size();i++){
    cout<<a1[i];
    }
    cout<<endl;
    for(int i=0;i<a2.size();i++){
    cout<<a2[i];
    }
    cout<<endl<<endl;
    */
    vector<int >v3=mult(a1,a2);
    bool x=0;
    for(int i=0;i<v3.size();i++){
    if(v3[i]!=0)x=1;
        if(x)
        cout<<v3[i];
    }
    //cout<<x<<endl;
    if(!x)cout<<"0";
    cout<<endl;
    }

}
