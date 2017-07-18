/*
Author: Hossam Eissa
Idea:get all divisors and do n^3 solution
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define MOD 1073741824
const int N = 1e6 + 5;
int prime[N];
int divs[N];
int main()
{
    fill(divs,divs+N,1);
    for(int i=2;i<N;i++){
        if(prime[i]==0){
                for(int j=i;j<N;j+=i){
                    int jj=j;
                    int cnt=0;
                    while(jj%i==0)jj/=i,cnt++;
                    divs[j]*=(cnt+1);
                    prime[j]=1;
                }
        }
    }
 /*   for(int i=1;i<=20;i++){
        cout<<i<<" "<<divs[i]<<endl;
    }*/
    int a,b,c;
    cin>>a>>b>>c;
    ll ans=0;
    for(int i=1;i<=a;i++)
    for(int j=1;j<=b;j++)
    for(int k=1;k<=c;k++)
        ans=(ans%MOD+divs[i*j*k]%MOD)%MOD;
    cout<<ans<<endl;
}
