#include<iostream>
using namespace std;
#define string_max_length 6
int cal_length1(int first_char, int length1)//计算首字母为first_char，长度为length1的字符串个数
{
	int num1;
	int sum1 = 0;
	if (length1 == 1)
		return 1;
	else
	{
		for (num1 = first_char + 1; num1 <= 26; num1++)
		{
			sum1 += cal_length1(num1, length1 - 1);
		}
	}
	return sum1;
}
//计算给定字符串前字符串的总数
int sequential_cal()
{
	int length, length1;
	int n;
	int sum = 0;
	char test[string_max_length + 1];
	cin >> test;
	length = strlen(test);
	for (int i = 1; i < length; i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			sum += cal_length1(j, i);
		}
	}//计算小于字符串长度的字符串数量
	int h = test[0] - 'a' + 1;
	for (int i = 1; i < h; i++)
	{
		sum += cal_length1(i, length);
	}//计算开头字母小于字符串，长度相同的字符串数量
	int count1 = h;
	for (int i = 1; i < length; i++)
	{
		n = test[i] - 'a' + 1;
		length1 = length - i;
		for (int j = count1 + 1; j < n; j++)
		{
			sum += cal_length1(j, length1);
		}
		count1 = n;
	}//分别计算后面每一位字母可取的较小字符串数量
	return sum;
}

int main()
{
	int number1;
	int count1 = 0;
	cin >> number1;
	while (count1 < number1)
	{
		cout << sequential_cal() + 1 << endl;
		count1++;
	}
	return 0;
}