/*
 *
 *
 *
 *      Author: Hossam Eissa
 *      idea : build SCC from the nodes with out using bridges 
 */


#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

bool adj[N][N];
int n, DFSN[N], LOW[N], id,grpCNT[N],cnt;
void init()
{
    memset(adj,0,sizeof adj);
    id = 0;
    memset(DFSN, 0, sizeof DFSN);
    memset(grpCNT, 0, sizeof grpCNT);
    memset(LOW, 0, sizeof LOW);
    cnt=0;
}

stack<int>st;
void Tarjan(int u, int p = -1)
{
    DFSN[u] = LOW[u] = ++id;
    st.push(u);
    for(int v=1; v<=n; v++)
    {
        if(adj[u][v])
        {
            adj[v][u]=0;
            if(!DFSN[v])
            {

                Tarjan(v, u);
                LOW[u] = min(LOW[u], LOW[v]);
            }
            else if(p != v)
                LOW[u] = min(LOW[u], DFSN[v]);
        }
    }
    if(DFSN[u]==LOW[u])
    {
        cnt++;
        int v=st.top();
        do
        {
            v=st.top();
            st.pop();
            grpCNT[v]=cnt;
        }
        while(v!=u);
    }
}
int x=-1;

int main()
{
    int t=1;
    int m;
    while(scanf("%d%d", &n,&m)&&(n|m))
    {
        init();
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a][b]=adj[b][a]=1;
        }
        for(int i=1; i<=n; i++)
        {
            if(!DFSN[i])
            {

                Tarjan(i);
            }
        }

        printf("%d\n\n",t++);
        for(int i=1; i<=n; i++)
        {
            for(int v=1; v<=n; v++)
            {
                if(adj[i][v])
                {
                    printf("%d %d\n",i,v);
                    if(grpCNT[i]!=grpCNT[v])
                        printf("%d %d\n",v,i);
                }
            }
        }
        puts("#");
    }
    return 0;
}
