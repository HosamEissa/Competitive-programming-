/*
 * LIVEARCHIVE_4682.cpp
 *
 *  Created on: Aug 29, 2017
 *      Author: Hossam Eissa
 *      Idea: add the prefix XOR sum at each index to A trie and then for each sum find the maximum value in the trie that Xor sum with it gives maximum value
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const double eps = 1e-9;
int arr[N], sum[N];
struct node {
	node * a[2];
//	int idx;
	node() {
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
void insertnode(int val) {
	node* cur = root;
	//cout<<idx<<" "<<s<<endl;
	for (int i = 31; i >= 0; i--) {
		bool x = val & (1 << i);
		if (cur->a[x] == NULL)
			cur->a[x] = new node();
		cur = cur->a[x];
	}

}
int Find(int val) {
	node* cur = root;
	int ans = 0;
	for (int i = 31; i >= 0; i--) {
		if (val & (1 << i)) {
			if (cur->a[0] != NULL) {
				cur = cur->a[0];
			} else {
				ans |= (1 << i);
				cur = cur->a[1];
			}

		} else {
			if (cur->a[1] != NULL) {
				ans |= (1 << i);
				cur = cur->a[1];
			} else {
				cur = cur->a[0];
			}
		}
	}
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		root = new node();
		scanf("%d", &n);
		int mx = 0;
		//cerr << " " << n << endl;
		insertnode(0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			mx = max(mx, arr[i]);
			if (i)
				sum[i] = sum[i - 1] ^ arr[i];
			else
				sum[i] = arr[i];
			insertnode(sum[i]);
			mx = max(mx, sum[i]);
		}
		for (int i = 0; i < n; i++) {
			mx = max(mx, sum[i] ^ Find(sum[i]));
		}
		printf("%d\n", mx);
		del(root);
	}
	return 0;
}
