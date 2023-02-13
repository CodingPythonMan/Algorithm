#pragma once

class QuickSort
{
public:
	QuickSort() = default;
	~QuickSort();

public:
	void Sort(vector<int>& arr);
	void Quick(vector<int>& arr, int a, int b);
};
