/*
 * SRM513-D2-1000.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: Hossam Eissa
 *      Idea: try all possible solution of taking cells or rows or cols
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
class CutTheNumbers {
public:
	int mat[5][5], idx[5][5], n, m;
	int dp[65536 + 5];
	bool check() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (mat[i][j] != -1)
					return 0;
		return 1;
	}
	void print() {
		cerr << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cerr << mat[i][j] << " ";
			}
			cerr << endl;
		}
		cerr << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

	}
	int getidx(int r, int c) {
		return idx[r][c];
	}
	int solve(int msk) {
		if (msk == (1 << (n * m)) - 1) {
			return 0;

		}
		int &mxval = dp[msk];
		if (~mxval)
			return mxval;
		mxval = 0;
		for (int i = 0; i < 2; i++) {
			//row
			if (i == 0) {
				for (int r = 0; r < n; r++) {
					//which row
					for (int c = 1; c <= m; c++) {
						//number of cells
						for (int x = 0; x <= m - c; x++) {
							//starting cell
							int sum = 0;
							int can = 1;
							for (int hh = x; hh < x + c; hh++) {
								if (msk & (1 << (getidx(r,hh))))
									can = 0;
							}
							if (can) {
								int nmsk = msk;
								for (int hh = x; hh < x + c; hh++) {
									nmsk |= (1 << (getidx(r,hh)));
									sum = sum * 10 + mat[r][hh];
								}
								sum += solve(nmsk);
							}
							mxval = max(sum, mxval);
						}
					}
				}

			} else {
				//col
				for (int r = 0; r < m; r++) {
					//which col
					for (int c = 1; c <= n; c++) {
						//number of cells
						for (int x = 0; x <= n - c; x++) {
							//starting cell
							int sum = 0;
							int can = 1;
							for (int hh = x; hh < x + c; hh++) {
								if (msk & (1 << (getidx(hh,r))))
									can = 0;
							}
							if (can) {
								int nmsk = msk;
								for (int hh = x; hh < x + c; hh++) {
									nmsk |= (1 << (getidx(hh,r)));
									sum = sum * 10 + mat[hh][r];
								}
								sum += solve(nmsk);
							}
							mxval = max(sum, mxval);
						}
					}
				}
			}
		}
		return mxval;
	}
	int maximumSum(vector<string> board) {
		n = board.size();
		m = board[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat[i][j] = board[i][j] - '0';

			}
		}
		memset(dp,-1,sizeof dp);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				idx[i][j] = cnt++;
			}
		}
		return solve(0);
	}

};
int main() {
	CutTheNumbers c;
	cout << c.maximumSum( { "001", "010", "111", "100" });
	return 0;
}
