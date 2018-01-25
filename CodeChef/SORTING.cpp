#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE=72000005;
const int N=5e5+5;
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
int get(int K,int p,int p2,int L=0,int R=N-1){
   // cout<<K<<" "<<L<<" "<<R<<" "<<st[l[p]]<<" " <<st[l[p2]]<<endl;
    if(L==R)
        return L;
    if(st[l[p]]-st[l[p2]]>=K){
        return get(K,l[p],l[p2],L,M);
    }
    else {
        return get(K-st[l[p]]+st[l[p2]],r[p],r[p2],M+1,R);
 
    }
}
vector<int>roots;
int n,m;
vector<int>v(n+1),v2(n+1),v3(n+1);
ll solve(int L ,int R){
        //cout<<L<<" "<<R<<endl;
        if(R<=L)
            return 0;
        int idx=get((R-L+2)/2,roots[R],roots[L-1],1,n);
       // cout<<"idx "<<" "<<idx<<endl;
        //system("pause");
        return R-L+1+solve(L,v3[idx]-1)+solve(v3[idx]+1,R);
}
int main()
{
//    cin.sync_with_stdio(0);
 //   cin.tie(0);
    scanf("%d",&n);
    roots.resize(n+2);
    v.resize((n+1));
    v2.resize((n+1));
    v3.resize(n+1);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        v3[i]=a;
        v2[a]=i;
    }
    roots[0]=build(v,1,n);
    for(int i=1;i<=n;i++){
      //      cout<<v2[i]<<endl;
        roots[i]=update(v2[i],1,roots[i-1],1,n);
    }
    cout<<solve(1,n)<<endl;
}
