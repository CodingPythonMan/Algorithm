#include "pch.h"
#include "RadixSort.h"

int RadixSort::GetDigit(int num, int digit)
{
	// ex) 10�����̸� 10���� num�� ������ �ڸ����� ���Ѵ�.
	return (num / static_cast<int>(pow(10, digit))) % 10;
}

void RadixSort::CountSortWithDigit(vector<int>& arr, int digit)
{
	vector<int> arr2;
	for (int i = 0; i < arr.size(); i++)
	{
		arr2.push_back(-1);
	}

	vector<int> arr3;
	arr3.resize(10);

	// �� ���ڿ��� �ڸ����� ��� �������� ���
	for (int i : arr)
	{
		arr3[GetDigit(i, digit)] += 1;
	}

	// ���� ��
	for (int i = 0; i < 9; i++)
	{
		arr3[i + 1] += arr3[i];
	}

	// ���� �ڸ����� �������� ����
	for (int i = static_cast<int>(arr.size()) - 1; i > -1; i--)
	{
		arr2[arr3[GetDigit(arr[i], digit)]-1] = arr[i];
		arr3[GetDigit(arr[i], digit)] -= 1;
	}

	arr = arr2;
}

void RadixSort::Sort(vector<int>& arr)
{
	int max = 0;
	for (int i : arr)
	{
		if (max < i)
		{
			max = i;
		}
	}

	int digit = static_cast<int>(log10(max) + 1);

	for (int i = 1; i <= digit; i++)
	{
		CountSortWithDigit(arr, i);
	}
}