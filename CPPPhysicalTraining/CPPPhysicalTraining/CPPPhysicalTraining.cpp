#include "CorePch.h"
//#include "TakeGroup.h"
#include "UnionFInd.h"

int main()
{
	/*
	vector<vector<int>> graph;
	graph.push_back({ 1,2,2 });
	graph.push_back({ 2,4,100 });
	graph.push_back({ 1,3,100 });
	graph.push_back({ 3,4,1 });

	DelayNetwork d;
	d.networkDelayTime(graph, 4, 1);*/

	//TakeGroup t;
	//t.Print();
	int n = 6;
	vector<vector<int>> edges;
	edges.push_back({ 0,1 });
	edges.push_back({ 0,2 });
	edges.push_back({ 3,5 });
	edges.push_back({ 5,4 });
	edges.push_back({ 4,3 });
	int source = 0;
	int destination = 5;

	UnionFind u;
	cout << u.validPath(n, edges, source, destination);
}