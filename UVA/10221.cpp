/*
Author: Hossam Eissa
Idea:get the triangle two left angles then get the length of the distance and then calculate the chord
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const double pi=acos(-1);
int main()
{
    double a,b;
    string s;
        cout<<fixed<<setprecision(6);
    while(cin>>a>>b>>s){
        if(s=="deg");
        else b/=60;
        a+=6440;
        if(b>180)b=360-b;
        double deg=(180-b)/2;
        double x=a*cos(deg*pi/180.0)*2;
        double y=a*b*pi/180.0;
        cout<<y<<" "<<x<<endl;
    }
}
