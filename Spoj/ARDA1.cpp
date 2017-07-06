/*
Author: Hossam Eissa
Idea: make 1 kmp array for all the patteren togther and match them 
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
int n1,n2;
vector<int>v;
int arr[301];
string s[301];
string s2[2001];
void kmparr()
{
    int j=0;
    for(int i=1;i<n2;i++){
            int tmp=n2;
        for(int k=0;k<n1;k++){
            int tmpj=j;
            while(tmpj&&s[k][i]!=s[k][j])
                    tmpj=arr[tmpj-1];
            if(s[k][i]==s[k][tmpj])tmpj++;
            tmp=min(tmp,tmpj);
        }
    arr[i]=j=tmp;
    }
    //return ret;
}
int main()
{
    in;
   // FO;
   //int n1,n2;
    while(cin>>n1>>n2)
    {
        for(int i=0;i<n1;i++){
            cin>>s[i];
        }
        kmparr();
        int m1,m2;
        cin>>m1>>m2;
        for(int i=0;i<m1;i++){
            cin>>s2[i];
        }
        vector<pair<int,int> >v;
                int x2=0;
        for(int i=0;i+n1-1<m1;i++){
                x2=0;
            for(int j=0;j+n2-1<m2;j++){
                bool ans=1;
                while(x2<n2){
                    for(int x1=0;x1<n1;x1++){
                        if(s2[i+x1][j+x2]!=s[x1][x2]){
                            ans=0;
                            break;
                        }
                    }
                    if(ans)
                        x2++;
                    else {
                        x2=arr[x2-1];
                        break;
                    }
                }
                if(ans){
                    v.push_back({i,j});
                    x2=arr[x2-1];
                }

            }
        }
        for(int i=0;i<v.size();i++){
            cout<<"("<<v[i].first+1<<","<<v[i].second+1<<")"<<endl;
        }
        if(v.size()==0){
            cout<<"NO MATCH FOUND..."<<endl;
        }

    }


}
