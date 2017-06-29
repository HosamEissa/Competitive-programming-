/*
Author: Hossam Eissa
Idea:
*/
#include <bits/stdc++.h>
using namespace std;
bool vis[10][10];
int n1;
bool ok(int x,int y){
    return x>=1&&x<=n1&&y>=1&&y<=n1;

}
vector<string>answer;
void dfs(int x,int y){
    if(vis[x][y])return;
    vis[x][y]=1;
    string b;
    b+=x+'a'-1;
    b+=y+'0';
    answer.push_back(b);
    if(ok(x+1,y)&&!vis[x+1][y]){
       // vis[x+1][y]=1;
        dfs(x+1,y);
    }
    else if(ok(x,y+1)&&!vis[x][y+1]){
       // vis[x][y+1]=1;
        dfs(x,y+1);

    }
    else if(ok(x,y-1)&&!vis[x][y-1]){
       // vis[x][y-1]=1;
        dfs(x,y-1);
    }
    else if(ok(x-1,y)&&!vis[x-1][y]){
       // vis[x-1][y]=1;
        dfs(x-1,y);
    }

}
class DukeOnChessBoard
{

public :
    string dukePath(int n, string initPosition){
		n1=n;
        int x=initPosition[0]-'a'+1;
        int y=initPosition[1]-'0';
        dfs( x,y);
        string s=answer[0];
        for(int i=1;i<answer.size();i++){
            s+='-';
            s+=answer[i];
        }
        if(s.size()<=40)return s;
        else {
            string s2=s.substr(0,20);
            s2+="...";
            s2+=s.substr(s.size()-20);
            return s2;
        }

    }

};
