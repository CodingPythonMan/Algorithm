#pragma once

class MergeSort
{
private:
	vector<int> _arr;
	
public:
	MergeSort() = default;
	~MergeSort();

public:
	void Sort(vector<int>& arr);
	void Divide(int left, int right);
	void Merge(int left, int mid, int right);
	void Swap(int x, int y);
};