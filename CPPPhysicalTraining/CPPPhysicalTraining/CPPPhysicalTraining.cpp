#include "pch.h"

void Print(vector<int> arr)
{
	for (int i : arr)
	{
		std::cout << i << ", ";
	}
}

int main()
{
    vector<int> arr = {3,6,1,2,5,4};

	MergeSort mergeSort;
    mergeSort.Sort(arr);

    Print(arr);
}