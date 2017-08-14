/*
Author: Hossam Eissa
Idea:use dp to count in every position in the tree how many available trees if i put current character in currenet position
*/
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
class EncodingTrees
{
public:
    int dp[22];
    int solve(int mx){
       // cout<<mx<<endl;
        if(mx==0)return 1;
        int ans=0;
        if(dp[mx]!=-1)return dp[mx];
        for(int i=0;i<mx;i++){
            ans+=solve(i)*solve(mx-i-1);
        }
        //cout<<mx<<" "<<ans<<endl;
        return dp[mx]=ans;
    }
    string ans;
    void print(int mx,int index,int perv){
        if(index<0)return ;

        if(mx==0){
            return ;
        }
        //cout<<"start "<<mx<<" "<<index<<" "<<perv<<endl;
        if(index==0){
       //         cout<<"a7aaaaaaa"<<endl;
         /*      for(int i=mx-1;i>=0;i--)
                    ans+='a'+i+perv;
           */         return ;
        }
      //  int sum=0;
        for(int i=0;i<mx;i++){


            int val=solve(i)*solve(mx-i-1);
          //  sum+=val;
           // cout<<"pross " <<mx<<" "<<index<<" "<<perv<<" i = "<<i<<" val = "<<val<<endl;
            if(index<=val){
                int x1=solve(i);
                int x2=solve(mx-i-1);
                int cnt=0;
                //cout<<"x1 = "<<x1<<" x2 =  "<<x2<<" cnt = "<<cnt<<endl;
                ans+='a'+i+perv;
                //cout<<"adding "<<char('a'+i+perv)<<endl;
                print(i,(index-1)/(x2)+1,perv);
                print(mx-i-1,(index-1)%x2+1,perv+i+1);
              //  cout<<"ending " <<char('a'+i+perv)<<endl;
                return ;
            }
            else index-=val;
            }
     //  cout<<"end " <<mx<<" "<<index<<" "<<perv<<endl;

    }
    string getCode(int N, int index){
      //  return solve(N);
      memset(dp,-1,sizeof dp);
      if(index>solve(N))return "";
      print(N,index,0);
        return ans;
    }


};  
