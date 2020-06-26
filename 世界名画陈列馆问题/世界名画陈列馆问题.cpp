#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
#define MAX 0xffff
int m = 0, n = 0;
int** room, ** is_watched, ** has_robot, ** solution;
int k = 0, k_min = MAX, x;
int x1, x2;
void set_robot(int i, int j) {
	has_robot[i][j] = 1;
	++k;
	++is_watched[i][j];
	if (is_watched[i][j] == 1)
		++x;
	++is_watched[i - 1][j];
	if (is_watched[i - 1][j] == 1)
		++x;
	++is_watched[i][j - 1];
	if (is_watched[i][j - 1] == 1)
		++x;
	++is_watched[i + 1][j];
	if (is_watched[i + 1][j] == 1)
		++x;
	++is_watched[i][j + 1];
	if (is_watched[i][j + 1] == 1)
		++x;
}
void remove_robot(int i, int j) {
	has_robot[i][j] = 0;
	--k;
	--is_watched[i][j];
	if (is_watched[i][j] == 0)
		--x;
	--is_watched[i - 1][j];
	if (is_watched[i - 1][j] == 0)
		--x;
	--is_watched[i][j - 1];
	if (is_watched[i][j - 1] == 0)
		--x;
	--is_watched[i + 1][j];
	if (is_watched[i + 1][j] == 0)
		--x;
	--is_watched[i][j + 1];
	if (is_watched[i][j + 1] == 0)
		--x;
}

void next_room(int& i, int& j) {
	do {
		++j;
		if (j > m) {
			++i;
			j = 1;
		}
	} while (!(i > n || !is_watched[i][j]));
}

void search(int i, int j) {
	next_room(i, j);

	if (i > n) {
		if (k < k_min) {
			k_min = k;
			for (int ii = 1; ii <= n; ++ii)
				for (int jj = 1; jj <= m; ++jj)
					solution[ii][jj] = has_robot[ii][jj];
		}
		return;
	}
	if (k + (x1 - x) / 5 >= k_min)
		return;
	if (i < n - 1 && (k + (x2 - x) / 5) > k_min)
		return;
	if (i < n) {
		set_robot(i + 1, j);
		search(i, j);
		remove_robot(i + 1, j);
	}
	if (is_watched[i][j + 1] == 0) {
		set_robot(i, j);
		search(i, j);
		remove_robot(i, j);
	}
	if ((j < m) && ((is_watched[i][j + 1] == 0) || (is_watched[i][j + 2] == 0))) {
		set_robot(i, j + 1);
		search(i, j);
		remove_robot(i, j + 1);
	}
}

int main() {
	cout << "请输入陈列室行n 列m 数" << endl;
	cin >> n >> m;
	int flag = 0;
	int temp;
	if (m < n) {
		flag = 1;
		temp = m;
		m = n;
		n = temp;
	}
	temp = m / 4 + 1;
	if (m % 4 == 3)
		temp++;
	else if (m % 4 == 2)
		temp += 2;
	x1 = m * n + 4;
	x2 = m * n + temp + 4;
	int i, j;
	room = new int* [n + 2];
	is_watched = new int* [n + 2];
	has_robot = new int* [n + 2];
	solution = new int* [n + 2];
	for (i = 0; i <= n + 1; ++i) {
		room[i] = new int[m + 2]{ 0 };
		is_watched[i] = new int[m + 2]{ 0 };
		has_robot[i] = new int[m + 2]{ 0 };
		solution[i] = new int[m + 2]{ 0 };
	}
	for (i = 0; i <= m + 1; i++) {
		is_watched[0][i] = 1;
		is_watched[n + 1][i] = 1;
	}
	for (i = 0; i <= n + 1; i++) {
		is_watched[i][0] = 1;
		is_watched[i][m + 1] = 1;
	}
	search(1, 0);
	cout << "所需设置最少机器人数 " << k_min << endl;
	cout << "设置情况如下：(0表示不设置机器人，1表示设置机器人)" << endl;
	if (flag) {
		for (i = 1; i <= m; ++i) {
			for (j = 1; j <= n; ++j) {
				cout << solution[j][i] << ' ';
			}
			cout << endl;
		}
	}
	else {
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				cout << solution[i][j] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}