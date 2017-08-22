/*
Author: Hossam Eissa
Idea:
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int rows[N];
int main()
{
    int n;
    cin>>n;
    fill(rows,rows+n,1e9);
    int md=512;
    for(int i=1; i<=10; i++)
    {
        vector<int>v;
        for(int j=0; j<n; j++)
        {
            if(j%(2*md)<md)
            {
                v.push_back(j+1);
            }
        }
        cout<<v.size()<<endl;
        for(int i=0; i<v.size(); i++)
        {
            if(i)cout<<" ";
            cout<<v[i];
        }
        cout<<endl;
        v.clear();
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            if(j%(2*md)>=md)
            {
                rows[j]=min(rows[j],a);
            }
        }
        for(int j=0; j<n; j++)
        {
            if(j%(2*md)>=md)
            {
                v.push_back(j+1);
            }
        }
        if(v.size())
        {
            cout<<v.size()<<endl;
            for(int i=0; i<v.size(); i++)
            {
                if(i)cout<<" ";
                cout<<v[i];
            }
            cout<<endl;
            v.clear();

            for(int j=0; j<n; j++)
            {
                int a;
                cin>>a;
                if(j%(2*md)<md)
                {
                    rows[j]=min(rows[j],a);
                }
            }
        }
        md/=2;
        if(md<=0)break;
    }
    cout<<-1<<endl;
    for(int i=0; i<n; i++)
    {
        if(i)cout<<" ";
        cout<<rows[i];
    }
    cout<<endl;
}
