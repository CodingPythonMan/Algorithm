#pragma once
class UnionFind
{
public:
	void Print();

	int GetParent(vector<int>& parent, int x));
	int UnionParent(vector<int>& parent, int a, int b);
};

