/*
 * UVA_10199.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: Hossam Eissa
 *      Idea: articulation points 
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps=1e-9;

const int N = 100 + 5;

vector<int> adj[N];
int n, DFSN[N], LOW[N], id, root, rootCalls;
set<int> Arti;
vector<pair<int, int>> Bridges;

void init(){
  for(int i=0; i<N; i++)
    adj[i].clear();
  id = 0;
  memset(DFSN, 0, sizeof DFSN);
  memset(LOW, 0, sizeof LOW);
  Arti.clear();
  Bridges.clear();
}

void Tarjan(int u, int p = -1){
  DFSN[u] = LOW[u] = ++id;
  for(int v: adj[u]){
    if(!DFSN[v]){
      Tarjan(v, u);
      rootCalls += u == root;
      LOW[u] = min(LOW[u], LOW[v]);
      if(DFSN[u] < LOW[v]) Bridges.push_back({min(u, v), max(u, v)});
      if(DFSN[u] <= LOW[v] && root != u) Arti.insert(u);
    }else if(p != v)
      LOW[u] = min(LOW[u], DFSN[v]);
  }
}
string arr[N];
map<string,int>mp;
int main()
{
	int m;
	int t=1;
  while(~scanf("%d", &n)&&(n)){
    init();
    if(t>1)puts("");
    mp.clear();
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	mp[arr[i]]=i;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
    	string s1,s2;
    	cin>>s1>>s2;
    	int a=mp[s1];
    	int b=mp[s2];
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    for(int i=0; i<n; i++){
      if(!DFSN[i]){
        root = i;
        rootCalls = 0;
        Tarjan(i);
        if(rootCalls > 1)
          Arti.insert(root);
      }
    }
    printf("City map #%d: %d camera(s) found\n",t++,(int)Arti.size());
    set<string>st;
    for(auto i : Arti)
    	st.insert(arr[i]);
    for(auto i : st){
    	cout<<i<<endl;
    }
  }
  return 0;
}
