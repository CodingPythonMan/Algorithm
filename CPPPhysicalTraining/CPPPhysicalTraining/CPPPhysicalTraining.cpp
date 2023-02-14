#include "pch.h"
#include <cstdlib>
#include <ctime>

void Print(const vector<int>& arr)
{
	for (int i : arr)
	{
		cout << i << ", ";
	}
}

int main()
{
	int n, a = 0;
    vector<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		//cin >> a;
		//arr.push_back(a);
		arr.push_back(rand());
	}

	//for (int i = 0; i < 1000000; i++)
		//arr.push_back(rand());

	//Print(arr);
	//cout << endl;

	MergeSort mergeSort;
    mergeSort.Sort(arr);
	
	//QuickSort quickSort;
	//quickSort.Sort(arr);

    Print(arr);
}