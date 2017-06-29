/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;int n1;
int adj[11][11];
void floyd(){
int n=n1;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++)
        adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);

  //for(int i=0;i<n;i++)if(adj[i][i]<0)cout<<"there is a negative cycle"<<endl;
}

class Egalitarianism3Easy
{

public :
   int maxCities(int n, vector <int> a, vector <int> b, vector <int> len){
        if(n==1)return 1;
        n1=n;
     for(int i=0;i<n;i++) for(int j=0;j<n;j++) adj[i][j]=1e8;
    for(int i=0;i<a.size();i++){
        a[i]--;
        b[i]--;
        adj[a[i]][b[i]]=len[i];
        adj[b[i]][a[i]]=len[i];
    }
    floyd();
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        vector<int>v;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                v.push_back(j);
            }
        }
        set<int>st;
        for(int j=0;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                st.insert(adj[v[j]][v[k]]);
            }
        }

        if(st.size()==1){
            ans=max((int)v.size(),ans);
        }
    }
    return ans;
   }

};
