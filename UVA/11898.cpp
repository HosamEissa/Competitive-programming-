#include <bits/stdc++.h>
#include <map>
using namespace std;
#define ll long long
#define se second
#define fi first
#define mk(a, b) make_pair(a, b)
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvpi vector<vector<pii>>
#define pli pair<ll, int>
#define INF 1 << 29
#define MOD 1000000007
#define MAX (int)2e5 + 5
#define FI freopen("i.txt", "r", stdin);
#define FO freopen("o.txt", "w", stdout);
#define edge pair<int, pair<int, int>>
int n, t, block=sqrt(200000);
struct query {
	int le, ri, pos;
};
vector<query> q;
bool cmp(query &q1, query &q2) {
	int x1 = q1.le / block;
	int x2 = q2.le / block;
	if (x1 != x2)
		return (x1 < x2);
	return (q1.ri < q2.ri);
}
int ans = 0, answer[15001];
int arr[10005];
int v[200006];

void add(int x) {
    arr[v[x]]++;
}
void remove(int x) {
    arr[v[x]]--;
}
int main() {
   // FO;
 //   FI;
    int t;
    scanf("%d",&t);
    while(t--){
            memset(arr,0,sizeof arr);
            memset(v,0,sizeof v);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	int k;
	scanf("%d",&k);
	q.clear();
	q.clear();
	q.resize(k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &q[i].le, &q[i].ri);
		q[i].pos = i;
		q[i].le--;
		q[i].ri--;
	}
	sort(q.begin(), q.end(), cmp);
	int currl = 0;
	int currr = 0;
	for (int i = 0; i < k; i++) {
		while (currl < q[i].le) {
			remove(currl);
			currl++;
		}
		while (currl > q[i].le) {
			currl--;
			add(currl);
		}
		while (currr <= q[i].ri) {
			add(currr);
			currr++;
		}
		while (currr > q[i].ri + 1) {
			currr--;
			remove(currr);
		}
		int ans=1e5;
		int l=0;
        for(int i=1;i<=1e4;i++){
            if(arr[i]>1){
                ans=0;
                break;
            }
            if(arr[i]&&!l){
                l=i;
            }
            else if(arr[i]&&l){
                ans=min(ans,i-l);
                l=i;
            }
        }
		answer[q[i].pos] = ans;
	}
	for (int i = 0; i < k; i++) {
		printf("%d\n", answer[i]);
	}
	}
}
