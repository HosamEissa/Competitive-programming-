/*
Author: Hossam Eissa
Idea:brute force the answer
*/
#include <bits/stdc++.h>
using namespace std;

class TheCoffeeTimeDivTwo
{
public :
        int arr[10001];
    int find(int n, vector <int> tea){
        memset(arr,0,sizeof arr);
        sort(tea.begin(),tea.end());
        for(int i=0;i<tea.size();i++)
            arr[tea[i]]=1;
            vector<int>v;
        for(int i=1;i<=n;i++){
            if(!arr[i])
                v.push_back(i);
        }
        int x=tea.size()/7;
        if(tea.size()%7!=0)x++;
        x+=v.size()/7;
        if(v.size()%7!=0)x++;
        long long ans=x*47+4*n;
        for(int i=tea.size()-1;i>=0;i-=7){
            ans+=tea[i]*2;
        }
        for(int i=v.size()-1;i>=0;i-=7){
            ans+=v[i]*2;
        }
        return ans;
    }
};
