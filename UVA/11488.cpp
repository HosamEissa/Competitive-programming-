/*
 * UVA _11488.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: Hossam Eissa
 *      Idea: add all the strings into trie with cnt value in every node tells you how many strings in here then dfs the trie to find the answer
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4e5 + 1;
const double eps = 1e-9;
char st[N][202];
struct node {
	node * a[2];
	ll cnt;
	node() {
		cnt = 0;
		for (int i = 0; i < 2; i++)
			a[i] = NULL;
	}
}*root;
void del(node* u) {
	for (int i = 0; i < 2; i++)
		if (u->a[i] != NULL)
			del(u->a[i]);
	delete u;
}
void insertnode(char* s) {
	node* cur = root;
	cur->cnt++;
	//cerr<<s<<endl;
	for (int i = 0; s[i]; i++) {
		if (cur->a[s[i] - '0'] == NULL)
			cur->a[s[i] - '0'] = new node();
		cur = cur->a[s[i] - '0'];
		cur->cnt++;
	}

}
ll solve(node* n,int depth) {
	if(n==NULL)return 0;
	ll ans=depth*n->cnt;
	for (int i = 0;i<2; i++) {
		ans=max(ans,solve(n->a[i],depth+1));
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		root =new node();
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf(" %s", st[i]);
			insertnode(st[i]);
		}
		ll ans = solve(root,0);
		del(root);
		printf("%lld\n",ans);
	}
	return 0;
}
