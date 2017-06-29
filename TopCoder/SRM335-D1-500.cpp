/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0,1, 0, -1 }; // 4 Direction*/
int mat[51][51];
int costs[51][51];
double costs2[51][51];
int enx,eny;
typedef tuple<int,int,int> XX;
typedef tuple<double,int,int> YY;
#define X(a) get<0>(a)
#define Y(a) get<1>(a)
#define val(a) get<2>(a)
int n1,m1;
bool ok(int x,int y)
{
    if(x>=0&&x<n1&&y>=0&&y<m1)return 1;
    return 0;
}
int bfs(int i,int j)
{
    queue<XX>q;
    q.emplace(i,j,0);
    for(int i=0; i<=50; i++)
    {
        for(int j=0; j<=50; j++)
        {
            costs[i][j]=1e9;
        }
    }
    //costs[i][j]=0;
    while(!q.empty())
    {
        XX p=q.front();
        q.pop();
         // error(X(p),Y(p),val(p));
        if(val(p)>=costs[X(p)][Y(p)])continue;
        costs[X(p)][Y(p)]=val(p);
        //error(X(p),Y(p),costs[X(p)][Y(p)],val(p));

        priority_queue<YY,vector<YY>,greater<YY>>pq;
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<m1; j++)
            {
                costs2[i][j]=1.00001;
            }
        }
        pq.emplace(1.0/mat[X(p)][Y(p)],X(p),Y(p));
        while(!pq.empty())
        {
            YY np=pq.top();
            pq.pop();
            if(costs2[Y(np)][val(np)]<=X(np))continue;
           // error(Y(np),val(np));
            costs2[Y(np)][val(np)]=X(np);
            //costs[Y(np)][val(np)]=min(val(p)+1,costs[Y(np)][val(np)]);
          // cout<<"-----------"<<Y(np)<<" "<<val(np)<<" "<<X(np)<<endl;
            for(int i=0;i<4;i++){
                int x=Y(np)+dx[i];
                int y=val(np)+dy[i];
                if(!ok(x,y))continue;
                double c=1.0/mat[x][y]+X(np);
             //   error(x,y,c,costs[x][y],val(p)+1);
                if(costs2[x][y]>c&&costs[x][y]>val(p)+1){
                    pq.emplace(c,x,y);
                }
            }
        }
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<m1; j++)
            {
                if(costs2[i][j]<1.0000001)
                    q.emplace(i,j,val(p)+1);
            }
        }

    }
    return costs[enx][eny];
}
class ExpensiveTravel
{

public :
    int minTime(vector <string> m, int startRow, int startCol, int endRow, int endCol)
    {
        for(int i=0; i<m.size(); i++)
        {
            for(int j=0; j<m[i].size(); j++)
            {
                mat[i][j]=m[i][j]-'0';
            }
        }
        n1=m.size();
        m1=m[0].size();
        startRow--;
        startCol--;
        endRow--;
        endCol--;
        enx=endRow;
        eny=endCol;
        int ans=bfs(startRow,startCol);
        if(ans==1e9)return -1;
        return ans;
    }

};
