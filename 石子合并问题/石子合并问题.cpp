#include<iostream>
using namespace std;
#define MAX_INF 2000

int max(const int a, const int b) {
	return a > b ? a : b;
}

int min(const int a, const int b) {
	return a < b ? a : b;
}


int main()
{
	int n;
	cout << "输入总共的石子堆数n" << endl;
	cin >> n;
	int* arr = new int[2 * n + 1];
	cout << "输入每堆石子个数" << endl;
	int i, j;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	int* sum = new int[2 * n + 1]{ 0 };
	for (i = 1; i <= 2 * n; ++i)
		sum[i] = sum[i - 1] + arr[i];
	int** fmin = new int* [3 * n];
	int** fmax = new int* [3 * n];
	for (i = 0; i < 3 * n; ++i) {
		fmin[i] = new int[3 * n]{ 0 };
		fmax[i] = new int[3 * n]{ 0 };
	}
	for (i = 2 * n - 1; i >= 1; --i) {
		for (j = i + 1; j < i + n; ++j) {
			fmin[i][j] = MAX_INF;
			for (int k = i; k < j; ++k) {
				fmin[i][j] = min(fmin[i][j], fmin[i][k] + fmin[k + 1][j] + sum[j] - sum[i - 1]);
				fmax[i][j] = max(fmax[i][j], fmax[i][k] + fmax[k + 1][j] + sum[j] - sum[i - 1]);
			}
		}
	}
	int max_score = 0, min_score = MAX_INF;
	for (i = 1; i <= n; ++i) {
		min_score = min(min_score, fmin[i][i + n - 1]);
		max_score = max(max_score, fmax[i][i + n - 1]);
	}
	cout << "最小得分：" << min_score << endl;
	cout << "最大得分：" << max_score << endl;
	return 0;
}
