#include "CorePch.h"
#include "TakeGroup.h"

int main()
{
	vector<vector<int>> graph;
	graph.push_back({ 1,2,2 });
	graph.push_back({ 2,4,100 });
	graph.push_back({ 1,3,100 });
	graph.push_back({ 3,4,1 });

	DelayNetwork d;
	d.networkDelayTime(graph, 4, 1);

	/*
	TakeGroup t;
	t.solution(4, {"Friend","Friend","Total"}, {1,2,1}, {2,3,4});*/
}