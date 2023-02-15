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
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);

	int n, a = 0;
    vector<int> arr;

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	MergeSort mergeSort;
    mergeSort.Sort(arr);
	
	//QuickSort quickSort;
	//quickSort.Sort(arr);

	//sort(arr.begin(), arr.end());

    Print(arr);
}