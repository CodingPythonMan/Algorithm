#include "pch.h"
#include <cstdlib>
#include <ctime>
//#include <algorithm>

void Print(const vector<int>& arr)
{
	for (int i : arr)
	{
		cout << i << ", ";
	}
}

int main()
{
	// ���� �ʿ� cin
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);

	vector<int> arr = { 13, 40, 2, 100, 10 };

	RadixSort radix;
	radix.Sort(arr);
	Print(arr);
}