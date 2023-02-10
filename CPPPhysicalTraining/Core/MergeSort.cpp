#include "pch.h"
#include "MergeSort.h"

MergeSort::~MergeSort()
{
}

void MergeSort::Sort(vector<int>& arr)
{
	_arr = arr;

	int left = 0;
	int right = static_cast<int>(_arr.size());

	Divide(left, right);
}

void MergeSort::Merge(int left, int mid, int right)
{

}

void MergeSort::Divide(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		Divide(left, mid);
		Divide(mid, right);
		Merge(left, mid, right);
	}
}

void MergeSort::Swap(int x, int y)
{
	int temp = _arr[x];
	_arr[x] = _arr[y];
	_arr[y] = temp;
}