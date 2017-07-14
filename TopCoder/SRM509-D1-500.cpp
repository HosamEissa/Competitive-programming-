#include<bits/stdc++.h>
using namespace std;

#define ll long long
class PalindromizationDiv1
{
    ll sw[100][100];
    ll add[28];
    ll del[28];
    ll dp[100][100];
    vector<int>s;
public:
    ll solve(int i,int j){
       // cout<<i<<" "<<j<<endl;
        if(i>=j)return 0;

        ll &ans=dp[i][j];
        if(~ans)return ans;
        ans=1e17;
        if(s[i]==s[j])
            ans=min(ans,solve(i+1,j-1));

            ans=min(ans,solve(i+1,j-1)+sw[s[i]][s[j]]);
            ans=min(ans,solve(i+1,j-1)+sw[s[j]][s[i]]);
            ans=min(ans,solve(i+1,j-1)+sw[26][s[i]]+sw[26][s[j]]);
            ans=min(ans,solve(i+1,j-1)+sw[s[j]][26]+sw[s[i]][26]);
            ans=min(ans,solve(i+1,j)+sw[26][s[i]]);
            ans=min(ans,solve(i+1,j)+sw[s[i]][26]);
            ans=min(ans,solve(i,j-1)+sw[26][s[j]]);
            ans=min(ans,solve(i,j-1)+sw[s[j]][26]);
       for(int k=0;k<=26;k++){
            ans=min(ans,solve(i+1,j-1)+sw[s[i]][k]+sw[k][s[j]]);
            ans=min(ans,solve(i+1,j-1)+sw[s[j]][k]+sw[k][s[i]]);
            ans=min(ans,solve(i+1,j-1)+sw[s[i]][k]+sw[s[j]][k]);
            ans=min(ans,solve(i+1,j)+sw[26][k]+sw[s[i]][k]);
            ans=min(ans,solve(i+1,j)+sw[k][26]+sw[s[i]][k]);
            ans=min(ans,solve(i,j-1)+sw[26][k]+sw[s[j]][k]);
            ans=min(ans,solve(i,j-1)+sw[k][26]+sw[s[j]][k]);
        }
        return ans;
    }
    int getMinimumCost(string word, vector <string> operations)
    {
        for(int i=0;i<word.size();i++)
            s.push_back(word[i]-'a');
        memset(dp,-1,sizeof dp);
        for(int i=0; i<=27; i++)
        {
            add[i]=del[i]=1e17;
            for(int j=0; j<=27; j++)
                sw[i][j]=1e17;
        }
        for(int i=0; i<operations.size(); i++)
        {
            string x=operations[i];
            stringstream ss;
            ss<<x;
            ss>>x;
            char a,b;
            ll c;
            if(x[0]=='e')
            {
                ss>>a;
                ss>>c;
                sw[a-'a'][26]=c;
                //sw[26][a-'a']=c;
            }
            else if(x[0]=='a')
            {
                ss>>a;
                ss>>c;
                sw[26][a-'a']=c;
                //sw[a-'a'][26]=c;
            }
            else
            {
                ss>>a>>b;
                ss>>c;
                sw[a-'a'][b-'a']=min(c,sw[a-'a'][b-'a']);
            }
        }
              for(int i=0;i<26;i++)
                    sw[i][i]=0;
        for(int x=0;x<=30;x++)
        for(int i=0;i<=26;i++){
            for(int j=0;j<=26;j++){
                for(int k=0;k<=26;k++)
                sw[j][k]=min(sw[j][k],sw[j][i]+sw[i][k]);
            }
        }
          /*  for(int j=0;j<=26;j++){
                for(int k=0;k<=26;k++)
                cout<<j<<" "<<k<<" "<<sw[j][k]<<endl;
            }*/

        ll ans=solve(0,word.size()-1);
        if(ans>=1e17)ans=-1;
        return ans;
    }
};
