#pragma once
class UnionFind
{
public:
	int GetParent(vector<int>& parent, int x);
	void UnionParent(vector<int>& parent, int a, int b);
	bool FindParent(vector<int>& parent, int a, int b);

	bool validPath(int n, vector<vector<int>>& edges, int source, int destination);
};

