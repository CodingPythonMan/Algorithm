#pragma once

class MergeSort
{	
public:
	MergeSort() = default;
	~MergeSort();

public:
	void Sort(vector<int>& arr);
	void Merge(vector<int>& v1, vector<int>& v2, vector<int>& arr);
};