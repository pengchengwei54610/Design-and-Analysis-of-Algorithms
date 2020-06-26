#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

#define MAX 0xffff			//理论最大重量

int main() {
	int n, m, d;
	int** w, ** c;
	cout << "请输入机器由多少个部件组成 n" << endl;
	cin >> n;
	cout << "请输入由多少个不同的供应商 m" << endl;
	cin >> m;
	cout << "请输入最大总价格d" << endl;
	cin >> d;
	w = new int* [n + 1];		
	c = new int* [n + 1];
	int i, j;
	for (i = 0; i <= n; ++i) {
		w[i] = new int[m + 1];
		c[i] = new int[m + 1];
	}
	cout << "请输入各机器部件不同供应商的价格" << endl;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			cin >> c[i][j];
	cout << "请输入各机器部件不同供应商的重量" << endl;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			cin >> w[i][j];
	int* bj_gys = new int[n + 1]{ 0 };		
	int* res_bj_gys = new int[n + 1]{ 0 };	
	int d_now = 0;	
	int w_now = 0;	
	int w_min = MAX;

	i = 1;
	j = 1;
	for (; i > 0;) {


		if (d_now + c[i][j] > d) {	
			if (j < m)	
				++j;
			else {		
				--i;
				d_now -= c[i][bj_gys[i]];
				w_now -= w[i][bj_gys[i]];
				while (i > 0 && bj_gys[i] >= m) {
					--i;
					d_now -= c[i][bj_gys[i]];
					w_now -= w[i][bj_gys[i]];
				}
				j = bj_gys[i] + 1;
			}
		}
		else {	
			d_now += c[i][j];
			w_now += w[i][j];
			bj_gys[i] = j;
			if (i == n) {	
				if (w_now < w_min) {	
					for (int i_w = 1; i_w <= n; ++i_w)	
						res_bj_gys[i_w] = bj_gys[i_w];
					w_min = w_now;		
				}
				if (j < m) {	
					w_now -= w[i][j];
					d_now -= c[i][j];
					++j;
				}
				else {		
					d_now -= c[i][bj_gys[i]];
					w_now -= w[i][bj_gys[i]];					
					--i;
					d_now -= c[i][bj_gys[i]];
					w_now -= w[i][bj_gys[i]];
					while (i > 0 && bj_gys[i] >= m) {
						--i;
						d_now -= c[i][bj_gys[i]];
						w_now -= w[i][bj_gys[i]];
					}
					j = bj_gys[i] + 1;
				}
			}
			else {	
				++i;
				j = 1;
			}
		}

	}
	cout << endl << "最小重量 " << endl << w_min << endl;
	cout << endl << "各部件供应商" << endl;
	for (i = 1; i <= n; ++i)
		cout << res_bj_gys[i] << " ";
	cout << endl;

	return 0;
}