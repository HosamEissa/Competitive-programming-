/*
Author: Hossam Eissa
Idea:try to put the portals in every to cells and check the distance
*/
#include<bits/stdc++.h>
using namespace std;

int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};
class PublicTransit
{
    int n,m;
public:
#define node pair<pair<int,int>,int>
#define X first.first
#define Y first.second
#define CC second

    int vis[11][11];
    pair<int,int>p1,p2;
    int dfscnt=0,mx;
    bool ok (int i,int j)
    {
        return i>0&&i<=n&&j>0&&j<=m;
    }
    void bfs(int i,int j)
    {
        queue<node>q;
        q.push({{i,j},0});
        vis[i][j]=dfscnt;
        if(i==p1.first&&j==p1.second)
        {
            if(vis[p2.first][p2.second]!=dfscnt)
            {
                vis[p2.first][p2.second]=dfscnt;
                q.push({{p2.first,p2.second},0});
            }
        }

        else if(i==p2.first&&j==p2.second)
        {
            if(vis[p1.first][p1.second]!=dfscnt)
            {
                vis[p1.first][p1.second]=dfscnt;
                q.push({{p1.first,p1.second},0});
            }
        }
        while(!q.empty())
        {
            node a=q.front();
            q.pop();
            mx=max(mx,a.CC);
            for(int i=0; i<=3; i++)
            {
                int x=a.X+dx[i];
                int y=a.Y+dy[i];
                if(ok(x,y)&&vis[x][y]!=dfscnt)
                {
                    if(x==p1.first&&y==p1.second)
                    {
                        if(vis[p2.first][p2.second]!=dfscnt)
                        {
                            vis[p2.first][p2.second]=dfscnt;
                            q.push({{p2.first,p2.second},a.CC+1});
                        }
                    }

                   else if(x==p2.first&&y==p2.second)
                    {
                        if(vis[p1.first][p1.second]!=dfscnt)
                        {
                            vis[p1.first][p1.second]=dfscnt;
                            q.push({{p1.first,p1.second},a.CC+1});
                        }
                    }
                    vis[x][y]=dfscnt;
                    q.push({{x,y},a.CC+1});
                }
            }
        }

    }
    int minimumLongestDistance(int R, int C)
    {
        n=R,m=C;
        int mn=1e9;
        for(int x1=1; x1<=R; x1++)
        {
            for(int y1=1; y1<=C; y1++)
            {
                for(int x2=1; x2<=R; x2++)
                {
                    for(int y2=1; y2<=C; y2++)
                    {
                        p1= {x1,y1};
                        p2= {x2,y2};
                        int dist=0;
                        for(int i=1; i<=R; i++)
                        {
                            for(int j=1; j<=C; j++)
                            {
                                dfscnt++;
                                mx=0;
                                bfs(i,j);
                                dist=max(dist,mx);
                            }
                        }
                        if(dist<mn){
                        //    cout<<mn<<" "<<dist<<" "<<p1.first<< " "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
                            mn=dist;
                        }
                    }
                }
            }
        }
        return mn;
    }
};
