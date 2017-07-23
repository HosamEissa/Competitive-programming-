/*
Author: Hossam Eissa
Idea:if n is even then you should fill even positions from back to front then odd in the same way
if n is odd then last digit is X and deal with n-1 same as even
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
#define ll long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    in;
    ll n,k,m;
    cin>>n>>k>>m;
    ll n1=n-1;
    ll tk=k-1;
    while(m--){
            ll idx;
            cin>>idx;
            if(n%2){
                    if(!k){
                        cout<<'.';
                        continue;
                    }
                    if(idx==n)cout<<"X";
                    else if(idx%2){
                        if(tk<=n/2){
                            cout<<'.';
                        }
                        else {
                            ll k1=tk-n1/2;
                            idx=idx/2+1;
                            idx=n1/2-idx;
                            if(k1<=idx){
                                cout<<".";
                            }
                            else cout<<"X";
                        }
                    }
                    else {
                        if(tk>=n/2){
                            cout<<'X';
                        }
                        else {
                                    idx=n1-idx;
                                    idx/=2;
                                    if(idx<tk){
                                        cout<<'X';
                                    }
                                    else cout<<'.';
                        }
                    }

            }
            else {
                    if(idx%2){
                        if(k<=n/2){
                            cout<<'.';
                        }
                        else {
                            ll k1=k-n/2;
                            idx=idx/2+1;
                            idx=n/2-idx;
                            if(k1<=idx){
                                cout<<".";
                            }
                            else cout<<"X";
                        }
                    }
                    else {
                        if(k>=n/2){
                            cout<<'X';
                        }
                        else {
                                    idx=n-idx;
                                    idx/=2;
                                    if(idx<k){
                                        cout<<'X';
                                    }
                                    else cout<<'.';
                        }
                    }

            }
    }

    return 0;
}
