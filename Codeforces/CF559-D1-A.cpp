/*
Author: Hossam Eissa
Idea:a+b+c=nubmer of all triangles then erase the uneeded triangles
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi=acos(-1);
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int x=(a+b+c)*(a+b+c)-a*a-c*c-e*e;
    cout<<x<<endl;

}
