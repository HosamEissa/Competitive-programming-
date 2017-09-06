/*
 * SPOJ_MINMOVE.cpp
 *
 *  Created on: Sep 1, 2017
 *      Author: Hossam Eissa
 *      Idea:add string to it's back then do a (nlogn) suffix array and print number of the first suffix
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
const int Mx = 2e5 + 9;
typedef pair<int,int> ii;

const int n_ = 200005;

char str[n_];
int rnk[n_], suf[n_], newRnk[n_], LCP[n_], head[128], nxt[n_], rnkStrt[n_], newSuf[n_];

struct cmp{
  int len;
  bool operator()(int a, int b)const {
    return rnk[a] < rnk[b] || (rnk[a] == rnk[b] && rnk[a + len] < rnk[b + len]);
  }
};

void buildSuffArray(){
  int len = 0;
  memset(head, -1, sizeof head);
  for(; !len || str[len - 1]!=0; len++){
    nxt[len] = head[str[len]];
    head[str[len]] = len;
  }
  int ng = 0, ns = 0;
  for(int i=0; i<128; i++){
    if(head[i] == -1) continue;
    rnkStrt[ng] = ns;
    for(int j=head[i]; j != -1 ; j = nxt[j]){
      suf[ns++] = j;
      rnk[j] = ng;
    }
    ng++;
  }
  newRnk[len - 1] = -1;
  newSuf[0] = len - 1;
  for(int h=1; newRnk[len - 1] != len - 1; h <<= 1){
    cmp c = {h};
    for(int i=0; i<len; i++){
      int j = suf[i] - h;
      if(j < 0) continue;
      newSuf[rnkStrt[rnk[j]]++] = j;
    }
    for(int i=1; i<len; i++){
      bool newGrp = c(newSuf[i-1], newSuf[i]);
      newRnk[i] = newRnk[i-1] + newGrp;
      if(newGrp)
        rnkStrt[newRnk[i]] = i;
    }
    for(int i=0; i<len; i++){
      suf[i] = newSuf[i];
      rnk[suf[i]] = newRnk[i];
    }
  }
}

void buildLCP(){
  int len = 0;
  for(int i=0; str[i]; i++){
    int j = suf[rnk[i] - 1];
    while(str[i + len] == str[j + len])
      len++;
    LCP[rnk[i]] = len;
    if(len) len--;
  }
}

int T, k;
int suf2[100005];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	str[n] = ' ';
	for (int i = 0; i < n; i++)
		str[i + n] = str[i];
	str[2*n]=123;
	buildSuffArray();
	//build_lcp();
	//cerr << n << endl;
	for (int i = 0; i <= 2 * n; i++) {
		int idx = suf[i];
		if (idx < n) {
			cout << idx << endl;
			//printf("%s\n", str + idx);
			return 0;
		}
	}
	return 0;
}
