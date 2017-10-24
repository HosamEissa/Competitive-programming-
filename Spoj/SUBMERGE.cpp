/*
 * SPOJ_SUBMERGE.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: Hossam Eissa
 *      Idea: get the articulation points
 */



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps=1e-9;

const int N = 1e4 + 5;

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

int main()
{
	int m;
  while(~scanf("%d %d", &n,&m)&&(n|m)){
    init();
    for(int i=0;i<m;i++){
    	int a,b;
    	scanf("%d%d",&a,&b);
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
    printf("%d",(int)Arti.size());
    puts("");
  }
  return 0;
}
