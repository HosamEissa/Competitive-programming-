#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define ld long double
#define f first
#define s second
#define PI acos(-1)
#define CS ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
double EPS = 1e-8;
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
char mat[51][51];
int r[51][51];
int c[51][51];
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int cntr=0,cntc=0;
        for(int i=0;i<n;i++){
                bool x=false;
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
                if(mat[i][j]=='*'){
                    if(!x){
                        x=1;
                        cntr++;
                    }
                    r[i][j]=cntr;
                }
                else {
                    x=0;
                }
            }
        }
            for(int j=0;j<m;j++){
                bool x=false;
                for(int i=0;i<n;i++){
                if(mat[i][j]=='*'){
                    if(!x){
                        x=1;
                        cntc++;
                    }
                    c[i][j]=cntc;
                }
                else {
                    x=0;
                }
            }
        }
        //cout<<cntr<<" "<<cntc<<endl;
        MaximumMatching ma(cntr,cntc);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(mat[i][j]=='*'){
                   //     cout<<i<<" "<<j<<" "<<r[i][j]<<" "<<c[i][j]<<endl;
                        ma.addEdge(r[i][j]-1,c[i][j]-1);
                    }
            }
        }
        cout<<ma.getMaxMatching()<<endl;
    }

}
