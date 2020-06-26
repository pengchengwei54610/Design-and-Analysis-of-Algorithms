#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;
bool** f;
bool is_solute(int* S, int n, int c) {
	f = new bool* [n + 1];
	int i, j;
	for (i = 0; i <= n; ++i)
		f[i] = new bool[c + 1];
	for (i = 0; i <= n; ++i)
		f[i][0] = true;
	for (j = 1; j <= c; ++j)
		f[0][j] = false;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= c; ++j) {
			if (S[i - 1] > j)
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = f[i - 1][j] || f[i - 1][j - S[i - 1]];
		}
	return f[n][c];
}

int* solute(int* S, int n, int c) {
	if (!f[n][c])
		return NULL;

	int i = n, j = c, num = 0;
	int* res = new int[n] {0};
	while (i) {
		if (f[i][j] && !f[i - 1][j]) {
			res[num++] = S[i - 1];
			j = j - S[i - 1];
		}
		if (!j)
			break;
		--i;
	}

	return res;
}

int main() {
	int n, c, i;
	int* S;
	cout << "请输入集合S的大小n" << endl;
	cin >> n;
	cout << "请输入正整数c" << endl;
	cin >> c;
	cout << "请输入集合中的" << n << "个元素" << endl;
	S = new int[n];
	for (i = 0; i < n; ++i)
		cin >> S[i];
	if (is_solute(S, n, c)) {
		int* res = solute(S, n, c);
		for (i = 0; i < n; ++i)
			if (res[i + 1] == 0)
				break;

		cout << "子集中的元素为" << endl;
		for (; i >= 0; --i)
			cout << S[i] << " ";
		cout << endl;
	}
	else {
		cout << "No Sulution!" << endl;
	}
	return 0;
}