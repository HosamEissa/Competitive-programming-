/*
 * SRM206-D1-500.cpp
 *
 *  Created on: Aug 23, 2017
 *      Author: Hossam Eissa
 *      Idea: first solution is bruteforce (n^5) loop to get point for left and right and up and down and use fifth loop to check if there is points inside the rectangle
 *            second solution is (n^3) sort points on X and use two loops to get left and right and then sort points in this range on y and do a line sweep on them
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
const double eps = 1e-9;
class SensorGrid {
public:
	vector<int> largestRectangle(int width, int height, vector<int> x,
			vector<int> y) {
		x.push_back(-1);
		y.push_back(-1);

		x.push_back(-1);
		y.push_back(height);

		x.push_back(width);
		y.push_back(-1);

		x.push_back(width);
		y.push_back(height);
		//<Y,X>
		int n = x.size();
		vector<pair<int, int> > v(n), v2(n);
		for (int i = 0; i < n; i++) {
			v2[i]= {x[i],y[i]};
		}
		sort(v2.begin(), v2.end());
		int area = 0;
		cerr << n << endl;
		int ansx, ansy, answ, ansh;
		for (int L = 0; L < n; L++) {
			for (int R = L; R < n; R++) {
				int mnx = v2[L].first + 1;
				int mxx = v2[R].first - 1;
				if (mnx > mxx)
					continue;
				vector<int>v;
				for(int i=0;i<n;i++){
					if(mnx<=x[i]&&x[i]<=mxx)
						v.push_back(y[i]);
				}
				v.push_back(-1);
				v.push_back(height);
				sort(v.begin(),v.end());
				cerr << "LEFT " << L << " Right " << R << " mnx = " << mnx
						<< " mxx = " << mxx << endl;
				for (int j = 0; j < v.size() - 1; j++) {
					int mny = v[j] + 1;
					int mxy = v[j + 1] - 1;
					if (mnx > mxx || mny > mxy)
						continue;
					cerr << " mny = " << mny << " mxy = " << mxy << endl;
					if (area < (mxx - mnx + 1) * (mxy - mny + 1)) {
						area = (mxx - mnx + 1) * (mxy - mny + 1);
						answ = (mxx - mnx + 1);
						ansh = (mxy - mny + 1);
						ansx = mnx;
						ansy = mny;
					}
					if (area == (mxx - mnx + 1) * (mxy - mny + 1)) {
						if (ansy > mny || (ansy == mny && ansx > mnx)
								|| (ansy == mny && ansx == mnx
										&& answ < (mxx - mnx + 1))) {
							answ = (mxx - mnx + 1);
							ansh = (mxy - mny + 1);
							ansx = mnx;
							ansy = mny;

						}

					}
				}
			}
		}
		return vector<int>()= {ansx,ansy,answ,ansh};
	}
	/*vector<int> largestRectangle(int width, int height, vector<int> x,
	 vector<int> y) {
	 x.push_back(-1);
	 y.push_back(-1);

	 x.push_back(-1);
	 y.push_back(height);

	 x.push_back(width);
	 y.push_back(-1);

	 x.push_back(width);
	 y.push_back(height);

	 int n = x.size();
	 int area = 0;
	 cerr << n << endl;
	 int ansx, ansy, answ, ansh;
	 for (int L = 0; L < n; L++) {
	 for (int R = 0; R < n; R++) {
	 if (x[L] > x[R])
	 continue;
	 for (int U = 0; U < n; U++) {
	 for (int D = 0; D < n; D++) {
	 if (y[D] > y[U])
	 continue;
	 int mnx, mxx, mny, mxy;
	 mnx = x[L] + 1;
	 mxx = x[R] - 1;
	 mny = y[D] + 1;
	 mxy = y[U] - 1;
	 if (mnx > mxx || mny > mxy)
	 continue;
	 cerr << L << " " << R << " " << U << " " << D << " "
	 << endl;
	 cerr << mnx << " " << mxx << " " << mny << " " << mxy
	 << " " << endl;
	 bool f = 1;
	 for (int i = 0; i < n; i++) {
	 if (mnx <= x[i] && mxx >= x[i] && mny <= y[i]
	 && y[i] <= mxy) {
	 f = 0;
	 break;
	 }
	 }
	 cerr << f << endl;
	 if (f) {
	 if (area < (mxx - mnx + 1) * (mxy - mny + 1)) {
	 area = (mxx - mnx + 1) * (mxy - mny + 1);
	 answ = (mxx - mnx + 1);
	 ansh = (mxy - mny + 1);
	 ansx = mnx;
	 ansy = mny;
	 }
	 if (area == (mxx - mnx + 1) * (mxy - mny + 1)) {
	 if (ansy > mny || (ansy == mny && ansx > mnx)
	 || (ansy == mny && ansx == mnx
	 && answ < (mxx - mnx + 1))) {
	 answ = (mxx - mnx + 1);
	 ansh = (mxy - mny + 1);
	 ansx = mnx;
	 ansy = mny;

	 }

	 }
	 }
	 }
	 }
	 }
	 }
	 return vector<int>()= {ansx,ansy,answ,ansh};
	 }*/

};
int main() {
	SensorGrid s;
	vector<int> v = s.largestRectangle(6, 5, { 5, 4 }, { 2, 4 });
	for (auto i : v)
		cout << i << " ";
	return 0;
}
