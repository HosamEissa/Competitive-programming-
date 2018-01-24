#include <bits/stdc++.h>
using namespace std;
const int SIZE=8600001;
const int N=1e5+5;
#define M ((L+R)/2)
int l[SIZE], r[SIZE], st[SIZE], NODES = 0;
int newleaf(int value) {
    int p = ++NODES;
    l[p] = r[p] = 0; // null
    st[p] = value;
    return p;
}
int newparent(int lef, int rig) {
    int p = ++NODES;
    l[p] = lef;
    r[p] = rig;
    st[p] = st[lef] + st[rig]; // immediately update value from children
    return p;
}
int build(vector<int>&arr, int L=0, int R=N-1) {
    if (L == R) return newleaf(arr[L]); // construct as leaf
    else return newparent(build(arr, L, M), build(arr, M+1, R)); // construct as parent
}
int update(int i, int x, int p, int L=0, int R=N-1) {
    if (L == R) return newleaf(st[p] + x);
    if (i <= M) return newparent(update(i, x, l[p], L, M), r[p]);
    else        return newparent(l[p], update(i, x, r[p], M + 1, R));
}
int rangecopy(int a, int b, int p, int revert, int L=0, int R=N-1) {
    if (b < L || R < a) return p; // keep version
    if (a <= L && R <= b) return revert; // reverted version
    return newparent(rangecopy(a, b, l[p], l[revert], L, M),
                     rangecopy(a, b, r[p], r[revert], M+1, R));
}
vector<int>vals;
int get(int K,int p,int p2,int L=0,int R=N-1){
    //cout<<K<<" "<<L<<" "<<R<<" "<<vals[L]<<" "<<vals[R]<<endl;
    if(K<vals[L])
        return st[p]-st[p2];
    if(vals[R]<=K)
        return 0;
    return get(K,l[p],l[p2],L,M)+get(K,r[p],r[p2],M+1,R);
}
vector<int>roots;
int main()
{
//    cin.sync_with_stdio(0);
 //   cin.tie(0);
    int n,m;
    scanf("%d",&n);
    vector<int>v,v2(n);
    roots.resize(n+2);
    vals.resize(n+2,1e9+1);
//    roots[0]=build(v,0,n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        v2[i]=a;
        mp[a];
    }
    scanf("%d",&m);
    vector<pair<int,pair<int,int > > >in;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        in.push_back({a,{b,c}});
    }
    int cnt=0;
    for(auto & p:mp){
        vals[cnt]=p.first;
        p.second=cnt++;
    }
    v.resize(n+1);
    roots[0]=build(v,0,cnt);
    for(int i=0;i<n;i++){
        v2[i]=mp[v2[i]];
   //     cout<<v2[i]<<" ";
        roots[i+1]=update(v2[i],1,roots[i],0,cnt);
    }
    int last=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        a=in[i].first^last;
        b=in[i].second.first^last;
        c=in[i].second.second^last;
        if(a<1)
            a=1;
        if(b>n)
            b=n;
        if(a>b){
            last=0;
        }
        else
//        cout<<a<< " "<<b<<" "<<c<<endl;
        last=get(c,roots[b],roots[a-1],0,cnt);
        printf("%d\n",last);
    }
}
