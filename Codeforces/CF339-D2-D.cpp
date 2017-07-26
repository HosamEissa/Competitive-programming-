/*
Author: Hossam Eissa
Idea:but nodes in segmenttree and do the operation he says on its levels
*/
#include<bits/stdc++.h>
#include<unordered_map>
#include<sstream>
#include <map>
#include<functional>
#include<stack>
#include<list>
#include<iomanip>
using namespace std;
#define ll long long
#define MAX 200000+5
#define MOD 1000000007 
#define INF 1000000000
#define edge pair<ll,ll>
#define sz size()
//int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
//int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

struct  node
{
	int val;

};
int tree[262144];
vector<int>v;
void build(int low, int high, int pos,int level){
	if (low == high){
		tree[pos] = v[low];
		return;
	}
	int mid = (low + high) / 2;
	build(low, mid, 2 * pos + 1, level - 1);
	build(mid+1, high, 2 * pos + 2, level - 1);
	if (level % 2){
		int& c = tree[pos];
		int& c1 = tree[2*pos+1];
		int& c2 = tree[2*pos+2];
		c = (c1 | c2);
	}
	else {
		int& c = tree[pos];
		int& c1 = tree[2 * pos + 1];
		int& c2 = tree[2 * pos + 2];
		c = (c1 ^ c2);

	}
}
void update(int qlow, int val, int low, int high, int pos, int level){
	if (low == high&&qlow==low){
		tree[pos] = val;
		return;
	}
	if (high<qlow || low>qlow)return;
	int mid = (low + high) / 2;
	update(qlow,val,low, mid, 2 * pos + 1, level - 1);
	update(qlow,val,mid + 1, high, 2 * pos + 2, level - 1);
	if (level % 2){
		int& c = tree[pos];
		int& c1 = tree[2 * pos + 1];
		int& c2 = tree[2 * pos + 2];
		c = (c1 | c2);
	}
	else {
		int& c = tree[pos];
		int& c1 = tree[2 * pos + 1];
		int& c2 = tree[2 * pos + 2];
		c = (c1 ^ c2);
	}
}

int main()
{


	//int c = (1 << 30);
	//cout << c;
	int n, m;
	cin >> n >> m;
	v.resize(1 << n);
	int siz = v.size();
	for (int i = 0; i < (1 << n); i++){
		cin >> v[i];
	}
	build(0, siz - 1, 0, n);
	while (m--){
		int p, b;
		scanf("%d%d", &p, &b);

		update(p-1, b, 0, siz-1, 0, n);
		printf("%d\n", tree[0]);
	}

	//system ("pause");
	//return 0;
}
