/*
Author: Hossam Eissa
Idea:do a line sweep on X and if you found opening save it and if you found closing match it with the first opening lower or equal to it
*/
#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define FI freopen("input.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define in ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 2000000000;
const int N = 1e5+5;
const int TN = 1<<22;
const double PI=acos(-1);
ll n,m,k;
int match[N];
int mn[TN],mx[TN],lazy[TN];
void probagate(int l,int r,int p){
    mx[p]+=lazy[p];
    mn[p]+=lazy[p];
    if(l!=r){
        lazy[p<<1]+=lazy[p];
        lazy[(p<<1)|1]+=lazy[p];
    }
    lazy[p]=0;
}
void update(int val,int ql,int qr,int l=0,int r=(1<<19),int p=1){
    probagate(l,r,p);
    if(ql>r||qr<l)return;
    if(ql<=l&&r<=qr){
        lazy[p]+=val;
        probagate(l,r,p);
        return ;
    }
    int m=(l+r)>>1;
    update(val,ql,qr,l,m,(p<<1));
    update(val,ql,qr,m+1,r,(p<<1)|1);
    mn[p]=min(mn[(p<<1)],mn[(p<<1)|1]);
    mx[p]=max(mx[(p<<1)],mx[(p<<1)|1]);
}
int getmin(int ql,int qr,int l=0,int r=(1<<19),int p=1){
       probagate(l,r,p);
    if(ql>r||qr<l)return 1e9;
    if(ql<=l&&r<=qr){
        return mn[p];
    }
    int m=(l+r)>>1;
    return min(getmin(ql,qr,l,m,(p<<1)),getmin(ql,qr,m+1,r,(p<<1)|1));
}

int getmax(int ql,int qr,int l=0,int r=(1<<19),int p=1){
    probagate(l,r,p);
    if(ql>r||qr<l)return -1e9;
    if(ql<=l&&r<=qr){
        return mx[p];
    }
    int m=(l+r)>>1;
    return max(getmax(ql,qr,l,m,(p<<1)),getmax(ql,qr,m+1,r,(p<<1)|1));
}
struct rect{
    int x1,x2,y1,y2;
    rect(int X1,int Y1,int X2,int Y2){
        x1=X1;
        x2=X2;
        y1=Y1;
        y2=Y2;
    }
};
bool comp(rect a,rect b){
    return a.y1<b.y1;
}
vector<pair<pair<int,int>,int> >input(2*n),v;
vector<rect>boxs;
void compress(){
    map<int,int>xs,ys;
    for(auto i : input){
        xs[i.first.first]=0;
        ys[i.first.second]=0;
    }
    int cnt=1;
    for(auto &i : xs){
        i.second=cnt++;
    }
    cnt=1;
    for(auto &i : ys){
        i.second=cnt++;
    }
    for(auto &i : input){
        i.first.first=xs[i.first.first];
        i.first.second=ys[i.first.second];
    }
}
bool isborder(int x1,int x2){

        if(abs(getmin(x1,x1)-getmin(x1-1,x1-1))>1)return 1;
        if(abs(getmax(x2,x2)-getmax(x2+1,x2+1))>1)return 1;
    return 0;
}
bool sweep(){
    memset(mn,0,sizeof mn);
    memset(mx,0,sizeof mx);
    memset(lazy,0,sizeof lazy);
    sort(boxs.begin(),boxs.end(),comp);
        //<Y2,<X1,X2>>
        set<pair<int,pair<int,int>>>st;
    for(int i=0;i<boxs.size();i++){
            while(st.size()&&(*st.begin()).first<=boxs[i].y1){
                pair<int,int>p=(*st.begin()).second;
                if(getmin(p.first,p.second)!=getmax(p.first,p.second)||isborder(p.first,p.second))
                return 0;
                update(-1,p.first,p.second);
                st.erase(st.begin());
            }
            update(1,boxs[i].x1,boxs[i].x2);
            if(getmin(boxs[i].x1,boxs[i].x2)!=getmax(boxs[i].x1,boxs[i].x2))
                return 0;
            if(isborder(boxs[i].x1,boxs[i].x2))
                return 0;
            st.insert({boxs[i].y2+1,{boxs[i].x1,boxs[i].x2}});
    }
    return 1;
}
bool valid()
{
    compress();
    for(int i=0;i<n;i++){
        int idx=match[i];
        boxs.push_back(rect(input[i].first.first,input[i].first.second,input[idx].first.first,input[idx].first.second));
            if(boxs[i].x1>boxs[i].x2)swap(boxs[i].x1,boxs[i].x2);
            if(boxs[i].y1>boxs[i].y2)swap(boxs[i].y1,boxs[i].y2);
    }
    if(!sweep())return 0;
    for(int i=0;i<n;i++){
        swap(boxs[i].x1,boxs[i].y1);
        swap(boxs[i].x2,boxs[i].y2);
    }
    if(!sweep())return 0;

    return 1;
}
int main()
{
    while(cin>>n){
    //<<X,Y>,index>
    input.clear();
    boxs.clear();
    input.resize(2*n);
    for(int i=0; i<2*n; i++)
    {
        cin>>input[i].first.first>>input[i].first.second;
        input[i].second=i;
    }
    v=input;
    sort(v.begin(),v.end());
    //  <Y,index>
    set<pair<int,int>>st;
    set<pair<int,int>>::iterator it;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].second<n)
        {
            st.insert({v[i].first.second,v[i].second});
        }
        else
        {
            it=st.upper_bound({v[i].first.second,v[i].second});
            if(it==st.begin())
            {
                cout<<"syntax error"<<endl;
                return 0;
            }
            it--;
            match[it->second]=v[i].second;
            st.erase(it);
        }
    }

    if(!valid())cout<<"syntax error"<<endl;
    else
    {
        for(int i=0; i<n; i++)
        {
            cout<<match[i]-n+1<<endl;
        }
    }}
}
