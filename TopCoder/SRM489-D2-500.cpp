/*
Author: Hossam Eissa
Idea:brute force every possible answer
*/
#include <bits/stdc++.h>
using namespace std;

class BuyingFlowers
{
public :

    int buy(vector <int> roses, vector <int> lilies)
    {
        int n=roses.size();
        int ans=1e9;
        for(int i=0; i<(1<<n); i++)
        {
            int l=0;
            int r=0;
            for(int j=0; j<n; j++)
            {
                if(i&(1<<j))
                {
                    l+=lilies[j];
                    r+=roses[j];
                }
            }
            int total=l+r;
            for(int i=1; i*i<=total; i++)
            {
                if(total%i==0)
                {
                    int ro=total/i;
                    int co=i;
                    int l1=(co/2)*(ro/2);
                    int r1=(co-co/2)*(ro-ro/2);
                    int l2=(co/2)*(ro-ro/2);
                    int r2=(co-co/2)*(ro/2);
                    int t1=l1+r1;
                    int t2=l2+r2;
                    if((t1==r&&t2==l)||(l==t1&&t2==r)){
                        ans=min(ans,abs(ro-co));
                    }


                }
            }

        }



        return ans==1e9?-1:ans;


    }

};
