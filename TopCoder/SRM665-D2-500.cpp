/*
Author: Hossam Eissa
Idea:try to go from every i to every j if path is valid return it
*/
#include<bits/stdc++.h>
using namespace std;


class LuckyCycle
{
public:
    int mat[101][101];
    int mat2[101][101];
    int vis[101];
    int n,dfscnt=1;
    int  ans=0;
    int dfs(int u,int f,int par=1,int cnt=0)
    {

        if(u==f)
        {
            if(cnt==1)
            {
                ans=1;
            }
            if(cnt==-1)
            {
                ans=-1;
            }

        }
        //cout<<u<<" "<<par<<" "<<cnt<<" "<<ans<<endl;
        vis[u]=dfscnt;
        for(int i=1; i<=n; i++)
        {
            if(i==u)continue;
            if(i==par)continue;
            if(mat[u][i]!=0)
            {
                if(vis[i]!=dfscnt)
                {
                    dfs(i,f,u,cnt+mat[u][i]);
                }
            }
        }
        // cout<<u<<" "<<par<<" "<<cnt<<" "<<ans<<endl;


    }
    vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight)
    {
        n=weight.size()+1;
        for(int i=0; i<edge1.size(); i++)
        {
            if(weight[i]==4)weight[i]=1;
            else weight[i]=-1;
            mat[edge1[i]][edge2[i]]=weight[i];
            mat[edge2[i]][edge1[i]]=weight[i];
        }
       for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)continue;
                if(mat[i][j])continue;
                dfscnt++;
                dfs(i,j);
                if(ans!=0)
                {
                    int val=4;
                    if(ans==1)val=7;
                    return vector<int>()= {i,j,val};
                }
            }
        }
        return vector<int>();
    }

};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
