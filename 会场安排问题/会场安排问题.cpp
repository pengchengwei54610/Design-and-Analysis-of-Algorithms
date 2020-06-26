#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cout << "请输入活动数：" << endl;
	cin >> n;
	int* start = new int[n], * end = new int[n];
	cout << "请输入 " << n << " 个活动对应的开始时间和结束时间" << endl;
	int i;
	for (i = 0; i < n; ++i)
		cin >> start[i] >> end[i];
	//快排
	sort(start, start + n);
	sort(end, end + n);
	int j = 0, count = 0;
	for (i = 0; i < n; ++i) {
		if (start[i] < end[j])
			++count;
		else
			++j;
	}
	cout << "所需要的会场数有：" << endl << count << endl;
	delete[] start, end;
	return 0;
}