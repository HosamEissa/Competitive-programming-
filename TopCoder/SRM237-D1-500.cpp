/*
Author: Hossam Eissa
Idea:Recursion
*/
#include<bits/stdc++.h>
using namespace std;
class CakeDivision{
public:

double ratio(int length, int width, int pieces){
	return solve(length,width,pieces);
}
double solve(double l,double w,int p){
    if(p==1)return max(l,w)/min(w,l);
    double ans=1e18;
    for(int i=1;i<p;i++){

        ans=min(ans,max(solve(i*l/p,w,i),solve((p-i)*l/p,w,p-i)));
       // ans=min(ans,solve(i*l/p,w,i));
       // ans=min(ans,solve(l,i*w/p,i));
        ans=min(ans,max(solve(l,i*w/p,i),solve(l,(p-i)*w/p,p-i)));
    }
    return ans;

}
};
