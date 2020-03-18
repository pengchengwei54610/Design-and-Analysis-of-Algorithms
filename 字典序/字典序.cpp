#include<iostream>
using namespace std;
#define string_max_length 6
int cal_length1(int first_char,int length1)//计算首字母为first_char，长度为length1的字符串个数
{
	int num1;
	int sum1 = 0;
	if (length1 == 1)
		return 1;
	else
	{
		for (num1 = first_char + 1; num1 <= 26; num1++)
		{
			sum1 += cal_length1(num1, length1-1);
		}		
	}
	return sum1;
}
int calshorterthanlength(int length1)//计算长度小于等于length1字符串个数
{
	int sum1 = 0;
	int count1 = 1;
	if (length1 == 1)
		return 26;
	else
	{
		for (; count1 <= length1; count1++)
		{
			for (int count2 = 1; count2 <= 26; count2++)
			{
				sum1 += cal_length1(count2, count1);
			}
		}
		return sum1;
	}	
}
int calsmallinfirstletter(char a,char b,int length1)//计算长度相同，首字母比a小,比b大的字符串个数
{
	char count1 = b+1;
	int sum1 = 0;
	for (; count1 < a; count1++)
	{
		sum1 += cal_length1(count1-'a'+1, length1);
	}
	return sum1;
}
void sequential_cal()
{
	int sum1 = 0;
	int count1 = 0;
	char test[string_max_length+1];
	cin >> test;
	int length1 = strlen(test);
	if (length1 == 1)
		sum1+=(test[0] - 'a');
	else
	{
		sum1+= calshorterthanlength(length1 - 1);
		sum1 += calsmallinfirstletter(test[count1], 'a' - 1, length1);
		length1--;
		count1++;
		while (test[count1] != 0)
		{
			sum1 += calsmallinfirstletter(test[count1],test[count1-1], length1);
			length1--;
			count1++;
		}
	}
	sum1++;
	cout << sum1 << endl;
	return;
}

int main()
{
	int number1;
	int count1 = 0;
	cin >> number1;
	while (count1 < number1)
	{
		sequential_cal();
		count1++;
	}
	return 0;
}