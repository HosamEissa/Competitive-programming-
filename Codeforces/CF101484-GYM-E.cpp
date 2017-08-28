/*
 * CF101484-GYM-E.cpp
 *
 *  Created on: Aug 28, 2017
 *      Author: Hossam Eissa
 *      Idea:get centeriod point of any 3 points in the convex polgon and convert all the points into polar angles then for every point
 *          in the other polygon get the polar angle for it with the centeroid point and get the two points before and after it in log(n)
 *          then check if it is inside or not
 */

#include<bits/stdc++.h>
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
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int INF = 2000000000;
const double PI = acos(-1);
int n, d;
const int N = 1e5 + 5;
const double EPS = 1e-9;
int dcmp(double a, double b)
{
    return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}
double fixAngle(double A)
{
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}
double angleO(point a, point O, point b)
{
    point v1(a - O), v2(b - O);
    return acos(fixAngle( dp(v1, v2) / length(v1) / length(v2)));
}
vector<point> v, v2;
bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parllel || identical

    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;

    if (t1>1+EPS||t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;  //e.g ab is ray, cd is segment ... change to whatever
    return true;
}
bool solve(vector<point> v, vector<point> v2)
{
    double x = (v[0].X + v[1].X + v[2].X) / 3.0;
    double y = (v[0].Y + v[1].Y + v[2].Y) / 3.0;
    point p(x, y);
  //  cout<<x<<" "<<y<<endl;
    vector<pair<double, int>> angles;
    for (int i = 0; i < (int) v.size(); i++)
    {
        double c = angle(v[i]-p) * 180.0 / PI;
        if (c < 0)
            c += 360;
        if (c > 360)
            c -= 360;
        angles.push_back(pair<double, int>(c, i));
    }
    sort(angles.begin(), angles.end());
   // cout<<"angles"<<endl;
    for(int i=0; i<angles.size(); i++)
    {
  //           cout<<angles[i].first<<" "<<angles[i].second<<endl;
    }
	//cout<<"work"<<endl;
    for (int i = 0; i < (int) v2.size(); i++)
    {
    //    cout<<"point "<<v2[i].X<<" "<<v2[i].Y<<endl;
        point tmp = vec(p, v2[i]);
        double c = angle(tmp) * 180.0 / PI;
        if (c < 0)
            c += 360;
        if (c > 360)
            c -= 360;
        int idx = upper_bound(angles.begin(), angles.end(),
                              pair<double, int>(c, -1)) - angles.begin();
        point tt;
      //  cout<<i<<" "<<c<<" "<<idx<<endl;
        if (idx == v.size() || idx == 0)
        {
            int i1 = angles[0].second;
            int i2 = angles[angles.size() - 1].second;
           // cout<<v[i1].X<<" "<<v[i1].Y<<" "<<v[i2].X<<" "<<v[i2].Y<<endl;
            if (intersectSegments(v2[i], p, v[i1], v[i2], tt))
            {
                return false;
            }
         //   cout<<"intersect "<<tt.X<<" "<<tt.Y<<endl;

        }
        else
        {
            int i1 = angles[idx].second;
            int i2 = angles[idx - 1].second;

         //   cout<<v[i1].X<<" "<<v[i1].Y<<" "<<v[i2].X<<" "<<v[i2].Y<<endl;
            if (intersectSegments(v2[i], p, v[i1], v[i2], tt))
            {
                return false;
            }


        //    cout<<"intersect "<<tt.X<<" "<<tt.Y<<endl;
        }
    }
 //   cout<<endl<<endl;
    return true;
}
int main()
{
   // cout<<fixed<<setprecision(3)<<endl;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back(point(a, b));
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v2.push_back(point(a, b));
    }
    if (solve(v, v2)||solve(v2,v))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
