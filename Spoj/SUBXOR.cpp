/*
 * SPOJ_SUBXOR.cpp
 *
 *  Created on: Aug 30, 2017
 *      Author: Hossam Eissa
 *      Idea:for each prefix sum find how many index from 0 to i have xor sum less than k then add it to the trie
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

 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
int n, m, k;
struct node {
	node * a[2];
	int cnt[2];
	node() {
		cnt[0] = cnt[1] = 0;
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
void insertnode(int idx) {
	node* cur = root;
	//cout<<idx<<" "<<s<<endl;
	for (int i = 20; i >= 0; i--) {
		bool bit = idx & (1 << i);

		cur->cnt[bit]++;
		if (cur->a[bit] == NULL)
			cur->a[bit] = new node();
		cur = cur->a[bit];
	}
}
ll Find(int idx) {
	node* cur = root;
	int ans = 0;
	int val = idx;

	for (int i = 20; i >= 0; i--) {
		bool d = (idx & 1 << i);
		bool d2 = (k & 1 << i);
		//	cerr << i << " " << d << " " << d2 << endl;
		if (d && d2) {

			ans += cur->cnt[1];

			if (cur->a[0] != NULL)
				cur = cur->a[0];
			else
				return ans;

		} else if (d && !d2) {
			if (cur->a[1] != NULL)
				cur = cur->a[1];
			else
				return ans;
		} else if (!d && d2) {
			ans += cur->cnt[0];

			if (cur->a[1] != NULL)
				cur = cur->a[1];
			else
				return ans;
		} else {
			if (cur->a[0] != NULL)
				cur = cur->a[0];
			else
				return ans;

		}
	}
	//5ans += cur->cnt;
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		root = new node();
		insertnode(0);
		scanf("%d%d", &n, &k);
		ll ans = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			sum ^= a;
			ans += Find(sum);
			//cerr << ans << endl;
			//cerr << "done" << endl;
			insertnode(sum);
		}
		cout << ans << endl;
		del(root);
	}

	return 0;
}
