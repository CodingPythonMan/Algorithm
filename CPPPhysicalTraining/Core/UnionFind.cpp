#include "pch.h"
#include "UnionFind.h"

void UnionFind::Print()
{
	cout << "AHh";
}

int UnionFind::GetParent(vector<int>& parent, int x)
{
	if (parent[x] == x) 
		return x;
	return parent[x] = GetParent(parent, parent[x]);
}
