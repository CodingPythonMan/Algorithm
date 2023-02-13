#include "pch.h"
#include "MergeSort.h"

MergeSort::~MergeSort()
{
}

void MergeSort::Sort(vector<int>& arr)
{
	int n = static_cast<int>(arr.size());
	if (n <= 1)
		return;

	vector<int> v1, v2;
	auto p = arr.begin();

	for (int i = 0; i < n / 2; i++)
		v1.push_back(*p++);
	for (int i = n / 2; i < n; i++)
		v2.push_back(*p++);
	arr.clear();
	Sort(v1);
	Sort(v2);
	Merge(v1, v2, arr);
}

void MergeSort::Merge(vector<int>& v1, vector<int>& v2, vector<int>& arr)
{
	auto p1 = v1.begin();
	auto p2 = v2.begin();
	while (p1 != v1.end() && p2 != v2.end())
	{
		if (*p1 < *p2)
			arr.push_back(*p1++);
		else
			arr.push_back(*p2++);
	}
	while (p1 != v1.end())
		arr.push_back(*p1++);
	while (p2 != v2.end())
		arr.push_back(*p2++);
}