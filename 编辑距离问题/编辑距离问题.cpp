#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int getvalue_equal(int** f, int i, int j) {
	int t;
	if (i == 1 && j == 1)
		t = 0;
	else if (i == 1)
		t = f[i][j - 1];
	else if (j == 1)
		t = f[i - 1][j];
	else
		t = f[i - 1][j - 1];

	if (t < abs(i - 1))
		t = abs(i - 1);
	f[i][j] = t;
	return t;
}

int getvalue_notequal(int** f, int i, int j) {
	int t;
	if (i == 1 && j == 1)
		t = 1;
	else if (i == 1)
		t = f[i][j - 1] + 1;
	else if (j == 1)
		t = f[i - 1][j] + 1;
	else {
		t = f[i - 1][j - 1] < f[i - 1][j] ? f[i - 1][j - 1] : f[i - 1][j];
		t = t < f[i][j - 1] ? t : f[i][j - 1];
		t = t + 1;
	}

	if (t < abs(i - 1))
		t = abs(i - 1);
	f[i][j] = t;
	return t;
}

int solve(string a, string b) {
	int** f = new int* [a.length() + 1];
	for (int i = 0; i < a.length() + 1; ++i)
		f[i] = new int[b.length() + 1]{ 0 };

	for (int i = 0; i <= a.length(); ++i)
		f[i][0] = i;
	for (int j = 0; j <= b.length(); ++j)
		f[0][j] = j;

	for (int i = 1; i <= a.length(); ++i) {
		for (int j = 1; j <= b.length(); ++j) {
			if (a[i - 1] == b[j - 1])
				getvalue_equal(f, i, j);
			else
				getvalue_notequal(f, i, j);
		}
	}
	return f[a.length()][b.length()];
}

int main() {
	string a, b;
	cout << "ÇëÊäÈë×Ö·û´®A" << endl;
	cin >> a;
	cout << "ÇëÊäÈë×Ö·û´®B" << endl;
	cin >> b;
	cout << "×Ö·û´®AºÍBµÄ±à¼­¾àÀëÎª£º" << solve(a, b) << endl;
	return 0;
}