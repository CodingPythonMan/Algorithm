#pragma once
class RadixSort
{

public:
	// num 은 실제 수, digit 은 현재 자릿수, base 는 진법이지만 10진법
	int GetDigit(int num, int digit);

	void CountSortWithDigit(vector<int>& arr, int digit);

	void Sort(vector<int>& arr);

};