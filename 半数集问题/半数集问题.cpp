#include<iostream>
#define max_num 100000
using namespace std;
int count1[max_num];
int half(int value)
{
	if (count1[value] > 0)
		;
	else
	{
		if (value == 1)
		{
			count1[value] = 1;
		}
		else
		{
			int sum = 0;
			for (int count2 = 1; count2 <= value / 2; count2++)
			{
				sum += half(count2);
			}
			sum += 1;
			count1[value] = sum;
		}
	}
	return count1[value];
}
int main()
{
	int n;
	cout << "请输入初始自然数" << endl;
	cin >> n;
	cout << "半数集个数为" << endl;
	cout << half(n) << endl;
}