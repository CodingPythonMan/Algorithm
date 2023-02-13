#include "pch.h"
#include <cstdlib>
#include <ctime>

void Print(vector<int> arr)
{
	for (int i : arr)
	{
		std::cout << i << ", ";
	}
}

int main()
{
    vector<int> arr;

	for (int i = 0; i < 1000; i++)
		arr.push_back(rand());

	MergeSort mergeSort;
    mergeSort.Sort(arr);

    Print(arr);
}