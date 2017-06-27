/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
int arr[]={2,3,5,7};
int cnt[4];
class ProductOfDigits{
public:
    int smallestNumber(int n){
   // cin>>n;
    if(n==1){
        cout<<1<<endl;
        return 1;
    }
    for(int i=0;i<4;i++){
     //       error(i,n);
       //     error(n%arr[i]);
        while(n>1&&(n%arr[i])==0){
            n/=arr[i];
            cnt[i]++;
        }
    }
    if(n!=1)return -1;
    else {
     //       error(cnt[0],cnt[1],cnt[2],cnt[3]);
          int x=cnt[0]/3;
        cnt[0]-=3*x;
        string s;
        for(int i=0;i<x;i++){
            s+='8';
        }
        if(cnt[0]%3==2)s+='4';
        x=cnt[1]/2;
        for(int i=0;i<x;i++){
            s+='9';
        }
      
        if(cnt[1]%2&&cnt[0]%2)s+='6';
        else if(cnt[0]%2)s+='2';
        else if(cnt[1]%2)s+='3';
        for(int i=0;i<cnt[2];i++){
            s+='5';
        }
        for(int i=0;i<cnt[3];i++){
            s+='7';
        }
        return s.size();
    }
    }

    };
