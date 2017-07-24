/*
Author: Hossam Eissa
Idea:inclusion execlusion all the triangles
*/
#include <bits/stdc++.h>
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
const double PI=acos(-1);
class BoxUnion{
public :
    int X[4],X2[4],Y[4],Y2[4];
    int area(vector <string> rectangles){
        n=rectangles.size();
        for(int i=0;i<n;i++){
            int x1,x2,y1,y2;
            stringstream ss;
            ss<<rectangles[i];
            ss>>x1;
            ss>>y1;
            ss>>x2;
            ss>>y2;
            if(x1>x2)swap(x1,x2);
            if(y1>y2)swap(y1,y2);
            X[i]=x1;
            Y[i]=y1;
            X2[i]=x2;
            Y2[i]=y2;
        }
    int total=0;
    for(int i=1;i<(1<<n);i++){
        int cnt=0;
        int mxx,mxy,mnx,mny;
        mxx=mxy=1e9+2;
        mnx=mny=-1e9-2;
       // cout<<i<<" ";
        for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    cnt++;
                    mnx=max(X[j],mnx);
                    mny=max(Y[j],mny);
                    mxx=min(X2[j],mxx);
                    mxy=min(Y2[j],mxy);
                }
        }
        if(mny>mxy||mnx>mxx)continue;
        //cout<<mnx<<" "<<mny<<" "<<mxx<<" "<<mxy<<endl;
        if(cnt%2)total+=abs(mxx-mnx)*abs(mxy-mny);
        else total-=abs(mxx-mnx)*abs(mxy-mny);
    }
    return total;
    }
};
int main()
{

}
