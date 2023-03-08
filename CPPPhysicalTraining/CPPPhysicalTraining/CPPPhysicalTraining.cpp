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
	// 백준 필요 cin
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);

	vector<int> arr = { 13, 40, 2, 100, 10 };

	RadixSort radix;
	radix.Sort(arr);
	Print(arr);

	int min = 0;
	if (arr.size() > 0)
	{
		min = arr[1] - arr[0];
		for (int i = 2; i < arr.size(); i++)
		{
			int diff = arr[i] - arr[i - 1];
			if (min > diff)
			{
				min = diff;
			}
		}
	}
	else
	{
		min = 0;
	}
	cout << "최소 : " << min << endl;
}