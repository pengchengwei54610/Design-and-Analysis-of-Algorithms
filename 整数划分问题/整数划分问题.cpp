#include<iostream>
using namespace std;
//整数划分，n为需要划分的正整数，m为划分中最大的那个数
int equationcount(int n, int m)
{
	if (n == 1 || m == 1) {
		return 1;
	}
	else if (n > m) {
		return equationcount(n - m, m) + equationcount(n, m - 1);
	}
	else if (n < m) {
		return equationcount(n, n);
	}
	else {
		return 1 + equationcount(n, m - 1);
	}
}
int main()
{
	int a;
	cout<<"请输入需要划分的正整数" << endl;
	cin >> a;
	cout <<"共"<< equationcount(a, a)<<"种划分";
	return 0;
}
