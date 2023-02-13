#include "pch.h"
#include "QuickSort.h"

QuickSort::~QuickSort()
{
}

void QuickSort::Sort(vector<int>& arr)
{
	if (arr.size() <= 1)
		return;
	Quick(arr, 0, static_cast<int>(arr.size() - 1));
}

void QuickSort::Quick(vector<int>& arr, int a, int b)
{
	if (a >= b)
		return;

	int pivot = arr[b];
	int left = a;
	int right = b-1;

	while (left <= right)
	{
		while (left <= right && arr[left] <= pivot)
			left++;
		while (right >= left && pivot <= arr[right]) 
			right--;

		if (left < right)
			swap(arr[left], arr[right]);
	}

	swap(arr[left], arr[b]);
	Quick(arr, a, left - 1);
	Quick(arr, left+1, b);
}