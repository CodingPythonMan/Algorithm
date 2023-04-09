#include "pch.h"
#include "UnionFind.h"

int UnionFind::GetParent(vector<int>& parent, int x)
{
	if (parent[x] == x) 
		return x;
	return parent[x] = GetParent(parent, parent[x]);
}

void UnionFind::UnionParent(vector<int>& parent, int a, int b)
{
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a > b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool UnionFind::FindParent(vector<int>& parent, int a, int b)
{
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a == b) return true;
	return false;
}

bool UnionFind::validPath(int n, vector<vector<int>>& edges, int source, int destination)
{
	vector<int> parent;
	for (int i = 0; i < n; i++)
		parent.push_back(i);

	for (vector<int>& edge : edges)
	{
		UnionParent(parent, edge[0], edge[1]);
	}

	return FindParent(parent, source, destination);
}