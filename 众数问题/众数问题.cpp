#include<iostream>
using namespace std;
#define max_number 4090
int main()
{
	int data[max_number] = { 0 };
	cout << "请输入元素个数" << endl;
	int n;
	cin >> n;
	for (int count1 = 0; count1 < n; count1++)
	{
		int temp;
		cin >> temp;
		data[temp]++;
	}
	int max_pos = 0;
	for (int count1 = 1; count1 < max_number; count1++)
	{
		if (data[count1] > data[max_pos])
			max_pos = count1;
	}
	cout << "众数为：" << max_pos << endl;
	cout << "重数为：" << data[max_pos];
	return 0;
}