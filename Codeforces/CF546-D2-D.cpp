/*
Author: Hossam Eissa
Idea: generate all primes factors for all number and do prefix sum then answer every query in o(1)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
int n,m;
int primes[N];
int factors[N];
int main()
{
    for(int i=2; i<N; i++)
    {
        if(!primes[i])
        {
            // cout<<i<<endl;
            for(int j=i; j<N; j+=i)
            {
                int jj=j;
                int cnt=0;

                while(jj%i==0)cnt++,jj/=i;
                factors[j]+=cnt;
                primes[j]=1;
            }
        }
    }
    for(int i=1; i<N; i++)
    {
        factors[i]+=factors[i-1];
    }
    int n;
    scanf("%d",&n);
    int a,b;
    while(n--)
    {
        scanf("%d %d",&b,&a);
        printf("%d\n",factors[b]-factors[a]);
    }

}
