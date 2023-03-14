#include <vector>
#include <climits>
#include <iostream>
#include "SpecificDijkstra.h"
using namespace std;

void SpecificDijkstra::main()
{
	int n, e, param1, param2;
	n = 4;
	e = 6;
	param1 = 2;
	param2 = 3;

	linkList.resize(n + 1);
	visit.resize(n + 1);
	distances.resize(n + 1);

	linkList[1].push_back({ 2,3 });
	linkList[2].push_back({ 1,3 });
	linkList[2].push_back({ 3,3 });
	linkList[3].push_back({ 2,3 });
	linkList[3].push_back({ 4,1 });
	linkList[4].push_back({ 3,1 });
	linkList[1].push_back({ 3,5 });
	linkList[3].push_back({ 1,5 });
	linkList[2].push_back({ 4,5 });
	linkList[4].push_back({ 2,5 });
	linkList[1].push_back({ 4,4 });
	linkList[4].push_back({ 1,4 });

	int result = explorer(param1, param2, n);
	int result2 = explorer(param2, param1, n);

	if (visit[n] == true)
	{
		if (result < result2)
			cout << result;
		else
			cout << result2;
	}
	else
		cout << -1;
}


void SpecificDijkstra::init(int n)
{
	for (int i = 1; i < n + 1; i++)
		distances[i] = INT_MAX;

	for (int i = 1; i < n + 1; i++)
		visit[i] = false;
}

void SpecificDijkstra::dijkstra(const vertex& ver)
{
	const vector<vertex>& links = linkList[ver.index];

	auto cmp = [](const vertex& v1, const vertex& v2) {
		return (v1.weight > v2.weight);
	};

	priority_queue < vertex, vector<vertex>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < links.size(); i++)
	{
		const vertex& v = links[i];
		if (visit[v.index] == true)
			continue;

		if (distances[v.index] > v.weight + ver.weight)
			distances[v.index] = v.weight + ver.weight;

		if (linkList[v.index].empty() == false)
			pq.push({ v.index, distances[v.index] });
	}

	if (pq.size() != 0)
	{
		const vertex& v = pq.top();
		visit[v.index] = true;
		dijkstra(v);
	}
}

int SpecificDijkstra::explorer(int param1, int param2, int n)
{
	int result = 0;

	init(n);
	visit[1] = true;
	distances[1] = 0;
	dijkstra({ 1,0 });
	result += distances[param1];
	init(n);
	dijkstra({ param1, 0 });
	result += distances[param2];
	init(n);
	dijkstra({ param2, 0 });
	result += distances[n];
	
	return result;
}