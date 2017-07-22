/*
Author: Hossam Eissa
Idea:do maximum bipartie matching between every same maximum value in rows and cols and greedy the rest
*/
#include<bits/stdc++.h>
using namespace std;
/*
0 based node indices
left nodes are numbered from 0
right nodes are numbered from 0 as well
*/
struct MaximumMatching {
	vector<int> m1, m2, seen;
	vector<vector<int> > g;
	int seen_id;
	MaximumMatching(int numNodesLeft, int numNodesRight) {
		g = vector<vector<int> >(numNodesLeft, vector<int>());
		m1 = vector<int>(numNodesLeft, -1);
		m2 = vector<int>(numNodesRight, -1);
		seen_id = 0;
		seen = vector<int>(numNodesRight, 0);
	}
	void addEdge(int leftNode, int rightNode) {
		assert(leftNode < int(m1.size()));
		assert(rightNode < int(m2.size()));
		g[leftNode].push_back(rightNode);
	}
	int getMaxMatching() {
		int ans = 0;
		for (int node = 0; node < int(m1.size()); node++) {
			seen_id++;
			if (dfs(node)) ans++;
		}
		return ans;
	}
	bool dfs(int node) {
		for (int i = 0; i < int(g[node].size()); i++) {
			int child = g[node][i];
			// if the child is not matched yet, match it with me
			if (m2[child] == -1) {
				m2[child] = node;
				m1[node] = child;
				return true;
			}

			// if the child was seen before (some other node tried to take it), leave it
			if (seen[child] == seen_id) continue;
			seen[child] = seen_id;

			// if the child is already matched with some other node, try to match that other node is some other way
			int enemy = m2[child];
			// take the child for me
			m1[enemy] = -1; m1[node] = child; m2[child] = node;
			// try to match the enemy
			if (dfs(enemy)) return true;
			// match the child with the enemy if not successful
			m1[enemy] = child; m1[node] = -1; m2[child] = enemy;
		}
		return  false;
	}

};
int mat[101][101];
int mat2[101][101];
int r[101],c[101];
int r2[101],c2[101];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>mat[i][j];
        r[i]=max(r[i],mat[i][j]);
        c[j]=max(c[j],mat[i][j]);
        }
    }
    map<int,vector<int>>mpr;
    map<int,vector<int>>mpc;
    for(int i=0;i<n;i++)mpr[r[i]].push_back(i);
    for(int i=0;i<m;i++)mpc[c[i]].push_back(i);

    for(auto i: mpr){
        vector<int>v=i.second;
        vector<int>v2=mpc[i.first];
        MaximumMatching ma(v.size(),v2.size());
        for(int j=0;j<v.size();j++){
            for(int k=0;k<v2.size();k++){
                    if(mat[v[j]][v2[k]]!=0)
                        ma.addEdge(j,k);
            }
        }
        ma.getMaxMatching();
        for(int j=0;j<v.size();j++){
            if(ma.m1[j]!=-1){
                mat2[v[j]][v2[ma.m1[j]]]=i.first;
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]!=0&&mat2[i][j]==0){
                mat2[i][j]=1;
            }
        }
    }

  /*  for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
        cout<<endl;*/
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c2[j]=max(mat2[i][j],c2[j]);
        }
    }
    for(int i=0;i<m;i++){
        if(c[i]!=c2[i]){
            for(int j=0;j<n;j++){
                if(mat[j][i]==c[i])
                {

                    mat2[j][i]=c[i];
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            r2[i]=max(mat2[i][j],r2[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(r[i]!=r2[i]){
       // cout<<"r = "<<i<<" "<<r[i]<<" "<<r2[i]<<endl;
            for(int j=0;j<m;j++){
                if(mat[i][j]==r[i])
                {
                    mat2[i][j]=r[i];
                    break;
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=(mat[i][j]-mat2[i][j]);
    //        cout<<mat2[i][j]<<" ";
        }
    //    cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
