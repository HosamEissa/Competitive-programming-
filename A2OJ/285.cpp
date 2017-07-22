/*
Author: Hossam Eissa
Idea:topo sort from every item i from 1 to k and you have 2 cases to choose your item i 
1st :if your pervious was the same item i
sec :if there are no other items but i
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD  1000000007
const int N=5e2+5;
int n,m;
int arr[N];
bool type[N];
vector<int>indeg;
vector<vector<int> >v2;
int get_best(vector<int>&same,vector<int>&Nsame,int cur)
{
    int val;
    if(cur)
    {
        if(same.size())
        {
            val=same.back();
            same.pop_back();
            return val;
        }
        val=Nsame.back();
        Nsame.pop_back();
    }
    else
    {

        if(Nsame.size())
        {
            val=Nsame.back();
            Nsame.pop_back();
            return val;
        }
        val=same.back();
        same.pop_back();
    }
    return val;

}
int topo(int cur)
{

    vector<int>same,Nsame,Tindeg=indeg;
    for(int i=0; i<n; i++)
    {
        if(Tindeg[i]==0)
            if(arr[i]==cur)
            {
                same.push_back(i);
            }
            else Nsame.push_back(i);
    }
    bool current=0;
    int ans=0;
    while(same.size()||Nsame.size())
    {
        int node=get_best(same,Nsame,current);
        if(!current&&arr[node]==cur)
            ans++;
        current=(arr[node]==cur);
        for(int j=0;j<v2[node].size();j++)
        {
            int i=v2[node][j];
            Tindeg[i]--;
            if(Tindeg[i]==0)
            {
                if(arr[i]==cur)
                {
                    same.push_back(i);
                }
                else Nsame.push_back(i);
                }
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    int tc=1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        v2.clear();
        v2.resize(n);
        indeg.clear();
        indeg.resize(n);
        for(int i=0; i<n; i++)scanf("%d",&arr[i]),type[arr[i]]=1;
        for(int j=0; j<m; j++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            b--;
            v2[a].push_back(b);
            indeg[b]++;
        }
        printf("Case %d:\n",tc++);
        for(int i=1; i<=n; i++)
        {
            if(type[i])
            {
                printf("%d\n",topo(i));
            type[i]=0;
            }
        }
    }
}
