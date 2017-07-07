/*
Author: Hossam Eissa
Idea: using KMP to string matching in 2d
*/
#include <bits/stdc++.h>
using namespace std;
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FO freopen("o.txt", "w", stdout);
int n1,n2;
vector<int>v;
int arr[101];
string s[101];
string s2[1001];
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
   // FO;
   //int n1,n2;
   int t;
   cin>>t;
   while(t--){
        int m1,m2;
        cin>>m1>>m2;
        memset(arr,0,sizeof arr);
        for(int i=0;i<m1;i++){
            cin>>s2[i];
        }
        vector<pair<int,int> >v;
                int x2=0;
        cin>>n1>>n2;
        for(int i=0;i<n1;i++){
            cin>>s[i];
        }
        kmparr();
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
        cout<<v.size()<<endl;
    }


}
