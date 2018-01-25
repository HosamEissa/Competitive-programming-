#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
int get(int p,int ql,int qr,int L=0,int R=N-1){
   // cout<<p<<" "<<ql<<" "<<qr<<" "<<L<<" "<<R<<endl;
    if(ql>R||qr<L)
        return 0;
    if(ql<=L&&R<=qr)
        return st[p];
    return get(l[p],ql,qr,L,M)+get(r[p],ql,qr,M+1,R);
}
void print(int p,int L,int R){
    if(L==R){
        cout<<L<<" "<<st[p]<<endl;
        return;
    }
    print(l[p],L,M);
    print(r[p],M+1,R);

}
vector<int>roots;
int n,m;
vector<int>v(n+1),v2(n+1),v3(n+1,-1);

int main()
{
//    cin.sync_with_stdio(0);
 //   cin.tie(0);
    scanf("%d",&n);
    roots.resize(n+2);
    v.resize((n+1));
    v2.resize((n+1));
    v3.resize(1e6+5,-1);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        v2[i]=a;
    }
    roots[0]=build(v,1,n);
    for(int i=1;i<=n;i++){
        int p=roots[i-1];
     //   cout<<v3[v2[i]]<<endl;
        if(v3[v2[i]]!=-1)
            p=update(v3[v2[i]],-1,p,1,n);
        roots[i]=update(i,1,p,1,n);
       // puts("newtree\n\n");
       // print(roots[i],1,n);
        v3[v2[i]]=i;
    }
    scanf("%d",&m);
    while(m--){
            int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",get(roots[b],a,b,1,n));

    }

}
