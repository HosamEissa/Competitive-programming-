/*
Author: Hossam Eissa
Idea:hash all the strings the apply mo's algorithm to answer the query 
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod=1e9+7;
const int mod2=50001137;
const int mod3=50001137;
const int N=1e5+5;
long long base,pw1,inv;
int k,n,block;
void shiftleft(long long & a,long long number,long long number2,int mod)
{
    a=(a-(number*pw1)%mod+mod)%mod;
    a=(a*base)%mod;
    a=(a+number2)%mod;
}
long long arr[N],arr2[N],S[N],S2[N];
int A[N],B[N],Q[N],ans[N];
 
bool cmp(int i,int j){
    int x1=A[i]/block;
    int x2=A[j]/block;
 
    if(x1!=x2)
        return x1<x2;
    else
      return B[i]<B[j];
}
int answer=0;
map<long long,int>mp;
map<long long,int>mp2;
void add(int idx){
    mp[arr[idx]]++;
    mp2[arr2[idx]]++;
 
}
void rem(int idx){
    mp[arr[idx]]--;
    mp2[arr2[idx]]--;
}
char s[20];
int main()
{
    scanf("%d",&n);
    base=128;
    for(int i=0;i<n;i++){
 
        scanf("%s",s);
        long long a=0,b=0;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            shiftleft(a,0,s[i],mod);
            shiftleft(b,0,s[i],mod2);
        }
        arr[i]=a;
        arr2[i]=b;
        //cout<<a<<endl;
    }
    block=200;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d%d%s",&A[i],&B[i],s);
        A[i]--;
        Q[i]=i;
        long long a=0,b=0;
        int len=strlen(s);
        for(int j=0;j<len;j++){
            shiftleft(a,0,s[j],mod);
            shiftleft(b,0,s[j],mod2);
        }
        S[i]=a;
        S2[i]=b;
    }
    sort(Q,Q+k,cmp);
    int l=0,r=0;
    for(int i=0;i<k;i++){
        int idx=Q[i];
     //   cout<<i<<" "<<idx<<endl;
            while(l<A[idx]){
                rem(l);
                l++;
            }
            while(l>A[idx]){
                l--;
                add(l);
            }
            while(r<=B[idx]){
                add(r);
                r++;
            }
            while(r>B[idx]){
                r--;
                rem(r);
            }
            //cout<<idx<<" "<<l<<" "<<r<<endl;
            ans[idx]=min(mp[S[idx]],mp2[S2[idx]]);
    }
    for(int i=0;i<k;i++){
        printf("%d\n",ans[i]);
    }
 
}
 
Language: C++14
