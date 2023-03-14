#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct vertex {
	int index;
	int weight;
};

vector<vector<vertex>> linkList;
vector<bool> visit;
vector<int> distances;

void init(int start, int n)
{
	for (int i = 1; i < n + 1; i++)
		distances[i] = INT_MAX;

	for (int i = 1; i < n + 1; i++)
		visit[i] = false;

	visit[start] = true;
	distances[start] = 0;
}

void dijkstra(const vertex& ver)
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

int explorer(int param1, int param2, int n)
{
	int result = 0;

	init(1, n);
	dijkstra({ 1,0 });
	result += distances[param1];
	init(param1, n);
	dijkstra({ param1, 0 });
	result += distances[param2];
	init(param2, n);
	dijkstra({ param2, 0 });
	result += distances[n];

	return result;
}

int main()
{
	int n, e, param1, param2;
	n = 5;
	e = 7;
	param1 = 3;
	param2 = 2;

	linkList.resize(n + 1);
	visit.resize(n + 1);
	distances.resize(n + 1);

	linkList[1].push_back({ 2,3 });
	linkList[2].push_back({ 1,3 });

	linkList[2].push_back({ 3,3 });
	linkList[3].push_back({ 2,3 });

	linkList[3].push_back({ 4,3 });
	linkList[4].push_back({ 3,3 });

	linkList[4].push_back({ 5,3 });
	linkList[5].push_back({ 4,3 });

	linkList[1].push_back({ 4,4 });
	linkList[4].push_back({ 1,4 });

	linkList[2].push_back({ 4,2 });
	linkList[4].push_back({ 2,2 });

	linkList[1].push_back({ 3,2 });
	linkList[3].push_back({ 1,2 });

	int result = explorer(param1, param2, n);
	int result2 = explorer(param2, param1, n);

	result = result < result2 ? result : result2;

	if (visit[n] == true)
		cout << result;
	else
		cout << -1;
}