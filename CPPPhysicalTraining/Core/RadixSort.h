#pragma once
class RadixSort
{

public:
	// num �� ���� ��, digit �� ���� �ڸ���, base �� ���������� 10����
	int GetDigit(int num, int digit);

	void CountSortWithDigit(vector<int>& arr, int digit);

	void Sort(vector<int>& arr);

};