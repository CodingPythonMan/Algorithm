#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> distances;

void dijkstra(int start, int n)
{
	for (int i = 1; i < n + 1; i++)
		distances[i] = INT_MAX;

	distances[start] = 0;

	auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
		return (p1.second > p2.second);
	};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
	pq.push({ start, 0 });

	while (pq.size() != 0)
	{
		pair<int, int> node = pq.top();
		pq.pop();

		if (node.second > distances[node.first]) 
			continue;

		for (auto& next : graph[node.first])
		{
			if (distances[next.first] > node.second + next.second) 
			{
				distances[next.first] = node.second + next.second;
				pq.push({ next.first, distances[next.first] });
			}
		}
	}
}

int explorer(int param1, int param2, int n)
{
	int result = 0;

	dijkstra(1, n);
	if (distances[param1] == INT_MAX)
		return INT_MAX;
	result += distances[param1];

	dijkstra(param1, n);
	if (distances[param2] == INT_MAX)
		return INT_MAX;
	result += distances[param2];

	dijkstra(param2, n);
	if (distances[n] == INT_MAX)
		return INT_MAX;
	result += distances[n];

	return result;
}

int main()
{
	int n, e, param1, param2;
	cin >> n >> e;

	graph.resize(n + 1);
	distances.resize(n + 1);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> param1 >> param2;

	int result = explorer(param1, param2, n);
	int result2 = explorer(param2, param1, n);

	result = result < result2 ? result : result2;

	if (result != INT_MAX)
		cout << result;
	else
		cout << -1;
}